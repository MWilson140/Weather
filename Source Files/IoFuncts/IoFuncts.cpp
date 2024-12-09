#include "IOFuncts.h"


std::istream & operator >> (std::istream & input, Vector<string> & IF) //only for first lines
{
    std::string temp;
    getline(input, temp);
    stringstream sstr(temp);
    while (getline(sstr,temp,','))
    {
        IF.pushBack(temp);
    }
    return input;
}
void SetAllData(Vector<std::string> & inData, AllData & WD, InputConfig & InCon)
{
    try
    {
        WD.speed = (stof(inData[InCon.NewKey[11]]));
    }
    catch (...)
    {
        WD.speed = -999.0;
    }
    try
    {
        WD.ambientAirTemp = (stof(inData[InCon.NewKey[1]]));
    }
    catch (...)
    {
        WD.ambientAirTemp = -999.0;
    }
    try
    {
        WD.solarRadiation = (stof(inData[InCon.NewKey[12]]));
    }
    catch (...)
    {
        WD.solarRadiation = -999.0;
    }
}

std::stringstream & operator >> (std::stringstream & input, MetaData & MD)
{
    string temp;
    try
    {
        getline(input, temp, ' ');
        MD.date.SetUsingString(temp);
        getline(input, temp, ',');
        MD.time.SetUsingString(temp);
    }
    catch (...)
    {
        throw "Invalid Meta Data";
    }
    return input;
}

int UserMonth()
{
    fflush(stdin);
    std::string temp;
    int month;
    std::cout<<"Enter the Month: ";
    std::cin>>temp;
    try
    {
        month = stoi(temp);
        if(month < 1 || month > 12)
            throw "Invalid input";
    }
    catch (...)
    {
        throw "invalid input";
    }
    return month;
}

int UserYear()
{
    fflush(stdin);
    string temp;
    int year = 0;
    std::cout<<"Enter the year: ";
    std::cin>>temp;
    try
    {
       year = stoi(temp);
    }
    catch (std::invalid_argument)
    {
        throw "Non valid input";
    }
    return year;
}

void ReadFiles(Vector<std::string> & files, BST<NDC> & myData)
{
    InputConfig InCon;
    InCon.SetInput();
    Vector<string> fileInput(numInputs);
    ifstream FileIn;
    std::string Temp;
    stringstream sstr;
    MetaData metaData;
    AllData data;
    NDC ndc;
    for(int i = 0; i < files.GetLength(); i++)
    {
        FileIn.open(files[i]);
        if (!FileIn)
        {
            throw "File did not open";
        }
        std::cout<<files[i] << std::endl;
        FileIn >> fileInput;
        InCon.SetKey(fileInput);
        fileInput.Empty();
        while(getline(FileIn, Temp).good())
        {
                sstr.clear();
                sstr.str(Temp);
                while(getline(sstr, Temp,','))
                {
                    fileInput.pushBack(Temp);
                }
                sstr.clear();
                sstr.str(fileInput[0]);
                try
                {
                    sstr >> metaData;
                    SetAllData(fileInput, data, InCon);
                    if(!ndc.addData(metaData, data))
                    {
                        myData.Insert(ndc);
                        ndc.ClearData();
                        ndc.addData(metaData, data);
                    }
                }
                catch (const char * e)
                {
                    std::cout<<e << std::endl;
                }
                fileInput.Empty();
        } //while not eof
        FileIn.close();
    } //end of files
    if (ndc.getYear() !=0)
    {
        myData.Insert(ndc);
        ndc.ClearData();
    }
}
void printMenu()
{
        std::cout<<"1) Average Wind Speed." <<std::endl
        << "2) Average Ambient Air Temperature." <<std::endl
        <<"3) Pearson." << std::endl
        <<"4) Print to File." << std::endl
        << "5) Reset" << std::endl
        <<"6) Exit" << std::endl;
}

void Menu1 (const NDC * Result) //years worth of data.
{
    if(!Result)
    {
       std::cout<< "no Data" << std::endl;
       return;
    }
    int n;
    try
    {
        n = UserMonth();
    }
    catch (const char * e)
    {
        std::cout<< e << std::endl;
        return;
    }
    WindProcData WPD;
    WPD.NGetData(*Result, n);
    try
    {
        std::cout<< Months[n-1] << " " << Result->getYear() << std::endl;
        std::cout << "Average Speed: " << CalcMean(WPD.MonthData)
        << " km/h" << std::endl;
        std::cout << "Sample stdev: " << CalcStdDev(WPD.MonthData) << std::endl;
    }
    catch (...)
    {
        std::cout<<"No data" << std::endl;
    }
}

void Menu2 (const NDC * Result)
{
    AirProcData APD;
    if (!Result)
    {
        std::cout<<"No Data" << std::endl;
        return;
    }
    for(int i = 1; i < 13; i++)
    {
        APD.NGetData(*Result, i);
        std::cout<< Months[i-1] << ": ";
        try
        {
            std::cout<< CalcMean(APD.MonthData) << " Degress C, stdev:"
            << CalcStdDev(APD.MonthData) <<std::endl;
        }
        catch (...)
        {
            std::cout<<"No Data" << std::endl;
        }
        APD.MonthData.Empty();
    }
}

void printMenu3(const WindProcData & WPD, const AirProcData & APD, const RadProcData & RPD, const int & Year)
{
    try
    {
        std::cout<<Year << std::endl;
        std::cout<< "S_T: " << sPCC(WPD.MonthData, APD.MonthData) << std::endl;
    }
    catch (const char * e)
    {
        std::cout << e <<std::endl;
    }
    try
    {
       std::cout<< "S_R: " << sPCC(WPD.MonthData, RPD.MonthData) << std::endl;
    }
    catch (const char * e)
    {
        std::cout << e << std::endl;
    }
    try
    {
        std::cout<< "T_R: " << sPCC(APD.MonthData, RPD.MonthData) << std::endl;
    }
    catch (const char * e)
    {
        std::cout << e << std::endl;
    }
}

void Menu4 (const NDC * Result, const int & n) //change this, user specified year!!!
{
    ofstream FileOut;
    FileOut.open("WindTempSolar.csv", ios::app);
    FileOut<< n << std::endl;
    if(!Result)
    {
        FileOut << "No Data found" << std::endl;
        return;
    }
    WindProcData WPD;
    AirProcData APD;
    RadProcData RPD;
    for (int i = 1; i < 13; i++) //for loop for all the data.
    {
        WPD.NGetData(*Result, i);
        APD.NGetData(*Result, i);
        RPD.NGetData(*Result, i);
        RPD.calcRad();
        if(!(WPD.MonthData.IsEmpty() && APD.MonthData.IsEmpty() && RPD.MonthData.IsEmpty()))
        {
            FileOut << Months[i-1] << ",";
            try
            {
                FileOut<<CalcMean(WPD.MonthData) << "("
                << CalcStdDev(WPD.MonthData) << ")";
            }
            catch (const char * e)
            {
                std::cout<< e << std::endl;
            }
            FileOut<<",";
            try
            {
                FileOut << CalcMean(APD.MonthData) << "("
                << CalcStdDev(APD.MonthData) << ")";
            }
            catch (const char * e)
            {
                std::cout<< e << std::endl;
            }
            FileOut <<",";
            try
            {
               FileOut << CalcTotal(RPD.MonthData);
            }
            catch (const char * e)
            {
                std::cout<< e << std::endl;
            }
            FileOut << std::endl;
        }
        WPD.MonthData.Empty();
        APD.MonthData.Empty();
        RPD.MonthData.Empty();
    }
}


