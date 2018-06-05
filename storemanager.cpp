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
#include <iostream>
#include <fstream>
#include "storemanager.h"
////--------------------------------------------------------------------------
//// buildStore()
//// void type method:
//// invokes inventory and customer manager to build data base
//// for movie and customters
//// takes two parameters: ifstream refrences movie_DB,
//// ifstream refrences customer_DB.
void StoreManager::buildStore(ifstream& movie_DB, ifstream& customer_DB) {
	inventory_object.processInventory(movie_DB);
	customer_object.proccessCustomer(customer_DB);
}

////--------------------------------------------------------------------------
//// commnadsReader()
//// void type method:
//// invokes ComandLoader  (command_object) to read commamands
//// takes one paramter: ifstream refrences commands
void StoreManager::commandsReader(ifstream& commands) {
	command_object.commandsReader(commands, customer_object, inventory_object);
}

////--------------------------------------------------------------------------