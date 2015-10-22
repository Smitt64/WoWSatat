#include "comboboxdelegate.h"
#include <QComboBox>
#include <QApplication>

ComboBoxDelegate::ComboBoxDelegate(const QStringList &items, QObject *parent) :
    QItemDelegate(parent)
{
    _items = items;
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */, const QModelIndex &/* index */) const
{
    QComboBox* editor = new QComboBox(parent);
    for(unsigned int i = 0; i < _items.size(); ++i)
    {
        editor->addItem(_items[i]);
    }
    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    int value = index.model()->data(index, Qt::EditRole).toUInt();
    comboBox->setCurrentIndex(value);
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    model->setData(index, comboBox->currentText(), Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

void ComboBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItemV2 myOption = option;
    QString text = index.data().toString();

    myOption.text = text;

    QApplication::style()->drawControl(QStyle::CE_ItemViewItem, &myOption, painter);
}
