#ifndef DB2TABLEMODEL_H
#define DB2TABLEMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QStandardItemModel>

typedef struct
{
  quint32 magic; // always 'WDBC'
  quint32 record_count; // records per file
  quint32 field_count; // fields per record
  quint32 record_size; // sum (sizeof (field_type_i)) | 0 <= i < field_count. field_type_i is NOT defined in the files.
  quint32 string_table_size;
}DBCHeader;

typedef struct
{
    DBCHeader hdr;

    quint32 table_hash;
    quint32 build;
    quint32 timestamp_last_written;                              // set to time(0); when writing in WowClientDB2_Base::Save()
    quint32 min_id;
    quint32 max_id;
    quint32 locale;                                              // as seen in TextWowEnum
    quint32 unk2;
} DB2Header;

enum FldType
{
    FLD_INT = 'i',
    FLD_KEY = 'n',
    FLD_FLOAT = 'f',
    FLD_STRING = 's'
};

typedef struct
{
    FldType type;
    quint16 offset;
    QString title;
} RecordFld;

class QFile;
class SelDefenitionDlg;
class DB2TableModel : public QAbstractTableModel
{
    Q_OBJECT
    friend class DB2Window;
    friend class DB2TableModel;
public:
    DB2TableModel(QObject *parent = 0);

    bool load(const QString &filename);

    int	columnCount(const QModelIndex &parent = QModelIndex()) const;
    int	rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void clearDbInfo();

    void setTypeToFloat(const quint16 &fldNum);
    void setTypeToString(const quint16 &fldNum);
    void setTypeToInt(const quint16 &fldNum);
    void setType(const quint16 &fldNum, const QString &Name);
    QString getStringFld(const quint32 &offset) const;

    QString makeFormat();
private:
    void loadDB2(DB2Header *header, QFile *f);
    void loadDBC(DBCHeader *header, QFile *f);
    void fillOffsets();

    SelDefenitionDlg *defDlg;

    quint32 fieldCount;
    quint32 recordCount;
    quint32 recordSize;
    quint32 stringTableSize;
    quint32 dbbuild;

    quint64 dataLen;

    QString format;

    QVector<RecordFld> fieldsOffsets;

    quint8 *dataTable;
    quint32 *indices;
    quint16 *string_lengths;
    quint8 *string_block;
};

#endif // DB2TABLEMODEL_H
