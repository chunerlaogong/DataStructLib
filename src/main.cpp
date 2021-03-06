#include "SmartPointer.h"
#include "Exception.h"
#include "List.h"
#include "SeqList.h"
#include "StaticList.h"
#include "StaticLinkList.h"
using namespace YJDLib;

int main(int argc, char** argv)
{
    /*SmartPointer<int> *sp = new SmartPointer<int>();
    delete sp;
    InvalidOperationException *e = new InvalidOperationException();
    delete e;
    List<int> *list = NULL;
    SeqList<int> *seqList = NULL;*/

    /*StaticList<int, 5> staticList ;//= new StaticList<int, 5>();
    for(int i = 0; i < staticList.capacity(); i++)
    {
        staticList.insert(0, i);
    }
    for(int i = 0; i < staticList.length(); i++)
    {
        staticList[i] *= staticList[i];
        cout << staticList[i] << "," ;
    }*/
   /* try
    {
        staticList[5] = 10;
    }
    catch(Exception& e)
    {
        cout<< e.message() << endl;
        cout<< e.location() << endl;
    }
    cout << staticList[5] <<endl;*/
    //const StaticList<int, 2> staticList1;
   // staticList1.insert(0, 20);
   // staticList[0] = 20;
   // cout << staticList1[0] << endl;
    StaticLinkList<int, 5> staticLinkList;
    for(int i = 0; i < 5; i++)
    {
        staticLinkList.insert(0, i);
    }
    try{
        staticLinkList.insert(6);
    }catch(const Exception& e)
    {
        cout << e.message() << endl;
    }
    
    for(staticLinkList.move(0); !staticLinkList.end(); staticLinkList.next())
    {    
        cout << staticLinkList.current() << endl;
    }
}