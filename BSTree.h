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

#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "drama.h"
//--------------------------  class BinTree  --------------------------------
// ADT BinTree: a tree data structure in which each node (root) has at 
//  most two children(left,right), and each node points to data(Movie).
//
// Implementation and assumptions:
//   -- Implement as a binary search tree
//   -- default constructor set root to NULL
//   -- Implement with following futures: 
//      retireve, getHight
//      makeEmpty, insert, displaySideways
//   -- BinTree doesn't contain duplicate data
//      duplicate  data deletes whithin insert method
//---------------------------------------------------------------------------
class BinTree {

public:
	int movieID;

	BinTree();							   // constructor
	~BinTree();							   // destructor
	void makeEmpty();					   // empty out BinTree
	bool isEmpty() const;                  // true if tree is empty, otherwise false
	Movie * retrieve(const Movie*); // retrive data from BinTree
	bool insertBinary(Movie *);         // recurisve insert
	void displayAll();

private:
	struct Node {
		Movie* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

	//helpers
	void makeEmptyHelper(Node*&);            // helper for makeEmpty()
	void inorderDisplay(Node*) const; // helper for operator<<()
	Movie* retriveBSTreeElement(Node*&, const Movie*) const; // helper for retrive()
	bool insertBinaryHelper(Node*&, Movie*);
};

#endif