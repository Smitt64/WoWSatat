#ifndef DB2WINDOW_H
#define DB2WINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QTableView>
#include <QSplitter>
#include <QHBoxLayout>
#include <QAction>

namespace Ui {
class DB2Window;
}

class DB2TableModel;
class DB2Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit DB2Window(QWidget *parent = 0);
    ~DB2Window();
    void load(const QString &str);
    void showStringsList();
    void showFormatString();

private slots:
    void onTypeAction();
private:
    Ui::DB2Window *ui;
    DB2TableModel *dbModel;
    QTableView *tableView;

    QAction *valueFilter;
};

#endif // DB2WINDOW_H
