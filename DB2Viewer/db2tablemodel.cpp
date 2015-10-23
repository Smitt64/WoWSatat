#include "db2tablemodel.h"
#include <QFile>
#include <QColor>
#include <QDebug>
#include <QTextCodec>
#include "seldefenitiondlg.h"

DB2TableModel::DB2TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    dataTable = 0;
    indices = NULL;
    string_lengths = NULL;
    string_block = NULL;
    dbbuild = 0;

    defDlg = new SelDefenitionDlg();
}

void DB2TableModel::clearDbInfo()
{
    if (dataTable)
    {
        delete dataTable;
        dataTable = NULL;
    }

    if (indices)
    {
        delete indices;
        indices = NULL;
    }

    if (string_lengths)
    {
        delete string_lengths;
        string_lengths = NULL;
    }

    if (string_block)
    {
        delete string_block;
        string_block = NULL;
    }

    fieldCount = 0;
    recordCount = 0;
    recordSize = 0;
    stringTableSize = 0;
    dataLen = 0;
    dataTable = 0;
    format = "";
    fieldsOffsets.clear();
}

bool DB2TableModel::load(const QString &filename)
{
    bool ret = true;
    QFile f(filename);

    if (!f.open(QIODevice::ReadOnly))
        return false;

    char magic[5] = {0};
    f.read(magic, 4);

    if (QString(magic) == "WDB2")
    {
        clearDbInfo();

        DB2Header hdr;
        memset(&hdr, 0, sizeof(DB2Header));

        f.seek(0);
        f.read((char*)&hdr, sizeof(DB2Header));

        loadDB2(&hdr, &f);
    }
    else if (QString(magic) == "WDBC")
    {
        clearDbInfo();
        DBCHeader hdr;
        memset(&hdr, 0, sizeof(DBCHeader));

        f.seek(0);
        f.read((char*)&hdr, sizeof(DBCHeader));

        loadDBC(&hdr, &f);
    }
    else
    {
        return false;
    }

    defDlg->fillDefenition(filename, dbbuild);
    if (defDlg->exec() == QDialog::Accepted)
    {
        QAbstractTableModel::beginResetModel();
        QStandardItemModel *st = defDlg->defenition();
        for (int i = 0; i < st->rowCount(); i++)
        {
            if (i < fieldCount)
            {
                fieldsOffsets[i].title = st->data(st->index(i, 0)).toString();
                fieldsOffsets[i].type = (FldType)FindTypeForName(st->data(st->index(i, 1)).toString());
            }
        }
        QAbstractTableModel::endResetModel();
    }

    return ret;
}

int	DB2TableModel::columnCount(const QModelIndex &parent) const
{
    return fieldCount;
}

int	DB2TableModel::rowCount(const QModelIndex & parent) const
{
    return recordCount;
}

QString DB2TableModel::makeFormat()
{
    QString st;
    for (int i = 0; i < fieldsOffsets.size(); i++)
    {
        st += (char)fieldsOffsets[i].type;
    }

    return st;
}

void DB2TableModel::setTypeToFloat(const quint16 &fldNum)
{
    QAbstractTableModel::beginResetModel();
    fieldsOffsets[fldNum].type = FLD_FLOAT;
    QAbstractTableModel::endResetModel();
}

void DB2TableModel::setTypeToString(const quint16 &fldNum)
{
    QAbstractTableModel::beginResetModel();
    fieldsOffsets[fldNum].type = FLD_STRING;
    QAbstractTableModel::endResetModel();
}

void DB2TableModel::setTypeToInt(const quint16 &fldNum)
{
    QAbstractTableModel::beginResetModel();
    fieldsOffsets[fldNum].type = FLD_INT;
    QAbstractTableModel::endResetModel();
}

QString DB2TableModel::getStringFld(const quint32 &offset) const
{
    if (string_block + offset < string_block + stringTableSize)
    {
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        return codec->toUnicode((char*)string_block + (offset));
    }

    return QString("");
}

int DB2TableModel::getIntItem(const quint32 &row, const quint32 &col)
{
    //char *ptr = ((char*)dataTable) + row * recordSize + fieldsOffsets[col].offset;
    return *reinterpret_cast<int*>((char*)(dataTable + row * recordSize + fieldsOffsets[col].offset));
}

float DB2TableModel::getFloatItem(const quint32 &row, const quint32 &col)
{
    return *reinterpret_cast<float*>((char*)(dataTable + row * recordSize + fieldsOffsets[col].offset));
}

QString DB2TableModel::getStringItem(const quint32 &row, const quint32 &col)
{
    int stroffset = *reinterpret_cast<int*>((char*)(dataTable + row * recordSize + fieldsOffsets[col].offset));

    if (string_block + stroffset < string_block + stringTableSize)
    {
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        return codec->toUnicode((char*)string_block + (stroffset));
    }

    return QString("");
}

void DB2TableModel::setType(const quint16 &fldNum, const QString &Name)
{
    QAbstractTableModel::beginResetModel();
    for (int i = 0; i < ITEMSCOUNT; i++)
    {
        if (ItemTypes[i].name == Name)
        {
            fieldsOffsets[fldNum].type = (FldType)ItemTypes[i].type;
            break;
        }
    }

    QAbstractTableModel::endResetModel();
}

QVariant DB2TableModel::data(const QModelIndex &index, int role) const
{
    QVariant ret;
    if (role == Qt::DisplayRole)
    {
        RecordFld rec = fieldsOffsets[index.column()];
        char *ptr = ((char*)dataTable) + index.row() * recordSize + rec.offset;

        switch(rec.type)
        {
        case FLD_INT:
        case FLD_KEY:
            ret = QVariant::fromValue(*reinterpret_cast<int*>(ptr));
            break;
        case FLD_FLOAT:
            ret = QVariant::fromValue(*reinterpret_cast<float*>(ptr));
            break;
        case FLD_STRING:
            ret = getStringFld((quint32)(*reinterpret_cast<int*>(ptr)));
            break;
        }
    }
    else if (role == Qt::BackgroundColorRole)
    {
        if (fieldsOffsets[index.column()].type == FLD_KEY)
            ret = QVariant::fromValue(QColor(Qt::gray));
    }
    else if (role == Qt::ToolTipRole)
    {
        RecordFld rec = fieldsOffsets[index.column()];
        char *ptr = ((char*)dataTable) + index.row() * recordSize + rec.offset;
        QString tooltip;
        tooltip += QString("Integer: %1").arg(*reinterpret_cast<int*>(ptr));
        tooltip += QString("\nFloat: %1").arg(*reinterpret_cast<float*>(ptr));
        tooltip += QString("\nDouble: %1").arg(*reinterpret_cast<double*>(ptr));

        tooltip += QString("\nString: %1").arg(getStringFld((quint32)(*reinterpret_cast<int*>(ptr))));
        ret = QVariant::fromValue(tooltip);
    }
    return ret;
}

void DB2TableModel::loadDB2(DB2Header *header, QFile *f)
{
    fieldCount = header->hdr.field_count;
    recordCount = header->hdr.record_count;
    recordSize = header->hdr.record_size;
    stringTableSize = header->hdr.string_table_size;
    dataLen = recordCount * recordSize;
    dbbuild = header->build;

    QAbstractTableModel::beginResetModel();

    if (header->max_id > 0)
    {
        indices = new quint32[header->max_id - header->min_id + 1];
        f->read((char*)indices, (header->max_id - header->min_id + 1) * sizeof(quint32));

        string_lengths = new quint16[header->max_id - header->min_id + 1];
        f->read((char*)string_lengths, (header->max_id - header->min_id + 1) * sizeof(quint16));
    }

    dataTable = new quint8[dataLen];
    f->read((char*)dataTable, dataLen);

    string_block = new quint8[header->hdr.string_table_size];
    f->read((char*)string_block, header->hdr.string_table_size);

    for (int i = 0; i < fieldCount; i++)
    {
        format += (i == 0 ? "n" : "i");
    }
    fillOffsets();
    QAbstractTableModel::endResetModel();
}

void DB2TableModel::loadDBC(DBCHeader *header, QFile *f)
{
    fieldCount = header->field_count;
    recordCount = header->record_count;
    recordSize = header->record_size;
    stringTableSize = header->string_table_size;
    dataLen = recordCount * recordSize;

    QAbstractTableModel::beginResetModel();
    dataTable = new quint8[dataLen];
    f->read((char*)dataTable, dataLen);

    string_block = new quint8[header->string_table_size];
    f->read((char*)string_block, header->string_table_size);

    for (int i = 0; i < fieldCount; i++)
    {
        format += (i == 0 ? "n" : "i");
    }
    fillOffsets();
    QAbstractTableModel::endResetModel();
}

void DB2TableModel::fillOffsets()
{
    quint16 offset = 0;
    for (int i = 0; i < fieldCount; i++)
    {
        RecordFld rec;
        rec.type = (FldType)format[i].toLatin1();
        rec.offset = offset;

        switch(format[i].toLatin1())
        {
        case FLD_INT:
            rec.title = "integer";
            offset += sizeof(int);
            break;
        case FLD_KEY:
            rec.title = "key";
            offset += sizeof(int);
            break;
        case FLD_FLOAT:
            rec.title = "float";
            offset += sizeof(float);
            break;
        case FLD_STRING:
            rec.title = "string";
            offset += sizeof(char*);
            break;
        }

        fieldsOffsets.append(rec);
        setHeaderData(i, Qt::Horizontal, rec.title, Qt::DisplayRole);
    }
    emit headerDataChanged(Qt::Horizontal, 1, fieldsOffsets.size());
}

QVariant DB2TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        QString type;

        if (section > fieldsOffsets.size())
            return QAbstractTableModel::headerData(section, orientation, role);

        for (int i = 0; i < ITEMSCOUNT; i++)
        {
            if (ItemTypes[i].type == (char)fieldsOffsets[section].type)
            {
                type = ItemTypes[i].name;
            }
        }
        return QString("%1\n%2(%3)").arg(fieldsOffsets[section].title)
                .arg(type).arg(section + 1);
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}
