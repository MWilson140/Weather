#ifndef DAILYDATA_H_INCLUDED
#define DAILYDATA_H_INCLUDED

#include "../Time/Time.h"
#include "../Date/Date.h"

    /**
     * @struct AllData
     * @brief struct to store data
     */

typedef struct
{
public:
    float speed;
    float ambientAirTemp;
    float solarRadiation;
    string Temp;
} AllData;

#endif // DAILYDATA_H_INCLUDED
