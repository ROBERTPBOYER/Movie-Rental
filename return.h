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
#include "transaction.h"
using namespace std;

//-------------------------------------------------------- [Class Return] ------------------------------------------------------
// Description: 
// (Type of Customer Transaction/Command). Is a child class that inherits from the Transaction Class. When a customer returns a 
// movie the inventoryService updates movie inventory/stock.   
//------------------------------------------------------------------------------------------------------------------------------
class Return : public Transaction {
public:
	Return();                                                                                  //Default Constructor
	~Return();                                                                                 //Destructor
	static const char MyType = 'R';                                                            //Static Indentifier for this class
	virtual void proccessTransaction(string, CustomerManager&, InventoryManager&);             //Proccess Transaction

protected:
	void proccessReturn(Customer*, Movie*, Movie*);                                            //Helper method for processTransaction()
	void readTransaction(string info, Customer* customer, InventoryManager& inv_mang);         //Helper method for processTransaction()
};