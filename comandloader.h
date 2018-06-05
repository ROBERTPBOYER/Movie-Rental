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
#include "movie.h"
#include "inventorymanager.h"
#include  "customermanager.h"
#include "transactionfactory.h"
using namespace std;
//--------------------------  class ComandLoader ----------------------------
// ADT ComandLoader: manager class for proccesesing commands (transaction) 
//  Uses factory patern method for creating transactions.
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with following futures:
//      comandsReader(), displayErrors()
//---------------------------------------------------------------------------
class ComandLoader {
public:

	ComandLoader();                       // constractor  
	virtual ~ComandLoader();              // destractor
	void commandsReader(ifstream&, CustomerManager&, InventoryManager&);  // read commands
	void displayErrors() const;                                           // display errors
private:

	string invalid_transaction;                                           // hold erros
};