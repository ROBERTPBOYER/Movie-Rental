/*                                                                                                              #THE KILLER BUNNY
Robert Boyer                                                                                                         (\_/)
CSS 343 (Fall 2015)                                                                                                  (o o)
-------------------------------------------------------------------------------------------------------------       (     )
Creation Date: 12/13/2015
Date of Last Modification: 12/18/2015
--------------------------------------------------------------------------------------------------------------------------------
Purpose: Assignment to help a movie rental store automate their inventory tracking system.
--------------------------------------------------------------------------------------------------------------------------------
Notes:	There are 3 types of movies (Comedy, Drama, & Classics). Classics movie information format differs from Drama/Comedy when
reading in data4movies.txt. Each movie type are sorted differently in the system. Comedy: Title, then year released.
Drama: Director, then title. Classics: Release date, then Major actor.

Customers have unique 4-digit ID number along with their last/first name. Read in from data4customers.txt for data.
Users can choose between 4 types of commands:(Borrow) movie, (Return) movie, display their (History), or display store (Inventory).
Read in from data4commands.txt for customer transactions/commands.
--------------------------------------------------------------------------------------------------------------------------------
*/
#pragma once 
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
using namespace std;
// class hashtable
// chain model hashtable
// assumption: do not allowed duplicate customer (identical id)
// customer base up to 25 
//--------------------------  class HashTable  ------------------------------
// ADT HushTable: HashTable class: HashTable (chain model) data stucture
//      that holds customers. Proviedes easy access to a customer by (id)
//
// Implementation and assumptions:
//   -- Implement as  closed HashTable (chain model) by using linked list
//       at each index of the table
//   -- Implement with following futures: 
//      getCustomer(), putCustomers()
//   -- Assumption: HashTble assumed only 25 customer in the Table
//---------------------------------------------------------------------------
class HashTable {
	static const int SIZE = 50; // twice size of customer base
	static const int Hash = 52;          // number for hashing
public:
	HashTable();   // constractor
	~HashTable();  // descturctor
	Customer * getCustomer(int);       // return pointer  to the object customer
	bool putCustomer(int, Customer *); // insert customer into hashtable
private:
	void makeEmpty();  // helper method to distructor
	void buildTable(); // helper method for constractor

	struct HashList;   // structure for linkned list at hashtable index
	struct HashEntry   // hashtable  structure
	{
		HashList * head;
	};

	struct HashList   // linked list that attached to index of table
	{
		Customer * data;   //  hold customer
		int key;           // hold ID  (key)
		HashList * next;   // next
	};

	HashEntry table[SIZE];   // hastable array
};