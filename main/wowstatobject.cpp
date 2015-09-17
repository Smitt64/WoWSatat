#include "wowstatobject.h"

WowStatObject::WowStatObject(QObject *parent)
    : QObject(parent)
{

}

int WowStatObject::init()
{
    return WowStatObject::INIT_NOERROR;
}
