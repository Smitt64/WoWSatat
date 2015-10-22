#include "stringlistdlg.h"
#include "ui_stringlistdlg.h"
#include <ppl.h>
#include <QTextCodec>
#include <QByteArray>

StringListDlg::StringListDlg(const quint8 *stringstart, const quint32 &stringssize, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StringListDlg)
{
    ui->setupUi(this);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    //strings = new QStringListModel(codec->toUnicode(QString::fromLocal8Bit((char*)stringstart, stringssize)).split(QChar('\0')), this);
    ui->listView->setModel(strings);
}

StringListDlg::~StringListDlg()
{
    delete ui;
}
