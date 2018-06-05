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
#include "comedy.h"
////--------------------------------------------------------------------------
//// Comedy()
//// Constractor
Comedy::Comedy(const string& str) {
	loadString(str);
}

////--------------------------------------------------------------------------
//// Comedy()
//// Copy constractor
Comedy::Comedy(const string& new_title, const int& new_year) {
	title = new_title;
	year = new_year;
}

////--------------------------------------------------------------------------
//// ~Comedy()
//// Destructor
Comedy::~Comedy() {

}

////-------------------------------------------------------------------------
//// isEqual()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Comedy::isEqual(const Movie* rhs) const {
	const Comedy* ptr_comedy = (const Comedy*)rhs;
	return ((title == ptr_comedy->title) && (year == ptr_comedy->year));
}
////-------------------------------------------------------------------------
//// isGreater()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Comedy::isGreater(const Movie* rhs) const {
	const Comedy* ptr_comedy = (const Comedy*)rhs;
	return ((title > ptr_comedy->title) || ((title == ptr_comedy->title) && (year > ptr_comedy->year)));
}
////--------------------------------------------------------------------------
//// printInfo()
//// string type method:
//// compose all inforamtion about the Movie into a string
string Comedy::printInfo() const {
	ostringstream stringStream;
	stringStream << setw(33) << left << title << setw(1) << right << year
		<< setw(20) << left << director << setw(20) << left << stock << endl;
	return stringStream.str();
}

////--------------------------------------------------------------------------
//// printInfoForCustomer()
//// string type method:
//// compose inforamtion about movie with spaccific 
//// format for a customer history.
string Comedy::printInfoForCustomer() const {
	ostringstream stringStream;
	stringStream << " comedy: " << title << " " << director
		<< " " << year;;
	return stringStream.str();
}

////-------------------------------------------------------------------------