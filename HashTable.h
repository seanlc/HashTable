#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LList.h"
#include <string>
#include <utility>

using namespace std;

class HashTable
{
  private:
    LList<int,string> * buf;
    int numEle;
    int numBuck;
  public:
    HashTable()
    : buf (new LList<int,string> [100]), numEle (0), numBuck (100)
    {}
    HashTable(int numBuckets)
    : buf (new LList<int,string> [numBuckets]), numEle (0), numBuck (numBuckets)
    {}
    ~HashTable()
    {
	delete [] buf;
	buf = nullptr;
    }
    void clear()
    {
	for(int i = 0; i < numBuck; ++i)
	{
	    if(! buf[i].isEmpty() )
		buf[i].makeEmpty();
	}
    }
    bool containsValue(string val);
    bool containsKey(int key);
    string get(int key);
    bool isEmpty()
    {
	return numEle == 0;
    }
    void put(int key, string val)
    {
	int hashedIndex = hash(key);
	buf[hashedIndex].putItem(key,val);
	++numEle;	
    }
    void remove(int key);
    int size()
    {
	return numEle;
    }
    void print()
    {
	cout << "HashMap Contents\n";
	for(int i = 0; i < numBuck; ++i)
	{
	    cout << "bucket: " << i << " numEle: " << buf[i].getLength() << endl;
	    buf[i].print();
	}
    }
    int hash(int key)
    {
	return key % numBuck;
    }
}
;

#endif
