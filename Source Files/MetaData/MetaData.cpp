#include "MetaData.h"

MetaData::MetaData()
{
}

MetaData::MetaData(const MetaData & MD)
{
    this->date = MD.date;
    this->time = MD.time;
}

bool MetaData::operator < (const MetaData & c) const
{
    bool lessthan = false;
    if (this->date < c.date)
    {
        lessthan = true;
    }
    if (this->date == c.date && this->time < c.time)
    {
        lessthan = true;
    }
    return lessthan;
}

MetaData::~MetaData()
{
}
