#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include <utility>
#include <string>
#define LIST_MAX 100

using namespace std;

template
< typename K, typename V >
class LList
{
    public:
	LList()
	{
	    head = nullptr;
    	    len = 0;
	}
	~LList()
	{
    	    Node * temp;
    	    while (head != nullptr)
    	    {
	        temp = head;
		head = head->next;
		delete temp;
    	    }
            head = nullptr;
	}
	void makeEmpty()
	{ 
    	    Node * temp;
            while (head != nullptr)
    	    {
		temp = head;
		head = head->next;
		delete temp;
    	    }
    	    head = nullptr;
    	    len = 0;
	}
	bool isFull()
	{
    	    return len == LIST_MAX;
	}
	int getLength()
	{
	    return len;
	}
        V getItem(K n, bool & found)
	{
    	    Node * trav = head;
    	    found = false;
    	    V value;
    	    for(; trav != nullptr; trav=trav->next )
    	    {
		if(trav->val.first == n)
		{
	    	    value = trav->val.second;
	    	    found = true;
		}
    	    }
    	    return value;   
	}
	void putItem(K n, V val)
	{
	    Node * trav;
    	    Node * newNode;
    
    	    if ( ! isFull() )
    	    {    

        	newNode = new Node;
        	newNode->val.first = n;
		newNode->val.second = val;
        	newNode->next = nullptr;    

        	trav = head;
        	if(trav == nullptr)
	    	head = newNode;
        	else
        	{
            	    while(trav->next != nullptr)
	        	trav = trav->next;
            	    trav->next = newNode;
        	}
        	++len;
    	    }
    	    else
		cout << "the list is full\n";
	}
	void deleteItem(K n)
	{
	    Node * trav = head;
    	    Node * trail;
    	    if(trav->val.first == n)
    	    {
		head = head->next;
		delete trav;	
    	    }
    	    else
    	    {
		for(trav=trav->next; trav->val.first != n && trav->next != nullptr; trav=trav->next)
	    	    trail = trav;
        	if(trav->val.first == n)
		{
	    	    trail->next = trav->next;
	    	    delete trav;
		} 
    	    }
    	    trav = nullptr;
	}
	void print()
	{
	    for ( Node * p = head; p != nullptr; p = p->next )
	    {
		cout << p->val.first << endl;
	    }
	}
    private:
	struct Node {
	    pair<int, string>  val;
	    Node * next;
	};
	Node * head;
	int len;	
};

#endif
