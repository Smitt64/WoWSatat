#include "itemsdbc.h"
#include "dbcstructure.h"
#include <ppl.h>
#include <QDebug>

using namespace Concurrency;
using namespace std;

const ItemSparse *const FindItemSparse(const quint32 &itemId)
{
    ItemSparse *item = NULL;

    /*std::vector<ItemSparse*> v;
    v.assign(sItemSparse.DataTable(), sItemSparse.DataTable() + sItemSparse.GetNumRows());
    parallel_for_each(v.begin(), v.end(), [&item,itemId](ItemSparse n) {
        if (n.Id == itemId)
            item = (ItemSparse*)&n;
    });*/

    /*for (int i = 0; i < sItemSparse.GetNumRows(); i++)
    {
        if (sItemSparse.LookupEntry(i)->Id == itemId)
        {
            qDebug() << i << sItemSparse.LookupEntry(i)->Id;*/
            item = (ItemSparse*)wItemSparse.LookupEntry(itemId);
            /*break;
        }
    }*/

    return (const ItemSparse *const)item;
}
