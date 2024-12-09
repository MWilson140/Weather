#ifndef RADPROCDATA_H_INCLUDED
#define RADPROCDATA_H_INCLUDED

#include "procData.h"
    /**
     * @class RadProcData
     * @brief Concrete class for Solar Radiation data
     */


class RadProcData : public ProcData
{
public:
        /**
        * @brief default constructor
        */
    RadProcData();
        /**
         * @brief Copy Constructor
         * @param RadProcData & RPD
         */
    RadProcData(const RadProcData & RPD);
        /**
         * @brief Fills the contained vector with data
         * @param NDC & ndc, data struct containing information, int - n, desired month
         * @post copies the month data into the MonthData Vector
         * @return void
         */
    void NGetData(const NDC & ndc, const int n);
        /**
         * @brief Converts n from W/m to KWh/m
         * @post All the values inside the vector are converted to KWh/m
         * @return void
         */
    void calcRad();

    void trim();
    ~RadProcData();
};



#endif // RADPROCDATA_H_INCLUDED
