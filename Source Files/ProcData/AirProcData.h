#ifndef AIRPROCDATA_H_INCLUDED
#define AIRPROCDATA_H_INCLUDED

#include "procdata.h"


    /**
     * @class AirProcData
     * @brief Concrete class for Ambient Air Temperature
     */

class AirProcData : public ProcData
{
public:
        /**
        * @brief default constructor
        */
    AirProcData();
        /**
         * @brief Copy Constructor
         * @param AirProcData & APD
         */
    AirProcData(const AirProcData & APD);
        /**
         * @brief Fills the contained vector with data
         * @param NDC & ndc, data struct containing information, int - n, desired month
         * @pre Month must be a valid month
         * @post copies the month data into the MonthData Vector
         * @return void
         */
    void NGetData(const NDC & ndc, const int n);
    ~AirProcData();
};

#endif // AIRPROCDATA_H_INCLUDED
