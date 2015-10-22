#ifndef STRINGLISTDLG_H
#define STRINGLISTDLG_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class StringListDlg;
}

class StringListDlg : public QDialog
{
    Q_OBJECT

public:
    explicit StringListDlg(const quint8 *stringstart, const quint32 &stringssize, QWidget *parent = 0);
    ~StringListDlg();

private:
    Ui::StringListDlg *ui;
    QStringListModel *strings;
};

#endif // STRINGLISTDLG_H
