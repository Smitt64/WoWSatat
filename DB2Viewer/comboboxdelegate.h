#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QObject>
#include <QItemDelegate>
#include "seldefenitiondlg.h"

class QModelIndex;
class QWidget;
class QVariant;
class ComboBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ComboBoxDelegate(const QStringList &items, QObject *parent);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

private:
    QStringList _items;
};

#endif // COMBOBOXDELEGATE_H
