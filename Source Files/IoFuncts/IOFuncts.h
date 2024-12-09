#ifndef IOFUNCTS_H_INCLUDED
#define IOFUNCTS_H_INCLUDED

#include "../Client/client.h"
#include "../ProcData/AirProcData.h"
#include "../ProcData/ProcData.h"
#include "../ProcData/RadProcData.h"
#include "../ProcData/WindProcData.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../NDC/NDC.h"
#include "../BST/BST.h"
#include "../InputConfig/InputConfig.h"
#include "../Math/Math.h"

    /**
     * @brief Reads the data into InputConfig Class
     * @param istream & input - the input, Vector<string> the split input
     * @pre CSV formatted string of data labels
     * @post Sets the vector to the input of the file
     * @return istream
     */
std::istream & operator >> (std::istream & input, Vector<string> & IF); //only for first lines
    /**
     * @brief Reads the data from the files
     * @param Vector<string> & files - the name of all the files, BST<NDC> & myData, BST to store the data
     * @pre The Vector of files must be sorted chronologically
     * @post Stores all the data inside of the BST based on year
     * @return istream
     */
void ReadFiles(Vector<std::string> & files, BST<NDC> & myData);
    /**
     * @brief Reads the data from the files
     * @param Vector<string> & files - the name of all the files, BST<NDC> & myData, BST to store the data
     * @pre The Vector of files must be sorted chronologically
     * @post Stores all the data inside of the BST based on year
     * @return istream
     */
std::stringstream & operator >> (std::stringstream & input, MetaData & MD);
    /**
     * @brief Gets a string month from the user
     * @return the int of the month
     */
int UserMonth();
    /**
     * @brief Gets a int year from the user
     * @return the int of the year
     */
int UserYear();
    /**
     * @brief Prints the menu options
     * @return void
     */
void printMenu();
    /**
     * @brief Handles the menu 1 option
     * @param NDC & ndc - class containing data
     * @return the int of the month
     */
void Menu1 (const NDC * Result);
    /**
     * @brief Handles the menu 2 option
     * @param NDC & ndc - class containing data
     * @return the int of the month
     */
void Menu2 (const NDC * Result);
    /**
     * @brief Handles the menu 3 option
     * @param NDC & ndc - class containing data
     * @return the int of the month
     */

    /**
     * @brief Prints the output from menu 3
     * This was split up to help make the routine smaller and more readable
     * @param WindProc, AirProc, RadProc - data to be printed, int Year - the year
     * @return void
     */

    /**
     * @brief Handles the logic menu 3 option
     * This routine was split to help make it smaller and more readable
     * @param const NDC & Result, the data to be processed
     * @return void
     */
void Menu3 (const NDC & Result);
    /**
     * @brief Organises the files in chronological order
     * @param Vector<string> the files names
     * @post Rearanges the Vector of file names to be in chronological order
     * @return void
     */

void printMenu3(const WindProcData & WPD, const AirProcData & APD, const RadProcData & RPD, const int & Year);
    /**
     * @brief Handles the menu 4 option
     * @param NDC & ndc - class containing data
     * @return the int of the month
     */
void Menu4 (const NDC * ndc, const int & n);


#endif // IOFUNCTS_H_INCLUDED
