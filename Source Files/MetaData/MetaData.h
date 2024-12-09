#ifndef METADATA_H_INCLUDED
#define METADATA_H_INCLUDED

#include "../Date/Date.h"
#include "../Time/Time.h"


    /**
     * @struct MetaData
     * @brief Class to store the date and time in a singular location.
     */
struct MetaData
{
        /**
         * @brief Default constructor
         */
    MetaData();
        /**
         * @brief Copy Constructor
         * @param MetaData & MD - struct to be copries
         * @post Copies values from MD
         */
    MetaData(const MetaData & MD);
    Date date;
    Time time;
        /**
         * @brief Less than operator for the struct
         * @param MetaData & c
         * @return bool - true if less than, false if not
         */
    bool operator < (const MetaData & c) const;
    ~MetaData();
};


#endif // METADATA_H_INCLUDED
