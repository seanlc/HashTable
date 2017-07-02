#include <iostream>
#include <string>
#include "LList.h"
#include "HashTable.h"

using namespace std;

int main()
{
/*
    LList<int,string> myList;
    for(int i = 0; i < 100; ++i)
        myList.putItem(i, to_string(i*2));
    myList.print();
    cout << "head deletion\n";
    myList.deleteItem(0);
    myList.print();
    cout << "middle deletion\n";
    myList.deleteItem(50);
    myList.print();
    cout << "tail deletion\n";
    myList.deleteItem(99);
    myList.print();
    myList.deleteItem(500);
*/
    
    string returnStr  = "";
    HashTable myTable(37);
    myTable.put(66666, "devil");
    myTable.put(12345, "test");
    myTable.print();
    if(myTable.containsKey(1222))
	cout << "found key\n";
    else
	cout << "did not find key\n";
    returnStr = myTable.get(666);
    cout << "key returned: " << returnStr << endl;
//    myTable.remove(12345);
//    myTable.print();

    return 0;
}
