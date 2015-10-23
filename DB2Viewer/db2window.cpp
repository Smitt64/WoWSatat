#include "db2window.h"
#include "ui_db2window.h"
#include "db2tablemodel.h"
#include "stringlistdlg.h"
#include "db2filtersortmodel.h"
#include "seldefenitiondlg.h"
#include "filterdlg.h"
#include <QFileInfo>
#include <QInputDialog>
#include <QClipboard>

DB2Window::DB2Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DB2Window)
{
    ui->setupUi(this);
    dbModel = new DB2TableModel(this);
    tableView = new QTableView(this);

    filter = new DB2FilterSortModel(this);

    QHeaderView *verticalHeader = tableView->verticalHeader();
    verticalHeader->setDefaultSectionSize(22);

    setCentralWidget(tableView);

    /*asFloat = new QAction(tr("Float"), this);
    asInt = new QAction(tr("Integer"), this);
    asString = new QAction(tr("String"), this);*/
    actionCopy = new QAction(tr("Copy"), this);
    actionCopy->setShortcut(QKeySequence(QKeySequence::Copy));
    QList<QAction*> typeAction;
    typeAction.append(actionCopy);
    typeAction.append(new QAction(this));
    typeAction.last()->setSeparator(true);
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

    connect(valueFilter, SIGNAL(triggered(bool)), SLOT(filterByColumnValue()));
    connect(actionCopy, SIGNAL(triggered(bool)), SLOT(onCopy()));
}

DB2Window::~DB2Window()
{
    delete ui;
}

void DB2Window::load(const QString &str)
{
    if (dbModel->load(str))
    {
        filter->setSourceModel(dbModel);
        tableView->setModel(filter);
        setWindowTitle(QFileInfo(str).fileName());
    }
}

void DB2Window::onCopy()
{
    QModelIndexList lst = tableView->selectionModel()->selectedIndexes();

    QString clip;
    if (lst.size() > 0)
    {
        clip = lst[0].data().toString();
    }
    /*foreach (QModelIndex index, lst) {
        clip += index.data().toString() + ",";
    }*/
    QApplication::clipboard()->setText(clip);
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

void DB2Window::setFilter()
{
    QStringList lst;

    for (int i = 0; i < dbModel->fieldsOffsets.size(); i++)
    {
        lst.append(dbModel->fieldsOffsets[i].title + QString(":%1").arg(i + 1));
    }

    FilterDlg dlg(lst, this);

    if (dlg.exec())
    {
        filter->setFilterString(dlg.getFilterString());
        filter->invalidate();
    }
}

void DB2Window::showFormatString()
{
    QInputDialog::getText(this, tr("Format string"), "", QLineEdit::Normal, dbModel->makeFormat());
}

void DB2Window::filterByColumnValue()
{
    QModelIndexList lst = tableView->selectionModel()->selectedIndexes();

    if (lst.size())
    {
        bool ok = false;
        QVariant val;
        switch(dbModel->formaStr()[lst[0].column()].toLatin1())
        {
        case FLD_INT:
        case FLD_KEY:
            {
                val = QInputDialog::getInt(this, "Filter by:", "Enter value:", lst[0].data().toInt(),
                        -2147483647, 2147483647, 1, &ok);
            }
            break;
        case FLD_FLOAT:
            {
                val = QInputDialog::getDouble(this, "Filter by:", "Enter value:", lst[0].data().toDouble(),
                        -2147483647, 2147483647, 1, &ok);
            }
            break;
        case FLD_STRING:
            {
                val = QInputDialog::getText(this, "Filter by:", "Enter value:", QLineEdit::Normal,
                                            lst[0].data().toString(), &ok);
            }
            break;
        }

        if (ok)
        {
            filter->filterByColumnValue(lst[0].column(), val);
            filter->invalidate();
        }
    }
}
