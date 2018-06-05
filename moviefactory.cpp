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
#include "moviefactory.h"
////-------------------------------------------------------------------------
//// MovieFactory()
//// static method returns the pointer to a Movie object
//// takes one parameter: const string refrences a
Movie * MovieFactory::createMovie(const string& a) {
	Movie *  movie = NULL;               //  pointer to movie
	switch (a[0])    // get first character of  string array
	{
	case Drama::MyType:
		movie = (Movie*) new Drama(a);  // create Drama
		break;
	case Comedy::MyType:
		movie = (Movie*) new Comedy(a);  // create Comedy
		break;
	case Classics::MyType:
		movie = (Movie*) new Classics(a); // create Classics
		break;
	default:
		movie = NULL;                     // NULL

		break;
	}
	return movie;                          // return movie
}

//////-------------------------------------------------------------------------