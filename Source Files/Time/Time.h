#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <sstream>

    /**
     * @class Time
     * @brief Class for storing time values
    */
class Time
{
public:
        /**
         * @brief Default constructor
         */
    Time();
        /**
         * @brief Construtor with paramaters
         * @param int m - minutes, int h - hours
         * @pre values must be valid
         * @post set minutes and hours
         */
    Time (const int m, const int h);
        /**
         * @brief Copy Constructor
         * @param Time & t
         * @post set the new time object
         */
    Time(const Time & T);
        /**
         * @brief destructor
         */
    ~Time();

        /**
         * @brief = operator
         * @param Time & t
         * @post Copies the object
         */
    Time & operator = (const Time & t);
        /**
         * @brief Less than operator
         * @param Time & t
         * @post returns true if the second opperand is less than the first.
         */
    bool operator < (const Time & t) const;
        /**
         * @brief Less than operator
         * @param Time & t
         * @post returns true if the second opperand is less than the first.
         */

        /**
         * @brief Second setter
         * @param int - seconds
         * @pre n must be between 0 and 59
         * @post Sets seconds to n
         * @return void
         */
    void SetSecond(const int n);
        /**
         * @brief Seconds getter
         * @return int second value
         */
    int GetSecond() const;
        /**
         * @brief Minute setter
         * @param int - Minute
         * @pre n must be between 0 and 59
         * @post Sets minutes to n
         * @return void
         */
    void SetMinute(const int n);
        /**
         * @brief Miute getter
         * @return int
         */
    int GetMinute() const;
        /**
         * @brief hour setter
         * @param int - seconds
         * @return void
         */
    void SetHour(const int n);
        /**
         * @brief hour getter
         * @return int
         */
    int GetHour() const;

        /**
         * @brief Sets using a string input
         * @param string & s
         * @pre a string in the format HH:MM
         * @post Sets seconds to n
         * @return void
         */
    void SetUsingString(std::string & s);

private:
    int minute;
    int hour;
        /**
         * @brief Checks the minute input
         * @param int - minutes
         * @post throws exception if invalid int
         * @return void
         */
    void CheckMinute(const int n);
        /**
         * @brief Checks the hour input
         * @param int - hour
         * @post throws exception if invalid int
         * @return void
         */
    void CheckHour(const int n);
};

#endif // TIME_H_INCLUDED
