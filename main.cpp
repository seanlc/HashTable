#include <iostream>
#include <string>
#include "LList.h"
#include "HashTable.h"

using namespace std;


int main()
{
    HashTable myTable(37);
    myTable.put(66666, "devil");
    myTable.put(12345, "test");
    myTable.print();

    return 0;
}
