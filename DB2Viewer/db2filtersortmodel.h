#ifndef DB2FILTERSORTMODEL_H
#define DB2FILTERSORTMODEL_H

#include <QSortFilterProxyModel>
#include <QScriptEngine>

class DB2FilterSortModel : public QSortFilterProxyModel
{
    Q_OBJECT
    typedef struct
    {
        QString name;
        int field;
        char type;
    }BoundValues;
public:
    DB2FilterSortModel(QObject *parent = 0);

    void filterByColumnValue(const quint16 &column, const QVariant &value);
    void filterByColumnValueDisable() { m_fFilterByValue = false; }

    void setFilterString(const QString &str);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;

public slots:

private:
    bool m_fFilterByValue;
    QVariant m_vFilterByValue;
    int m_vFilterByValueColumn;

    QString fmt;
    QScriptEngine *engine;
    QScriptValue *fun;

    QString m_filter, m_Script;
    bool m_fUseFilter;
    QList<BoundValues> m_BoundValues;
};

#endif // DB2FILTERSORTMODEL_H
