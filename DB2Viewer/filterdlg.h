#ifndef FILTERDLG_H
#define FILTERDLG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class FilterDlg;
}

class DB2FilterSortModel;
class FilterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDlg(const QStringList &fields, QWidget *parent = 0);
    ~FilterDlg();

    QString getFilterString();

private slots:
    void fldDoubleClicked(const QModelIndex &index);

private:
    Ui::FilterDlg *ui;
    QStringListModel model;
};

#endif // FILTERDLG_H
