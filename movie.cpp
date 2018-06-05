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
#include "movie.h"
////--------------------------------------------------------------------------
//// Movie()
//// constractor
Movie::Movie() {
	type = ' ';
	stock = 0;
	director = "";
	title = "";
	year = 0;
}

////--------------------------------------------------------------------------
//// loadString()
//// void type method:
//// helper method for constractor. 
//// Pasre the string into a smaller pieces. From these pieces
//// assign inforamtion to a current movie
//// takes one parameter: const stirng refrenseces info.
void Movie::loadString(const string& info) {
	stringstream ss;                 // string reader
	ss << info;                      // insert string info into reader
	string temp;                     //  temp string to parse the string
	getline(ss, temp, ',');          // get movie type
	type = temp[0];                  // assign movie type
	getline(ss, temp, ',');          // get stock
	stringstream(temp) >> stock;  // assign stock
	getline(ss, director, ',');      // assign director
	getline(ss, title, ',');         // assign title
	getline(ss, temp, ',');          // get year
	stringstream(temp) >> year;      // assign year
}

////--------------------------------------------------------------------------
//// increaseStock()
//// bool type method:
//// increase stock of current movie
//// takes one parameter: int addStock
bool Movie::increaseStock(int addToStock) {
	if (addToStock < 0) { return false; }
	stock += addToStock;
	return true;
}

////--------------------------------------------------------------------------
//// getStock()
//// int type method:
//// returns current stock of the movie
int Movie::getStock() {
	return stock;
}

////--------------------------------------------------------------------------
//// dicreaseStock()
//// bool type method:
//// dicrease current stock of the movie
//// if stock is less or equal zero, stock will be the same
bool Movie::dicreaseStock() {
	if (stock <= 0) { return false; }
	stock--;    // dicrease sctock
	return true;
}
////--------------------------------------------------------------------------