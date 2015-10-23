#include "seldefenitiondlg.h"
#include "ui_seldefenitiondlg.h"
#include <QXmlQuery>
#include <QDomDocument>
#include <QFileInfo>
#include <QCoreApplication>
#include <QStringListModel>
#include "comboboxdelegate.h"

DefItem ItemTypes[ITEMSCOUNT] =
{
    {"int", 'i', sizeof(int)},
    {"key", 'n', sizeof(int)},
    {"float", 'f', sizeof(float)},
    {"string", 's', sizeof(char*)},
    {"double", 'd', sizeof(double)}
};

char FindTypeForName(const QString &name)
{
    for (int i = 0; i < ITEMSCOUNT; i++)
    {
        if (ItemTypes[i].name == name)
        {
            return ItemTypes[i].type;
        }
    }

    return 'i';
}

SelDefenitionDlg::SelDefenitionDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelDefenitionDlg)
{
    ui->setupUi(this);
    model = new QStringListModel();
    ui->listView->setModel(model);
    defModel = new QStandardItemModel(this);
    ui->tableView->setModel(defModel);
    defModel->setColumnCount(2);

    QStringList lst;

    for (int i = 0; i < ITEMSCOUNT; i++)
    {
        lst << ItemTypes[i].name;
    }
    delegate = new ComboBoxDelegate(lst, this);
    ui->tableView->setItemDelegateForColumn(1, delegate);

    connect(ui->listView, SIGNAL(clicked(QModelIndex)), SLOT(buildClicked(QModelIndex)));
}

SelDefenitionDlg::~SelDefenitionDlg()
{
    delete ui;
}

void SelDefenitionDlg::setFileBuild(quint32 build)
{
    ui->label->setText(tr("File build: %1").arg(build));
}

void SelDefenitionDlg::buildClicked(const QModelIndex &index)
{
    QString dbclayout = QFileInfo(QCoreApplication::applicationFilePath()).absolutePath() + "/dbclayout.xml";

    QXmlQuery query;

    QFile f(dbclayout);
    if (f.open(QIODevice::ReadOnly))
    {
        query.setFocus(&f);
        QString res;
        query.setQuery(QString("/DBFilesClient/%1[@build=\"%2\"]").arg(QFileInfo(_filename).baseName())
                       .arg(index.data().toString()));
        query.evaluateTo(&res);

        QDomDocument doc;
        defModel->clear();
        defModel->setColumnCount(2);
        defModel->setHorizontalHeaderLabels(QStringList() << tr("Label") << tr("Type"));
        if (doc.setContent(res))
        {
            QDomElement docElem = doc.documentElement();

            QDomNode n = docElem.firstChild();
            while (!n.isNull())
            {
                QDomElement e = n.toElement();

                if (e.tagName() == "field")
                {
                    QStandardItem *item1 = new QStandardItem(e.attribute("name"));
                    QStandardItem *item2 = new QStandardItem(e.attribute("type"));
                    defModel->appendRow(QList<QStandardItem*>() << item1 << item2);
                }
                n = n.nextSibling();
            }
            ui->tableView->reset();
        }
    }
}

void SelDefenitionDlg::fillDefenition(const QString &filename, quint32 build)
{
    QXmlQuery query;
    QString dbclayout = QFileInfo(QCoreApplication::applicationFilePath()).absolutePath() + "/dbclayout.xml";
    QFile f(dbclayout);

    setFileBuild(build);

    if (f.open(QIODevice::ReadOnly))
    {
        _filename = filename;
        query.setFocus(&f);
        QString res;
        query.setQuery(QString("/DBFilesClient/%1").arg(QFileInfo(filename).baseName()));
        query.evaluateTo(&res);

        QDomDocument doc;
        if (doc.setContent(QString("<root>%1</root>").arg(res)))
        {
            QStringList builds;

            QDomElement docElem = doc.documentElement();

            QDomNode n = docElem.firstChild();
            while (!n.isNull())
            {
                QDomElement e = n.toElement();
                builds << e.attribute("build");
                n = n.nextSibling();
            }

            model->setStringList(builds);
        }
    }
}
