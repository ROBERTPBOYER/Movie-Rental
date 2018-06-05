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
#include "history.h"
////--------------------------------------------------------------------------
//// History()
//// Constractor
History::History() {
	errorCollector = "";
}

////--------------------------------------------------------------------------
//// ~History()
//// Destructor
History::~History() {

}

////--------------------------------------------------------------------------
//// proccessTransaction()
//// void type method:
//// read the line. From the line gets customer ID
//// tries to retrive the customer, if customer exist - 
//// prints customer hsitory
//// takes three parameter: sting line, CustomerManager refrences cus_mang,
//// InventoryManager refrences inv_mang
void History::proccessTransaction(string line, CustomerManager& cus_mang, InventoryManager& inv_mang) {

	int customer_id;            // hold customer id
	Customer * customer = NULL; // hold pointer to the object customer

	stringstream ss;            // string reader
	ss << line;                 // insert string into reader

	ss >> customer_id;
	customer = cus_mang.getCustomer(customer_id);     // get pointer to the customer
	if (checkValidCustomer(customer, customer_id)) {  // check if customer exist
		customer->movieHistory();                     // print customer history
	}
}