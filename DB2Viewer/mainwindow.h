#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void open();
    void showFormatString();
    void showStringsTable();
    void setFilterDlg();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdi;
};

#endif // MAINWINDOW_H
