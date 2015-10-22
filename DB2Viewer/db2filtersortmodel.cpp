#include "db2filtersortmodel.h"

DB2FilterSortModel::DB2FilterSortModel()
{

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
    /*if (leftData.type() == QVariant::DateTime) {
        return leftData.toDateTime() < rightData.toDateTime();
    } else {
        static QRegExp emailPattern("[\\w\\.]*@[\\w\\.]*)");

        QString leftString = leftData.toString();
        if(left.column() == 1 && emailPattern.indexIn(leftString) != -1)
            leftString = emailPattern.cap(1);

        QString rightString = rightData.toString();
        if(right.column() == 1 && emailPattern.indexIn(rightString) != -1)
            rightString = emailPattern.cap(1);

        return QString::localeAwareCompare(leftString, rightString) < 0;
    }*/
}

bool DB2FilterSortModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    return true;
}
