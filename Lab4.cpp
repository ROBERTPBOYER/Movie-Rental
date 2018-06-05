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
using namespace std;


//---------------------------------------------------------------------------
// lab4.cpp
//---------------------------------------------------------------------------
// This code tests the basic functionality of the classes to perform
// Dijkstra's algorihms and depth-first search for CSS 343 Lab 3.
// It is not meant to exhaustively test the class. 
//
// Assumptions:
//   -- students can follow the directions to interface with this file
//   -- text files "data31.txt" and "data32.txt" are formatted as described 
//   -- Data file data3uwb provides an additional data set for part 1;
//      it must be edited, as it starts with a description how to use it
//---------------------------------------------------------------------------
////-------------------------------------------------------------------------
//// main class. Checks for valid data files.
//// Invokes StoreManager to proccess data files.
int main() {
	ifstream infile1("data4movies.txt");
	if (!infile1) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	ifstream infile2("data4commands.txt");
	if (!infile2) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	ifstream infile3("data4customers.txt");
	if (!infile3) {
		cout << "File could not be opened." << endl;
		return 1;
	}

	StoreManager store;                   // allocate store
	store.buildStore(infile1, infile3);   // proccess movies and customers
	store.commandsReader(infile2);        // proccess commanads
	return 0;
}