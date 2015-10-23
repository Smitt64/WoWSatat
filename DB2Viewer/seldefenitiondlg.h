#ifndef SELDEFENITIONDLG_H
#define SELDEFENITIONDLG_H

#include <QDialog>
#include <QStringListModel>
#include <QStandardItemModel>

namespace Ui {
class SelDefenitionDlg;
}

typedef struct
{
    QString name;
    char type;
    quint16 size;
}DefItem;

#define ITEMSCOUNT 5
extern DefItem ItemTypes[ITEMSCOUNT];
char FindTypeForName(const QString &name);

class ComboBoxDelegate;
class SelDefenitionDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SelDefenitionDlg(QWidget *parent = 0);
    ~SelDefenitionDlg();

    void fillDefenition(const QString &filename, quint32 build);

    QStandardItemModel *defenition() { return defModel; }

private slots:
    void buildClicked(const QModelIndex &index);

private:
    void setFileBuild(quint32 build);
    Ui::SelDefenitionDlg *ui;
    QStringListModel *model;
    QString _filename;
    ComboBoxDelegate *delegate;
    QStandardItemModel *defModel;
};

#endif // SELDEFENITIONDLG_H
