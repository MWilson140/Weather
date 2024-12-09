#include "Time.h"

Time::Time()
{
    minute = 0;
    hour = 0;
}
Time::Time(const int m, const int h)
{
    try
    {
        CheckMinute(m);
        CheckHour(h);
    }
    catch (const char* c)
    {
        throw c;
    }
    minute = m;
    hour = h;
}

Time::Time(const Time & T)
{
    this->minute = T.minute;
    this->hour = T.hour;
}
Time::~Time()
{

}

Time & Time::operator = (const Time & t)
{
    this->minute = t.minute;
    this->hour = t.hour;
    return *this;
}

bool Time::operator < (const Time & t)const
{
    bool lessthan = false;
    if (this->hour < t.hour)
    {
        lessthan = true;
    }
    if (this->hour == t.hour && this->minute < t.minute)
    {
        lessthan = true;
    }
    return lessthan;

}


void Time::SetMinute(const int n)
{
    try
    {
        CheckMinute(n);
    }
    catch (const char* c)
    {
        throw c;
    }
    minute = n;

}

void Time::CheckMinute(const int n)
{
    if (n < 0 || n > 59)
        throw "Minutes out of bounds";
}
int Time::GetMinute() const
{
    return minute;
}
void Time::SetHour(const int n)
{
    try
    {
        CheckHour(n);
    }
    catch (const char* c)
    {
        throw c;
    }
    hour = n;
}

void Time::CheckHour(const int n)
{
    if (n < 0 || n > 23)
        throw "Hour out of bounds";
}
int Time::GetHour() const
{
    return hour;
}

void Time::SetUsingString(std::string & s)
{
    std::stringstream sstr(s);
    try
    {
        getline(sstr, s,':');
        SetHour(stoi(s));
        getline(sstr,s,',');
        SetMinute(stoi(s));
    }
    catch (const char * e)
    {
        throw e;
    }
}

