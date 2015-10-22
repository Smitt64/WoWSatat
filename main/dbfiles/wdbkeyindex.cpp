#include "wdbkeyindex.h"

WDBKeyIndex::WDBKeyIndex():
    root(NULL)
{

}

void WDBKeyIndex::insert(const quint32 &key, const quint64 &offset)
{
    root = insertNode(root, key, offset);
}

int WDBKeyIndex::search(const quint32 &key)
{
    return search(key, root);
}

int WDBKeyIndex::search(const quint32 &key, WDBKeyIndex::WDBKeyIndexNode *&tree)
{
    if (!tree)
        return -1;

    if(key < tree->_key)
    {
        return search(key, tree->left);
    }
    else if(tree->_key < key)
    {
        return search(key, tree->right);
    }
    else
    {
        return tree->_recordOffset;
    }

    return -1;
}

WDBKeyIndex::WDBKeyIndexNode *WDBKeyIndex::insertNode(WDBKeyIndexNode* p, const quint32 &key, const quint64 &offset)
{
    if(!p)
        return new WDBKeyIndexNode(key, offset);

    if( key < p->_key )
    {
        p->left = insertNode(p->left,key, offset);
        p = balance(p);
    }
    else
    {
        p->right = insertNode(p->right,key, offset);
        p = balance(p);
    }
    return p;
}

WDBKeyIndex::WDBKeyIndexNode *WDBKeyIndex::balance(WDBKeyIndexNode *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor >1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < 1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}

quint32 WDBKeyIndex::diff(WDBKeyIndexNode *temp)
{
    quint32 l_height = height (temp->left);
    quint32 r_height = height (temp->right);
    quint32 b_factor= l_height - r_height;
    return b_factor;
}

quint32 WDBKeyIndex::height(WDBKeyIndexNode *temp)
{
    quint32 h = 0;
    if (temp != NULL)
    {
        quint32 l_height = height (temp->left);
        quint32 r_height = height (temp->right);
        quint32 max_height = qMax (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

WDBKeyIndex::WDBKeyIndexNode *WDBKeyIndex::rr_rotation(WDBKeyIndexNode *parent)
{
    WDBKeyIndexNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

WDBKeyIndex::WDBKeyIndexNode *WDBKeyIndex::ll_rotation(WDBKeyIndexNode *parent)
{
    WDBKeyIndexNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

WDBKeyIndex::WDBKeyIndexNode *WDBKeyIndex::lr_rotation(WDBKeyIndexNode *parent)
{
    WDBKeyIndexNode *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}

WDBKeyIndex::WDBKeyIndexNode *WDBKeyIndex::rl_rotation(WDBKeyIndexNode *parent)
{
    WDBKeyIndexNode *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
