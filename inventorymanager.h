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
#include "movie.h"
#include "BSTree.h"
#include "moviefactory.h"
//--------------------------  class InventoryManager ------------------------
// ADT InventoryManager: Read given file then sort and insert
//    movies to a spacific BSTrees (Drama,Classiscs, Comedy). 
//    Also, displays all BTrees and keep track of invalid movies. 
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with using factory pattern:
//      MovieFactory class.
//   -- Implement with following futures:
//      proccessInvetory(), retriveMovie(), displayAll()
//---------------------------------------------------------------------------

class InventoryManager {
public:
	void processInventory(ifstream &);                 // proccess invetory
	Movie * retriveMovie(Movie*, char);                // retrive movie from BSTtree
	void displayAll();
private:
	void addError(string);                             // add erros from all invalid movie
	void displayErrors() const;                        // displays all invalid movies that has been detected

	int count;                                         // count error massages
	string errorCollector;                             // error collector
	BinTree dramaBST;                                  // BStrees for drama movies
	BinTree classicsBST;                               // BStrees for classics movies
	BinTree comedyBST;                                 // BStrees for comedy movies
};