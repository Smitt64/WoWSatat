#ifndef WDBKEYINDEX_H
#define WDBKEYINDEX_H

#include <QtCore>

class WDBKeyIndex
{
    struct WDBKeyIndexNode
    {
        WDBKeyIndexNode *left;
        WDBKeyIndexNode *right;
        quint32 _key;
        quint64 _recordOffset;

        WDBKeyIndexNode(const quint32 &key, const quint64 &offset) :
            left(NULL),
            right(NULL)
        {
            _key = key;
            _recordOffset = offset;
        }
    };
public:
    WDBKeyIndex();

    void insert(const quint32 &key, const quint64 &offset);
    int search(const quint32 &key);

private:
    WDBKeyIndexNode *insertNode(WDBKeyIndexNode* p, const quint32 &key, const quint64 &offset);
    WDBKeyIndexNode *balance(WDBKeyIndexNode *temp);
    quint32 diff(WDBKeyIndexNode *temp);
    quint32 height(WDBKeyIndexNode *temp);

    int search(const quint32 &key, WDBKeyIndexNode *&tree);

    WDBKeyIndexNode *rr_rotation(WDBKeyIndexNode *parent);
    WDBKeyIndexNode *ll_rotation(WDBKeyIndexNode *parent);
    WDBKeyIndexNode *lr_rotation(WDBKeyIndexNode *parent);
    WDBKeyIndexNode *rl_rotation(WDBKeyIndexNode *parent);

    WDBKeyIndexNode *root;
};

#endif // WDBKEYINDEX_H
