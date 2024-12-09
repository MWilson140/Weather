#include "AirProcData.h"
AirProcData::AirProcData()
{
}

AirProcData::AirProcData(const AirProcData & APD)
{
    this->MonthData = APD.MonthData;
}

void AirProcData::NGetData(const NDC & ndc, const int n)
{
    std::map<MetaData,AllData>::const_iterator IT;
    std::map<MetaData,AllData> TempMap;
    TempMap = ndc.getMap();
    float temp;
    for (IT = TempMap.begin(); IT != TempMap.end();IT++)
    {
        if (IT->first.date.GetMonth() == n)
        {
            if (IT->second.ambientAirTemp != -999.0)
            {
                temp = IT->second.ambientAirTemp;
                MonthData.pushBack(temp);
            }
        }
    }
}
AirProcData::~AirProcData()
{
}

