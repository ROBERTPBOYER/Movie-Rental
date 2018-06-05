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

//class Movie
//base class for Comedy, Drama, and Classics
#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//--------------------------  class Movie -----------------------------------
// ADT Comedy: abstract class Movie. Abstact class for child classes Drama,
// Comdedy, Classiscs. Can not be created. Used only for inheretance purpose.
// General movie contains information about title, director, year, and stock.
//
// Implementation and assumptions:
//   -- Implement as a abstract class
//   -- Implement with following futures:
//      printInfo(), printInfoForCustomer(), isEqual(), isGreater()
//---------------------------------------------------------------------------
class Movie {
public:

	virtual ~Movie() {};                // destructor
	virtual bool isEqual(const Movie* rhs) const = 0;   // pure virtual isEqual operator
	virtual bool isGreater(const Movie* rhs) const = 0; // pure virtual	isGreater operator
	virtual string printInfo() const = 0;               //  pure virtual printInfo
	virtual string printInfoForCustomer() const = 0;    // pure virtual printInfoForCustomer
	virtual bool increaseStock(int);    // increase stock
	virtual bool dicreaseStock();       // decrease stock
	virtual int getStock();             // return current stock

protected:

	Movie();                            // constractor (protected) to avoid diclaration of the object
	void loadString(const string&);     // helper mehtod for copy constractor

	//movie data
	char type;                          // hold type
	int stock;                          // hold stock
	string director;                    // hold director
	string title;                       // hold title
	int year;                           // hold year

};
#endif