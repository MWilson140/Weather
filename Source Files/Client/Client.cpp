#include "client.h"

void OrganiseFiles(Vector<std::string> & files)
{
    std::map<MetaData, std::string> SortedFiles;
    std::map<MetaData, std::string>::iterator MMIT;
    MetaData CTemp;
    std::string STemp;
    stringstream sstr;
    ifstream File;
    for (int i = 0; i < files.GetLength(); i++)
    {
        try
        {
            File.open(files[i]);
            if(!File)
            {
               throw "File did not open";
            }
            getline(File, STemp); //header line
            getline(File, STemp,',');
            sstr.str(STemp);
            sstr >> CTemp;
            SortedFiles.insert({CTemp,files[i]});
            sstr.clear();
            File.close();
        }
        catch (char const * e)
        {
            std::cout << e;
        }
    }
    files.Empty();
    for(MMIT = SortedFiles.begin(); MMIT !=SortedFiles.end(); MMIT++)
    {
        files.pushBack(MMIT->second);
    }
}

bool menu(const BST<NDC> & myData)
{
    int n;
    const NDC * Result;
    char c = '0'; //make a menu function.
    Collector coll;
    NDC Searcher;
    while (c !='5')
    {
        printMenu();
        try
        {
            fflush(stdin);
            c = getchar();
            switch (c)
            {
            case '1': //year and month
                n = UserYear();
                Searcher.setYear(n);
                Result = myData.smartSearch(Searcher);
                Menu1(Result);
                break;
            case '2': //all months 1 year
                n = UserYear();
                Searcher.setYear(n);
                Result = myData.smartSearch(Searcher);
                Menu2(Result);
                break;
            case '3': //month all years
                n = UserMonth();
                Searcher.setYear(n);
                coll.Destination = &Searcher;
                myData.inorderTrav(coll.CollData);
                Menu3(Searcher);
                Searcher.ClearData();
                break;
            case '4': //file output //all one year
                n = UserYear();
                Searcher.setYear(n);
                Result = myData.smartSearch(Searcher);
                Menu4(Result, n);
                break;
            case '5':
                return true;
                break;
            case '6' :
                return false;
            default:
                std::cout<<"Invalid Menu input"<<endl;
                break;
            }
        }
        catch (const char * e)
        {
            std::cout<< e <<std::endl;
        }
    }
}

void Menu3 (const NDC & Result)
{
    WindProcData WPD;
    AirProcData APD;
    RadProcData RPD;
    int TempYear;
    std::map<MetaData,AllData> Temp = Result.getMap();
    std::map<MetaData,AllData>::iterator IT;
    IT = Temp.begin();
    TempYear = IT->first.date.GetYear();
    for(IT = Temp.begin(); IT != Temp.end(); IT++)
    {
        if (IT->first.date.GetYear() == TempYear)
        {
            WPD.MonthData.pushBack(IT->second.speed);
            APD.MonthData.pushBack(IT->second.ambientAirTemp);
            RPD.MonthData.pushBack(IT->second.solarRadiation);
        }
        else
        {
            printMenu3(WPD, APD, RPD, TempYear);
            TempYear = IT->first.date.GetYear();
            WPD.MonthData.Empty();
            APD.MonthData.Empty();
            RPD.MonthData.Empty();
            WPD.MonthData.pushBack(IT->second.speed);
            APD.MonthData.pushBack(IT->second.ambientAirTemp);
            RPD.MonthData.pushBack(IT->second.solarRadiation);
        }
    }
    printMenu3(WPD, APD, RPD, TempYear);
    WPD.MonthData.Empty();
    APD.MonthData.Empty();
    RPD.MonthData.Empty();
}

void getFiles(std::string fileName, Vector<std::string>& files)
{
    std::string Loc = "Data/";
    std::string temp;
    ifstream File;
    ofstream OFile;
    File.open(fileName);
    if(!File)
        {
            throw "Source file did not open";
        }
    while(getline(File,temp).good())
    {
        fileName = Loc;
        fileName += temp;
        files.pushBack(fileName);
    }
    File.close();
    OFile.open("WindTempSolar.csv");
    if (!OFile)
    {
        throw "Output file did not open";
    }
    OFile.close();
}



