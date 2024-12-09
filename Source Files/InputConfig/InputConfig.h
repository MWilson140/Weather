#ifndef INPUTCONFIG_H_INCLUDED
#define INPUTCONFIG_H_INCLUDED

#include <string>
#include "../Vector/Vector.h"

const int numInputs = 18; //number of input fields

typedef struct InputConfig
{
     /**
     * @brief Sets the desired input format
     */
     void SetInput();
     /**
     * @brief Sets the key
     * @param Vector<string> - inputFormat, the order of data from the input file
     */
    void SetKey(Vector<std::string>inputFormat);
    Vector<std::string> format;
    int NewKey[numInputs];

}InputConfig;


#endif // INPUTCONFIG_H_INCLUDED
