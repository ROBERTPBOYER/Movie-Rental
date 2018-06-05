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
#include "hashtable.h"
////--------------------------------------------------------------------------
//// HashTable()
//// Constractor
HashTable::HashTable() {
	buildTable();
}

////--------------------------------------------------------------------------
//// buildTable()
//// void type method:
//// helper method for constractor
//// initizilized all header at all table's indexes to null
void HashTable::buildTable() {
	for (int i = 0; i < SIZE; ++i) {
		table[i].head = NULL;
	}
}

////--------------------------------------------------------------------------
//// ~HashTable()
//// Desctuctor
HashTable::~HashTable() {
	makeEmpty();
}

////--------------------------------------------------------------------------
//// makeEmpty()
//// void type method:
//// helper method for distructor.
//// Delete all linked list at all indexes of hashtable
void HashTable::makeEmpty() {
	for (int i = 0; i < SIZE; ++i) {
		if (table[i].head != NULL) {
			HashList* del = table[i].head;             // hold del at head
			// loop until the last node
			while (table[i].head != NULL) {
				table[i].head = table[i].head->next;   // moove head
				delete del->data;                      // delete customer
				delete del;                            // delete node
				del = NULL;
				del = table[i].head;	               // assing del to head
			}
		}
	}
}

////--------------------------------------------------------------------------
//// putCustomer()
//// bool type method:
//// find hash number for a customer  and
//// insert customer pointer to the HashTable
//// does it as closed (chain model) hasing
//// takes two parameters: int key, Pointer to a Customer customer
bool HashTable::putCustomer(int key, Customer * customer) {

	if (key > 9999 || key < 0) {         // over size
		return false;
	}
	// prime number 59 ?
	int hash = (key % Hash);             // assign hash

	HashList * node = new HashList;      // node that hold customer
	node->data = customer;               // point to customer
	node->key = key;                     // point to key
	node->next = NULL;                   // next null

	// check if the index is empty
	if (table[hash].head == NULL) {
		node->next = table[hash].head;
		table[hash].head = node;
	} // more than one nodes 
	else {
		HashList * current = table[hash].head;
		while (current->next != NULL) {
			// check if duplicate 
			if (key == current->key) {
				delete node->data;      // delete customer
				delete node;            // delete pointer
				node = NULL;
				return false;
			}
			current = current->next;
		}
		current->next = node; // add to the list
	}
	return true;
}

////--------------------------------------------------------------------------
//// getCustomer()
//// Pointer to a Customer type method:
//// return pointer to the  object customer
//// find  hash (index) in the HashTable. If nessary,
//// triverse likned list at hash (index) and return poiter.
//// takes one parameter: int key
Customer * HashTable::getCustomer(int key) {

	if (key > 9999 || key < 0) {             // over size
		return NULL;
	}

	int hash = (key % Hash);                // assign hash

	if (table[hash].head == NULL) {         // no customer at index
		return NULL;
	}
	else {
		HashList * node = table[hash].head; // traves linked list until found 
		while (node != NULL) {
			if (key == node->key) {         // found
				return node->data;
			}
			node = node->next;
		}
	}
	return NULL;                           // not found
}

////--------------------------------------------------------------------------