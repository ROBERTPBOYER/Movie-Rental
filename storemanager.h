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
#ifndef STOREMANAGER_H
#define  STOREMANAGER_H
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "comandloader.h"
//--------------------------  class StoreManager ----------------------------
// ADT StoreManager: Store Manager class: high leve manager for other manager
//  classes such as: CustomerManager, InventoryManager, ComandLoaderManager.
//
// Implementation and assumptions:
//   -- Implement as a manager class
//   -- Implement with following futures:
//      buildStore(), commadnsReader()
//---------------------------------------------------------------------------
class StoreManager {
public:
	void buildStore(ifstream&, ifstream&);               // build store by  creating movie and customer base
	void commandsReader(ifstream&);                      // proccess commands lines
private:
	CustomerManager customer_object;                     // Customer manager object
	InventoryManager inventory_object;                   // Inventroy manager object
	ComandLoader command_object;                         // comands  manager object
};
#endif