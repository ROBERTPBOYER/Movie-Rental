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
#include "drama.h"
#include <sstream>
////--------------------------------------------------------------------------
//// Drama()
//// Constractor
Drama::Drama(const string& str) {
	loadString(str);
}

////--------------------------------------------------------------------------
//// Drama()
//// Copy constractor
Drama::Drama(const string& new_title, const string& new_director) {
	title = new_title;
	director = new_director;
}

////--------------------------------------------------------------------------
//// ~Drama()
//// Destructor
Drama::~Drama() {

}

////-------------------------------------------------------------------------
//// isEqual()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Drama::isEqual(const Movie* rhs) const {
	const Drama* ptr_drama = (const Drama*)rhs;
	return ((title == ptr_drama->title) && (director == ptr_drama->director));
}

////-------------------------------------------------------------------------
//// isGreater()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Drama::isGreater(const Movie* rhs) const {
	const Drama* ptr_drama = (const Drama*)rhs;
	return ((director > ptr_drama->director) || ((director == ptr_drama->director) && (title > ptr_drama->title)));
}

////--------------------------------------------------------------------------
//// printInfo()
//// string type method:
//// compose all inforamtion about the Movie into a string
string Drama::printInfo() const {
	ostringstream stringStream;
	stringStream << setw(21) << left << director << setw(21) << left << title;
	stringStream << setw(9) << right << year << setw(8) << right << stock << endl;
	return stringStream.str();
}

////--------------------------------------------------------------------------
//// printInfoForCustomer()
//// string type method:
//// compose inforamtion about movie with spaccific 
//// format for a customer history.
string Drama::printInfoForCustomer() const {
	ostringstream stringStream;
	stringStream << " drama: " << director << " " << title;
	stringStream << " " << year;;
	return stringStream.str();
}

////-------------------------------------------------------------------------