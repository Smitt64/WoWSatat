#include "filterdlg.h"
#include "ui_filterdlg.h"

// (\[\s*(\w*)\s*\:\s*(\d*)\s*\])
FilterDlg::FilterDlg(const QStringList &fields, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDlg)
{
    ui->setupUi(this);
    model.setStringList(fields);
    ui->listView->setModel(&model);

    connect(ui->listView, SIGNAL(doubleClicked(QModelIndex)), SLOT(fldDoubleClicked(QModelIndex)));
}

FilterDlg::~FilterDlg()
{
    delete ui;
}

void FilterDlg::fldDoubleClicked(const QModelIndex &index)
{
    ui->plainTextEdit->insertPlainText(QString("[%1]").arg(index.data().toString()));
}

QString FilterDlg::getFilterString()
{
    return ui->plainTextEdit->toPlainText();
}
