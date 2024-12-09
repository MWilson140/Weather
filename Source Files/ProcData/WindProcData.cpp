#include "windprocdata.h"

WindProcData::WindProcData()
{
}

WindProcData::WindProcData(const WindProcData & WPD)
{
    this->MonthData = WPD.MonthData;
}

void WindProcData::NGetData(const NDC & ndc, const int n)
{
    std::map<MetaData,AllData>::const_iterator IT;
    std::map<MetaData,AllData> TempMap;
    TempMap = ndc.getMap();
    float temp;
    for (IT = TempMap.begin(); IT != TempMap.end();IT++)
    {
        if (IT->first.date.GetMonth() == n)
        {
            if (IT->second.speed != -999.0)
            {
                temp = IT->second.speed;
                MonthData.pushBack(temp);
            }
        }
    }
}

WindProcData::~WindProcData()
{

}
