#ifndef PROCDATA_H_INCLUDED
#define PROCDATA_H_INCLUDED

#include "../NDC/NDC.h"
#include <map>
#include "../Vector/Vector.h"
#include <iostream>

    /**
     * @class ProcData
     * @brief abstract class for proccessing data and storing it
     */

class ProcData
{
public:
    ProcData();
    virtual void NGetData(const NDC & ndc, const int n) = 0;
    Vector<float> MonthData; //for children
    virtual ~ProcData();
};




#endif // PROCDATA_H_INCLUDED
