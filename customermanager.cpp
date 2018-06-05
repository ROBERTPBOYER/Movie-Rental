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
#include "customermanager.h"

////--------------------------------------------------------------------------
//// CustomerManager()
//// Constractor
CustomerManager::CustomerManager() {

}

////--------------------------------------------------------------------------
//// ~CustomerManager()
//// desctuctor
CustomerManager::~CustomerManager() {

}

////--------------------------------------------------------------------------
//// proccessCustomer()
//// void type method:
//// Read the file and parse into a customer information
//// then, based on the inforamtion insert customer into HashTable.
//// takes one parameter: ifstream refrences file
void CustomerManager::proccessCustomer(ifstream& file) {

	// loop to read the file
	for (;;) {

		int id;                                              // hold id                     
		string last;                                         // hold last name
		string first;                                        // hold first name
		string temp;                                         // hold space

		getline(file, temp, ' ');                            // get id 
		stringstream(temp) >> id;                            // convert id to int 
		getline(file, last, ' ');                            // get last name
		getline(file, first);                                // get first name

		if (file.eof()) break;                               // no more lines of data

		Customer *  ptr = new Customer(id, last, first);    // allocate new customer 
		bool success = table.putCustomer(id, ptr);           // insert customer into HashTable
		if (!success)
			delete ptr;                                     // invalid case, not inserted 
	}
}

////--------------------------------------------------------------------------
//// getCustomer()
//// Pointer to Customer return mehtod:
//// return refrences to a pointer of the object customer, retriveing 
//// customer from hashtable
//// takes one parameter: int id
Customer*  CustomerManager::getCustomer(int id) {
	Customer *  customer = NULL;                   // poitner to a customer
	customer = table.getCustomer(id);              // rertive customer from hashtable
	return customer;                                // return customer
}

////--------------------------------------------------------------------------