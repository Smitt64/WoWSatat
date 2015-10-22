#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "db2window.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mdi = new QMdiArea(this);
    mdi->setViewMode(QMdiArea::TabbedView);
    mdi->setDocumentMode(true);
    mdi->setTabsClosable(true);
    setCentralWidget(mdi);

    ui->mainToolBar->addAction(ui->actionOpen);

    connect(ui->actionOpen, SIGNAL(triggered(bool)), SLOT(open()));
    connect(ui->actionString_table, SIGNAL(triggered(bool)), SLOT(showStringsTable()));
    connect(ui->actionShow_formt_string, SIGNAL(triggered(bool)), SLOT(showFormatString()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QString str = QFileDialog::getOpenFileName(this, QString(), QDir::currentPath(), "WoW DBC,DB2 (*.dbc *.db2);;WoW DB2 (*.db2);;WoW DBC (*.dbc)");

    if (str.length() <= 0)
        return;

    DB2Window *wnd = new DB2Window(this);

    mdi->addSubWindow(wnd);

    wnd->load(str);
    wnd->show();
}

void MainWindow::showStringsTable()
{
    QMdiSubWindow *wnd = mdi->currentSubWindow();

    if (wnd)
    {
        DB2Window *w = (DB2Window*)wnd->widget();
        w->showStringsList();
    }
}

void MainWindow::showFormatString()
{
    QMdiSubWindow *wnd = mdi->currentSubWindow();

    if (wnd)
    {
        DB2Window *w = (DB2Window*)wnd->widget();
        w->showFormatString();
    }
}
