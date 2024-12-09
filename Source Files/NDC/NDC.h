#ifndef NDC_H_INCLUDED
#define NDC_H_INCLUDED

#include <map>
#include "../dailyData/DailyData.h"
#include "../MetaData/MetaData.h"
    /**
     * @class NDC
     * @brief Wrapper class for a map with a singular key for all the data ontop of the map key.
     * Stores date and time values inside a map with its associated data. The year variable is for a key.
     * Only data that falls within the year should be stored inside this class.
     */

class NDC
{
public:
        /**
         * @brief Default constructor
         */
    NDC();
        /**
         * @brief Copy Constructor
         * @param NDC & d
         */
    NDC(const NDC & d);

    void FillData(const NDC & ndc);
        /**
         * @brief Setter for yeclassar (key)
         * @param int n - year
         * @post Sets year to n
         * @return void
         */
    void setYear(const int n);
        /**
         * @brief getter for year (key)
         * @return int
         */
    int getYear()const;
        /**
         * @brief getter for the Map
         * @return std::map<MetaData,AllData>
         */
    std::map<MetaData,AllData>getMap()const;
        /**
         * @brief Checks if the map is empty
         * Helper method for the map
         * @param int n - year
         * @post Sets year to n
         * @return void
         */
    bool checkEmpty()const;

        /**
         * @brief Adds a key pair to the map
         * helper method for the insert of the map
         * @param MetaData & MD - class containing date and time, ALlData & AD the variabled to be stored
         * @return void
         */
    bool addData(MetaData & MD, AllData & AD);
        /**
         * @brief Empties the map
         * helper method for the map function clear
         * @post Empties the map
         * @return void
         */
    void ClearData();
        /**
         * @brief less than operator
         * for BST functionality
         * @param NDC - ndc, class to be compared against
         * @return returns true if less than, false if not equal
         */
    bool operator < (const NDC & ndc)const; //used in bst
        /**
         * @brief Greater than operator
         * for BST functionality
         * @param NDC - ndc, class to be compared against
         * @return returns true if greater than, false if not equal
         */
    bool operator > (const NDC & ndc)const; //used in bst

        /**
         * @brief equals operator compairing against an NDC
         * @param iNDC & ndc - class to compair against
         * @return returns true if equals, false if not equal
         */
    bool operator == (const NDC & ndc)const; //tree search
        /**
         * @brief  equals operator compairing against an int
         * @param int i - year
         * @return returns true if equals, false if not equal
         * @return returns true if equals, false if not equal
         */
private:
    int year;
    std::map<MetaData,AllData> MP;
};

#endif // NDC_H_INCLUDED
