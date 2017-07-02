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
	bool isEmpty()
	{
	    return len == 0;
	}
	int getLength()
	{
	    return len;
	}
        bool findItem(K n)
	{
    	    Node * trav = head;
    	    bool found = false;
    	    for(; trav != nullptr; trav=trav->next )
    	    {
		if(trav->val.first == n)
	    	    found = true;
    	    }
    	    return found;   
	}
	V getItem(K n)
	{
    	    Node * trav = head;
    	    for(; trav != nullptr; trav=trav->next )
    	    {
		if(trav->val.first == n)
	    	    return trav->val.second;
    	    }
    	    return nullptr;   
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
	bool deleteItem(K n)
	{
	    Node * trav = head;
    	    Node * trail;
	    if(findItem(n))
	    {
    	        if(trav->val.first == n)
		    head = head->next;
    	        else
    	        {
		    for(trav=trav->next; trav->val.first != n && trav->next != nullptr; trav=trav->next)
	    	        trail = trav;
        	    if(trav->val.first == n)
	    	        trail->next = trav->next;
    	        }
		delete trav;
		--len;
		return true;	
	    }
    	    trav = nullptr;
	    return false;
	}
	void print()
	{   
	    if(len > 0)
	    {
	        for ( Node * p = head; p != nullptr; p = p->next )
		    cout << "key: " << p->val.first << " val: " << p->val.second << endl;
	    }
	    else
		   cout << "the list is empty\n";
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
