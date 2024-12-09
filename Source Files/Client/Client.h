#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "../Vector/Vector.h"
#include <string>
#include <fstream>
#include "../BST/BST.h"
#include "../NDC/NDC.h"
#include "../IoFuncts/IOFuncts.h"
#include <iterator>
#include "../InputConfig/InputConfig.h"
#include "../Collector/Collector.h"

const string Months[] = {"January", "February", "March",
    "April", "May", "June",
    "July","August", "September",
    "October", "November", "December"};
    /**
     * @brief USed for displaying and handling the menu options
     * @param BST<NDC> & myData - BST full of data
     * @return void
     */
bool menu(const BST<NDC> & myData);
    /**
     * @brief Organises the files in chronological order
     * @param Vector<string> files - vector of the file names
     * @post The files inside the vector are sorted based on the first date that appears inside the file.
     * @return void
     */
void OrganiseFiles(Vector<std::string> & files);
    /**
     * @brief Gets all the file names from a source file
     * @param string fileName - the source file name, Vector<string> vector to store the names
     * @post Adds all the file names to the vector
     * @return void
     */
void getFiles(std::string fileName, Vector<std::string>& files);

#endif // CLIENT_H_INCLUDED
