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
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
using namespace std;
//--------------------------  class Transaction -----------------------------------
// ADT Transcation: Class Transaction. parent  class for child classes Borrow,
// Rerurn, Inventory, Hisory. Also, records erros and adds erros into string
//
// Implementation and assumptions:
//   -- Implement as a perant class
//   -- Implement with following futures:
//      proccessTransaction() getErorrs()
//---------------------------------------------------------------------------
class Transaction {
public:
	Transaction();              // constractor
	virtual ~Transaction() {};  // destructor
	virtual void proccessTransaction(string, CustomerManager&, InventoryManager&); // proccess command
	string getErrors();                                                            // return arrors massages
	static const char DVD = 'D';                                                   // shared by all transactions
protected:
	bool checkValidCustomer(Customer*, int);           // check if customer is valid
	string errorCollector;                             // string that hold all type of errors during reading the commands
	void addError(string);                             // add erros from all comands mistakes	
};