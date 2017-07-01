#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LList.h"
#include <string>

using namespace std;

class HashTable
{
  private:
    LList<int,string> * head;
    int len;
  public:
    HashTable()
    : head (new LList<int,string> [100]), len (100)
    {}
    HashTable(int numBuckets)
    : head (new LList<int,string> [numBuckets]), len (numBuckets)
    {}
    ~HashTable()
    {
	delete [] head;
	head = nullptr;
    }
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

#endif
