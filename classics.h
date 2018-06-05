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
#include "movie.h"
using namespace std;
//--------------------------  class Classics --------------------------------
// ADT Classics: child class of Movie. Classical movie has extra info:
// month and majorActor. Also, classical movie sort by majoractor, month,
// and year.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      printInfo(), printInfoForCustomer(), isEqual(), isGreater()
//   -- Assumption: each Classics movie that has same director, same
//      title, same year and month, but has different Major will be 
//      considirate as a diffrent  classic movie.
//---------------------------------------------------------------------------
class Classics : public Movie {
public:

	Classics(const string&);                            // copy constractor
	Classics(const string&, const int&, const int&);    // copy constractor
	virtual ~Classics();                                // destructor

	static const char MyType = 'C';                     // static indentifier for a class             

	virtual string printInfoForCustomer() const;        // return string ifno for customer
	virtual string printInfo() const;                   // return string of full movie  info

protected:

	void loadString(const string&);                     // helper method for reading info
	virtual bool isEqual(const Movie* rhs) const;       // operator=
	virtual bool isGreater(const Movie* rhs) const;     // operator>=

	int month;                                          // hold month                                
	string majorActor;                                  // hold majorActor
};