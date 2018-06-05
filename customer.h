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
#include "movie.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//--------------------------  class Cusomer  --------------------------------
// ADT Customer: Customer class contains id, first, and last name. Also,
//    customer keeps track of his borrowed and returned movies.
//
// Implementation and assumptions:
//   -- Implement with  two linked lists and vector 
//   -- Implement with following futures: 
//      movieBorrow(), movieReturn() movieHistory(),
//      getMyID(), getCustomerInfo(), addTransaction()
//      returnMovie(), borrowMovie()
//---------------------------------------------------------------------------
class Customer {
public:

	Customer();                    // constractor
	Customer(int, string, string); // copy constrator
	~Customer();                   // destructor
	bool movieBorrow(Movie*);      // borrow movie
	bool movieReturn(Movie*);      // return movie

	void movieHistory();           // print customer borrow and return history
	int getMyID() const;          // return customer ID
	string getCustomerInfo();      // return infomation about customer
private:

	bool addTransaction(const char, Movie*); // add transaction
	bool returnMovie(Movie*);      // private method to check if  return is valid
	bool borrowMovie(Movie*);      // private mehtod to borrow movie into transaction log

	int customer_ID;               // customer id
	string lastName;               // customer last name
	string FirstName;              // customer first name
	int plus_One;                  // integet for increasing movie stock

	// structure for customer history
	struct  List {
		List * next;        // next
		char transaction;   // transaction type (B or R)
		Movie * info;       // pointer to the movie
	};
	List * head;

	vector <string> print_array;    // vector for reverse history print

	// structure for borrow, return history
	struct TransactionLog{
		Movie * movie;         // pointer to the movie
		char transaction;      // transaction type (B or R)
		TransactionLog * next; // nexy
	};
	TransactionLog * logHead;
};