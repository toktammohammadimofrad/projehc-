#include "StrikerBase.h"

StrikerBase::StrikerBase(QObject* parent)
    : AgentBase(parent), attackInterval(1000)
{
    speed = 1;
}
