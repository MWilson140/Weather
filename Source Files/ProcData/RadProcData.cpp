#include "RadProcData.h"

RadProcData::RadProcData()
{
}

RadProcData::~RadProcData()
{

}

RadProcData::RadProcData(const RadProcData & RPD)
{
    this->MonthData = RPD.MonthData;
}

void RadProcData::NGetData(const NDC & ndc, const int n) //just store raw data, no modifications
{
    float temp;
    std::map<MetaData,AllData>::const_iterator IT;
    std::map<MetaData,AllData> TempMap;
    TempMap = ndc.getMap();
    for (IT = TempMap.begin(); IT != TempMap.end();IT++)
    {
        if (IT->first.date.GetMonth() == n)
        {
            if (IT->second.solarRadiation !=-999.0)
            {
                temp = (IT->second.solarRadiation);
                MonthData.pushBack(temp);
            }
        }
    }
}

void RadProcData::calcRad()
{
    Vector<float> Temp;
    for(int i = 0; i < MonthData.GetLength(); i++)
    {
        Temp.pushBack((MonthData[i] * ((float)1/6)) / (float)1000);
    }
    MonthData = Temp;
}

void RadProcData::trim()
{
    Vector<float> temp;
    for (int i = 0; i < MonthData.GetLength(); i++)
    {
        if (MonthData[i] > 100)
        {
            std::cout<<"copied" << MonthData[i] << std::endl;
            temp.pushBack(MonthData[i]);
        }
    }
    MonthData = temp;
}

