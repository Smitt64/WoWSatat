#include "db2filtersortmodel.h"
#include "db2tablemodel.h"
#include <QRegExp>
#include <QDebug>
#include <QScriptEngine>

DB2FilterSortModel::DB2FilterSortModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    m_fFilterByValue = false;
    fun = NULL;
}

bool DB2FilterSortModel::lessThan(const QModelIndex &left,
                                      const QModelIndex &right) const
{
    QVariant leftData = sourceModel()->data(left);
    QVariant rightData = sourceModel()->data(right);

    if (leftData.type() == QVariant::Int)
    {
        return leftData.toInt() < rightData.toInt();
    }

    if (leftData.type() == QVariant::Double)
    {
        return leftData.toDouble() < rightData.toDouble();
    }
}

bool DB2FilterSortModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (!m_Script.isEmpty())
    {
        DB2TableModel *m = ((DB2TableModel*)sourceModel());

        QScriptValueList args;
        foreach (BoundValues v, m_BoundValues)
        {
            switch(v.type)
            {
            case FLD_INT:
            case FLD_KEY:
                args << m->getIntItem(sourceRow, v.field);
                break;
            case FLD_FLOAT:
                args << m->getFloatItem(sourceRow, v.field);
                break;
            case FLD_STRING:
                args << m->getStringItem(sourceRow, v.field);
                break;
            }

        }
        QScriptValue result = fun->call(QScriptValue(), args);
        return result.toBool();
    }
    return true;
}

void DB2FilterSortModel::filterByColumnValue(const quint16 &column, const QVariant &value)
{
    m_vFilterByValueColumn = column;
    m_vFilterByValue = value;
    m_fFilterByValue = true;
}

void DB2FilterSortModel::setFilterString(const QString &_str)
{
    m_BoundValues.clear();

    QRegExp rx("(\\[\\s*(\\w*)\\s*\\:\\s*(\\d*)\\s*\\])");
    QString str = _str;
    m_Script = str;

    DB2TableModel *m = (DB2TableModel*)sourceModel();
    fmt = m->formaStr();

    engine = m->script();

    int pos = 0;
    while ((pos = rx.indexIn(str, pos)) != -1)
    {
        qDebug()<< rx.cap(1) << rx.cap(2) << rx.cap(3);

        BoundValues v;
        v.name = QString("%1%2")
                .arg(rx.cap(2))
                .arg(rx.cap(3));
        v.field = rx.cap(3).toInt() - 1;
        v.type = fmt[v.field].toLatin1();

        m_Script = m_Script.replace(rx.cap(1), v.name);

        m_BoundValues.append(v);

        pos += rx.matchedLength();
    }

    QString tmp = "(function(";
    for (int i = 0; i < m_BoundValues.size(); i++) {
        tmp += m_BoundValues[i].name;
        if (i != m_BoundValues.size() - 1)
        {
            tmp += ",";
        }
    }

    tmp += ") { return " + m_Script + "; })";
    m_Script = tmp;
    qDebug() << m_Script;

    if (fun)
    {
        delete fun;
    }
    fun = new QScriptValue(engine->evaluate(m_Script));
}
