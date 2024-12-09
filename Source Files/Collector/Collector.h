#ifndef COLLECTOR_H_INCLUDED
#define COLLECTOR_H_INCLUDED

#include "../NDC/NDC.h"

    /**
    * @class Collector
    * @brief Class used for collection of data from the BST
    */

typedef class Collector
{
public:
    static void CollData(const NDC & ndc);
    static NDC * Destination;
}Collector;

#endif // COLLECTOR_H_INCLUDED
