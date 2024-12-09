#ifndef WINDPROCDATA_H_INCLUDED
#define WINDPROCDATA_H_INCLUDED

#include "procdata.h"

    /**
     * @class WindProcData
     * @brief Concrete class for wind data
     */

class WindProcData : public ProcData
{
public:
        /**
        * @brief default constructor
        */
    WindProcData();
        /**
         * @brief Copy Constructor
         * @param WindProcData & WPD
         */
    WindProcData(const WindProcData & WPD);
        /**
         * @brief Fills the contained vector with data
         * @param NDC & ndc, data struct containing information, int - n, desired month
         * @post copies the month data into the MonthData Vector
         * @return void
         */
    void NGetData(const NDC & ndc, const int n);
    ~WindProcData();
};

#endif // WINDPROCDATA_H_INCLUDED
