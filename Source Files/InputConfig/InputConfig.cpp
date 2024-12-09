#include "InputConfig.h"


void InputConfig::SetInput() //get from config file later on
{
    std::string Data[] = {"WAST", "T", "DP", "Dta",
    "Dts", "EV", "QFE", "QFF", "QNH",
    "RF", "RH", "S", "SR","ST1", "ST2",
    "ST3", "ST4", "Sx"};
    for (int i = 0; i < numInputs; i++)
    {
        format.pushBack(Data[i]);
    }
}

void InputConfig::SetKey(Vector<std::string>inputFormat)
{
    for (int i = 0; i < numInputs; i ++)
    {
        for (int j = 0; j < numInputs; j++)
        {
            if (format[i].compare(inputFormat[j]) == 0)
            {
                InputConfig::NewKey[i] = j;
            }
        }
    }
}
