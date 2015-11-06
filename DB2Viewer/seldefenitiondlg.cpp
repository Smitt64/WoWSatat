#include "seldefenitiondlg.h"
#include "ui_seldefenitiondlg.h"
#include <QXmlQuery>
#include <QDomDocument>
#include <QFileInfo>
#include <QCoreApplication>
#include <QStringListModel>
#include <QInputDialog>
#include <QTextStream>
#include "comboboxdelegate.h"

DefItem ItemTypes[ITEMSCOUNT] =
{
    {"int", 'i', sizeof(int)},
    {"uint", 'u', sizeof(int)},
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

QString FindTypeName(char type)
{
    for (int i = 0; i < ITEMSCOUNT; i++)
    {
        if (ItemTypes[i].type == type)
        {
            return ItemTypes[i].name;
        }
    }

    return ItemTypes[0].name;
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
    buildNumber = 0;

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
    buildNumber = build;
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

QString SelDefenitionDlg::getLayoutFileName()
{
    return QFileInfo(QCoreApplication::applicationFilePath()).absolutePath() + "/dbclayout.xml";
}

void SelDefenitionDlg::fillDefenition(const QString &filename, quint32 build)
{
    QXmlQuery query;
    QString dbclayout = getLayoutFileName();
    QFile f(dbclayout);

    setFileBuild(build);
    wdbFilename = QFileInfo(filename).baseName();

    if (f.open(QIODevice::ReadOnly))
    {
        _filename = filename;
        query.setFocus(&f);
        QString res;
        query.setQuery(QString("/DBFilesClient/%1").arg(wdbFilename));
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

void SelDefenitionDlg::on_btnAdd_clicked()
{
    QFile f(getLayoutFileName());

    if (!f.open(QIODevice::ReadOnly))
        return;

    QDomDocument doc("layout");
    if (!doc.setContent(&f))
    {
        f.close();
        return;
    }

    bool ok = false;
    int build = QInputDialog::getInt(this, tr("Add new build"), tr("Enter build number: "), buildNumber, 0, 2147483647, 1, &ok);

    if (ok)
    {
        QDomElement docElem = doc.documentElement();

        QDomElement item = doc.createElement(wdbFilename);
        item.setAttribute("build", build);

        for (int i = 0; i < defModel->rowCount(); i++)
        {
            QDomElement fld = doc.createElement("field");
            fld.setAttribute("type", "int");
            fld.setAttribute("name", QString("unknown%1").arg(i + 1));
            item.appendChild(fld);
        }
        docElem.appendChild(item);

        f.close();

        if (f.open(QIODevice::WriteOnly))
        {
            QTextStream s(&f);
            doc.save(s, 2);
            f.close();

            model->insertRow(model->rowCount());
            model->setData(model->index(model->rowCount() - 1, 0), item.attribute("build"));
        }

    }
}
