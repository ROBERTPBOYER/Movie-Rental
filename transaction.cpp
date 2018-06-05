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
#include "transaction.h"

////--------------------------------------------------------------------------
//// constractor
Transaction::Transaction() {
	errorCollector = "";
}
////--------------------------------------------------------------------------
//// proccessTransaction()
//// void type  method:
/// does nothig (exist for inheretance purpose) 
void Transaction::proccessTransaction(string a, CustomerManager& b, InventoryManager& c)  {
	// do nothig
}
////--------------------------------------------------------------------------
//// checkValidCustomer()
//// bool type method:
//// check  if customer was found or not
//// check the pointer points somewhere
//// takes two parameters: Pointer to Customer customer, int id
bool Transaction::checkValidCustomer(Customer * customer, int id)  {
	if (customer == NULL) {
		ostringstream stringStream;
		stringStream << id;
		addError("Invalid  Customer ID: " + stringStream.str()); // add invalid customer id
		return false;
	}
	return true;
}

////-------------------------------------------------------------------------
//// addErrors()
//// void type method:
//// collect all errors that appears during the command reading 
void Transaction::addError(string error) {
	errorCollector += "* ";
	errorCollector += error;
	errorCollector += "\n";
}

////-------------------------------------------------------------------------
//// getErros()
//// string type method:
//// return the string of all erros that has been detected during file reading
string Transaction::getErrors() {
	return errorCollector;
}

////--------------------------------------------------------------------------