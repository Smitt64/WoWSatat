#include "db2window.h"
#include "ui_db2window.h"
#include "db2tablemodel.h"
#include "stringlistdlg.h"
#include "seldefenitiondlg.h"
#include <QFileInfo>
#include <QInputDialog>

DB2Window::DB2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB2Window)
{
    ui->setupUi(this);
    dbModel = new DB2TableModel(this);
    tableView = new QTableView(this);

    tableView->setModel(dbModel);

    QHeaderView *verticalHeader = tableView->verticalHeader();
    verticalHeader->setDefaultSectionSize(22);

    setCentralWidget(tableView);

    /*asFloat = new QAction(tr("Float"), this);
    asInt = new QAction(tr("Integer"), this);
    asString = new QAction(tr("String"), this);*/
    QList<QAction*> typeAction;
    for (int i = 0; i < ITEMSCOUNT; i++)
    {
        typeAction.append(new QAction(ItemTypes[i].name, this));
        connect(typeAction.last(), SIGNAL(triggered(bool)), SLOT(onTypeAction()));
    }

    typeAction.append(new QAction(this));
    typeAction.last()->setSeparator(true);
    valueFilter = new QAction(tr("Filter by value"), this);
    typeAction.append(valueFilter);

    tableView->addActions(typeAction);
    tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
}

DB2Window::~DB2Window()
{
    delete ui;
}

void DB2Window::load(const QString &str)
{
    if (dbModel->load(str))
    {
        setWindowTitle(QFileInfo(str).fileName());
    }
}

void DB2Window::showStringsList()
{

    StringListDlg dlg(dbModel->string_block, dbModel->stringTableSize, this);
    dlg.exec();
}

void DB2Window::onTypeAction()
{
    QAction *action = (QAction*)sender();
    QModelIndexList lst = tableView->selectionModel()->selectedIndexes();

    foreach (QModelIndex index, lst) {
        dbModel->setType(index.column(), action->text());
    }
}

/*void DB2Window::onString()
{
    QModelIndexList lst = tableView->selectionModel()->selectedIndexes();

    foreach (QModelIndex index, lst) {
        dbModel->setTypeToString(index.column());
    }
}*/

void DB2Window::showFormatString()
{
    QInputDialog::getText(this, tr("Format string"), "", QLineEdit::Normal, dbModel->makeFormat());
}
