#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include <cmath>
#include "../Vector/Vector.h"


    /**
     * @brief Methods for calculations
     */

using namespace std;

    /**
     * @brief Calc the total of all values
     * @param Vector of t
     * @return T sum of the vector
     */
template <class T>
T CalcTotal(const Vector<T> & data)
{
    if (data.GetLength() ==0)
    {
        throw "cannot divide by 0";
    }
    T sum = 0;
    for(int i =0; i < data.GetLength(); i++)
    {
        sum += data[i];
    }
    return sum;
}

    /**
     * @brief Rounds a number to two decimal places
     * @param T num - a number
     * @return num rounded to two decimal places.
     */
template <class T>
T Round(T num)
{
    num = num * 100;
    num = std::round(num);
    num = num/100;
    return num;
}

    /**
     * @brief Calculates the mean of the values
     * @param Vector<T> & data
     * @pre Must be more than 1 entry
     * @return float - the mean of the values
     */
template <class T>
float CalcMean(const Vector<T> & data)
{
    float total = 0;
    float mean = 0;
    try
    {
        total = CalcTotal(data);
    }
    catch (...)
    {
        throw "canot divide by 0";
    }
    mean = total/(float)data.GetLength();
    return mean;
}
    /**
     * @brief calculates the standard deviation of the values
     * @param Vector of type T
     * @pre Must be more than 1 entry in the vector
     * @return float - the standard deviation
     */
template <class T> //change to calc mean inside
float CalcStdDev(const Vector<T> & Data)
{
    float mean;
    try
    {
        mean = CalcMean(Data);
    }
    catch (...)
    {
        throw "Cannot divide by 0";
    }
    float sum = 0;
    for (int i =0; i < Data.GetLength(); i++)
    {
        sum+= ((Data[i] - mean) * (Data[i] - mean));
    }
    sum = sum / (Data.GetLength() -1);
    sum = sqrt(sum);
    return sum;
}
    /**
     * @brief Calculates the pearson of two Vectors
     * @param Vector<T> & Vectx - vector 1, Vector<T> & Vecty - vector 2
     * @pre Vectors must be same size, and contain more than 1 value each
     * @return The pearson correlation
     */
template <class T>
float sPCC(const Vector<T> & Vectx, const Vector<T> & Vecty)
{
    if (Vectx.GetLength() != Vecty.GetLength())
    {
        throw "Data is not the same size";
    }
    float xmean = 0;
    float ymean = 0;
    float equaTopx = 0;
    float equaTopy = 0;
    float equaTopt= 0;
    float equaBotx = 0;
    float equaBoty = 0;
    float equaBott = 0;
    float sum;

    try
    {
        xmean = CalcMean(Vectx);
        ymean = CalcMean(Vecty);
    }
    catch (...)
    {
        throw "Cannot divide by 0";
    }
    for(int i = 0; i < Vectx.GetLength(); i++)
    {
        equaTopx = (Vectx[i] - xmean);
        equaTopy = (Vecty[i] - ymean);
        equaTopt += equaTopx * equaTopy;
        equaBotx += ((Vectx[i] - xmean) * (Vectx[i] - xmean));
        equaBoty += ((Vecty[i] - ymean) * (Vecty[i] - ymean));
    }
    equaBotx = sqrt(equaBotx);
    equaBoty = sqrt(equaBoty);
    equaBott = equaBotx * equaBoty;
    sum = equaTopt/equaBott;
    sum = Round(sum);
    return sum;
}
#endif // MATH_H_INCLUDED
