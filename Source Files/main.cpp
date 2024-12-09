#include <string>
#include "Client/client.h"
#include "Vector/Vector.h"
#include "IoFuncts/IOFuncts.h"
#include "NDC/NDC.h"
#include "BST/BST.h"
#include "Collector/Collector.h"

//static pointer to a NDC object inside the collector class.
//no data is stored inside a static variable, only location of where to store the data.
NDC * Collector::Destination = nullptr;

using namespace std;
int main()
{
    try
    {
        BST<NDC> myData;
        Vector<string> files;
        bool cont = true;
        while (cont == true)
        {
            getFiles("DataSource.txt", files);
            OrganiseFiles(files);
            ReadFiles(files, myData);
            cont = menu(myData);
            myData.deleteTree();
            files.Empty();
        }
    }
    catch (char const * e)
    {
        std::cout << e;
    }
}
