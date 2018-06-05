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
#include "classics.h"
#include <sstream>
////--------------------------------------------------------------------------
//// Classics()
//// constractor
Classics::Classics(const string& str) {
	loadString(str);
}

////--------------------------------------------------------------------------
//// Classics()
//// copy constractor
Classics::Classics(const string& actor, const int& _month, const int& _year) {
	majorActor = actor;
	month = _month;
	year = _year;
}

////--------------------------------------------------------------------------
//// ~Classics()
//// Destructor
Classics::~Classics() {
}

////-------------------------------------------------------------------------
//// isEqual()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Classics::isEqual(const Movie* rhs) const {
	const Classics*  ptr_classic = (const Classics*)rhs;
	return ((majorActor == ptr_classic->majorActor) && (year == ptr_classic->year) && (month == ptr_classic->month));
}

////-------------------------------------------------------------------------
//// isGreater()
//// bool type method:
//// compare current object Movie with other object Movie
//// takes one parameter: const pointer to the object Movie
bool Classics::isGreater(const Movie* rhs) const {
	const Classics*  ptr_classic = (const Classics*)rhs;
	return ((year > ptr_classic->year) || ((year == ptr_classic->year) && (month > ptr_classic->month))
		|| ((year == ptr_classic->year) && (month == ptr_classic->month) && (majorActor > ptr_classic->majorActor)));
}

////--------------------------------------------------------------------------
//// loadString()
//// void type method:
//// helper method for constractor. 
//// Pasre the string into a smaller pieces. From these pieces
//// assign inforamtion to a current movie
//// takes one parameter: const stirng refrenseces info.
void Classics::loadString(const string& info) {
	stringstream ss;
	ss << info;
	string temp;                 // hold sub string from info string
	getline(ss, temp, ',');      // get type of movie (char)
	type = temp[0];
	getline(ss, temp, ',');      // get stock number (int)
	stringstream(temp) >> stock;
	getline(ss, director, ',');  // get director string
	getline(ss, title, ',');     // get title string
	ss >> temp;                  // add second name to first name
	majorActor += temp;
	majorActor += ' ';
	ss >> temp;                 // add second name to first name
	majorActor += temp;
	ss >> month;                // add month
	ss >> year;                 // add month
}

////--------------------------------------------------------------------------
//// printInfo()
//// string type method:
//// compose all inforamtion about the Movie into a string
string  Classics::printInfo() const {
	ostringstream stringStream;
	stringStream << " " << setw(7) << left << month << setw(6) << left << year <<
		setw(18) << left << majorActor << setw(23) << left <<
		title << setw(17) << left << director << setw(5) << left << stock << endl;
	return  stringStream.str();

}

////--------------------------------------------------------------------------
//// printInfoForCustomer()
//// string type method:
//// compose inforamtion about movie with spaccific 
//// format for a customer history.
string Classics::printInfoForCustomer() const {
	ostringstream stringStream;
	stringStream << " classic: " << month << " " << year << ' ' << majorActor << title << director;
	return  stringStream.str();
}

////-------------------------------------------------------------------------