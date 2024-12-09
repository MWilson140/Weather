#include "NDC.h"

NDC::NDC()
{
    year = 0;
}

int NDC::getYear()const
{
    return year;
}

std::map<MetaData,AllData>NDC::getMap()const
{
    return MP;
}

void NDC::FillData(const NDC & ndc) //get year in menu
{
    std::map<MetaData,AllData> Temp;
    Temp = ndc.getMap();
    std::map<MetaData,AllData>::iterator IT;
    for (IT = Temp.begin(); IT != Temp.end(); IT++)
    {
        if (IT->first.date.GetMonth() == this->getYear())
        {
            this->MP.insert(*IT);
        }
    }
}

bool NDC::checkEmpty()const
{
    return MP.empty();
}

void NDC::setYear(const int n)
{
    year = n;
}
bool NDC::operator < (const NDC & ndc)const
{
    if (this->year < ndc.year)
    return true;
    else
        return false;
}
bool NDC::operator > (const NDC & ndc)const
{
    if (this->year > ndc.year)
        return true;
    else
        return false;
}

bool NDC::operator == (const NDC & ndc)const
{
    if (this->year == ndc.year)
        return true;
    else
        return false;
}

bool NDC::addData(MetaData & MD, AllData & AD)
{
    if (year == 0 || year == MD.date.GetYear())
    {
        MP[MD] = AD;
        year = MD.date.GetYear();
        return true;
    }
    else
        return false;
}

void NDC::ClearData()
{
    year = 0;
    MP.clear();
}

NDC::NDC(const NDC & d)
{
    this->year = d.year;
    this->MP = d.MP;
}
