#include "LList.h"
#include <string>
class HashTable
{
  private:
    LList<int,string> * head;
    int len;
  public:
    void clear();
    bool containsValue(string val);
    bool containsKey(int key);
    string get(int key);
    bool isEmpty();
    void put(int key, string val);
    void remove(int key);
    int size();
    void print();
    int hash(int key);
}
;
