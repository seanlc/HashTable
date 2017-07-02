#include <iostream>
#include <string>
#include "LList.h"
#include "HashTable.h"

using namespace std;

int main()
{
/*
    LList<int,string> myList;
    int n = 98;
    bool found = false;
    string getRes = "";
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
    getRes = myList.getItem(n,found);
    cout << "item " << n << " has key: " << getRes << endl;
*/

    HashTable myTable(37);
    myTable.put(66666, "devil");
    myTable.print();

    return 0;
}
