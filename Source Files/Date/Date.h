#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>
#include <sstream>

using namespace std;


    /**
     * @class Date
     * @brief Class for storing date variables
     * class used for storing and updating date variables
     * has checking to make sure only valid dates are stores
     * @bug day max is 31 when no month is set, once day is set, month cannot be set if the day is less than the max for that month
     */


class Date
{
public:
    Date();
    Date(const int d, const int m, const int y);
    Date (const Date & d);

        /**
         * @brief Assignment opperator
         */
    Date & operator = (const Date & d);
        /**
         * @brief less than operator
         */
    bool operator < (const Date & d)const;
        /**
         * @brief greater than opperator
         */
    bool operator > (const Date & d)const;
        /**
         * @brief equality opperator
         */
    bool operator == (const Date & d) const;
        /**
         * @brief destructor
         */
    virtual ~Date();
        /**
         * @brief Setter for day
         * @param n - int for Day
         * @pre Must be a valid amount of days for the month
         * if not month is set, the maximum is 31
         */
    void SetDay(const int n);
        /**
         * @brief Getter for day
         * @return int - amount for day
         */
    int GetDay() const;
        /**
         * @brief
         * @param m - int for Month
         * @pre must be between 1 and 12
         */
    void SetMonth(const int m);
        /**
         * @brief Getter for month
         * @return int - month
         */
    int GetMonth() const;
        /**
        * @brief Setter for year
        * @param n - int for Year
        * @pre Must be between 1 and 3000
        */
    void SetYear(const int n);
        /**
         * @brief Getter for year
         * @return int - amount for year
         */
    int GetYear() const;
        /**
         * @brief Set Year, Month and day using a string
         * @param string & s - string to set the values
         * @pre must be in the format DD/MM/YYYY
         * @post
         */
    void SetUsingString(std::string & s);



private:
    int Day;
    int Year;
    int Month;
        /**
         * @brief Checks if the year is a leap year
         * @param int - year
         * @return bool - true if yes, false if no
         */
    bool LeapYear(const int n)const;
        /**
         * @brief Checks if the day input is valid
         * @param int - day
         * @return void
         */
    void DayCheck(const int n)const;
        /**
         * @brief Checks if the month input
         * @param int - month
         * @return void
         */
    void MonthCheck(const int n)const;
        /**
        *@brief Checks if the year input is valid
        *@param int - year
        @return void
        */
    void YearCheck(const int n)const;
};
#endif // DATE_H_INCLUDED
