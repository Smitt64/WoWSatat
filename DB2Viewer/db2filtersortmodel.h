#ifndef DB2FILTERSORTMODEL_H
#define DB2FILTERSORTMODEL_H

#include <QSortFilterProxyModel>

class DB2FilterSortModel : public QSortFilterProxyModel
{
public:
    DB2FilterSortModel();

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const Q_DECL_OVERRIDE;
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const Q_DECL_OVERRIDE;

public slots:
};

#endif // DB2FILTERSORTMODEL_H
