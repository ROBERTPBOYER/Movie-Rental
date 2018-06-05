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
#include "inventorymanager.h"
////-------------------------------------------------------------------------
//// InventoryManager()
//// void type method:
//// Proccess file  line by line. Send each line to the moviefactory
//// where creates different objects of Moive
//// after, the objects will be insreted to a spacific BSTree
//// if object are unkonw types, add it to error histroy
//// takes one parameter: ifstream refrences inflie
void InventoryManager::processInventory(ifstream& infile) {

	count = 0;                                    // counts unkonw movies
	string s;                                     // hold movie information

	for (;;) {

		getline(infile, s);                       // inser info into string
		if (infile.eof()) break;                  // no more lines of data

		Movie* a = MovieFactory::createMovie(s);  // pointer to the object movie

		switch (s[0])                             // check what object type to insert curent movie
		{
		case Drama::MyType:
			dramaBST.insertBinary(a);             // insert Drama movie
			break;
		case Comedy::MyType:
			comedyBST.insertBinary(a);            // insert Comedy movie
			break;
		case  Classics::MyType:
			classicsBST.insertBinary(a);          // insert Classics movie
			break;
		default:
			addError(s);                          // add unkown movie
			break;
		}
	}
	displayErrors();                              // display errors 
}
////-------------------------------------------------------------------------
//// retrieveMovie()
//// Pointer to a Movie method type:
//// retrive Movie from appropriate BSTree 
//// using its type.
//// takes two parameters: Pointer to Movie temp, char type
Movie* InventoryManager::retriveMovie(Movie* temp, char type)  {
	// use swith case to find appropriate Tree
	switch (type)
	{
	case 'D':
		return dramaBST.retrieve(temp);
		break;
	case 'F':
		return comedyBST.retrieve(temp);
		break;
	case 'C':
		return classicsBST.retrieve(temp);
		break;
	default:
		break;
	}
	return NULL;
}

////-------------------------------------------------------------------------
//// displayAll()
//// void type method:
//// display all BSTree (Comedy,Drama,Classics).
void InventoryManager::displayAll() {
	cout << endl;
	cout << "=============================================================================" << endl;
	cout << "                                Display Comedies " << endl;
	cout << "=============================================================================" << endl;
	cout << " Title                           Year Director          Stock" << endl;
	comedyBST.displayAll();
	cout << "============================================================================" << endl;
	cout << "                                Display Dramas " << endl;
	cout << "============================================================================" << endl;
	cout << " Director             Title                    Year     Stock" << endl;
	dramaBST.displayAll();
	cout << "============================================================================" << endl;
	cout << "                                Display Classics " << endl;
	cout << "============================================================================" << endl;
	cout << " Month  Year  Major actor        Title                  Director       Stock" << endl;
	classicsBST.displayAll();
	cout << "============================================================================" << endl;
	cout << endl << endl;
}
////-------------------------------------------------------------------------
//// addError() 
//// voie type method:
//// collectts errors that has been detected during movie creating
//// store error into string errorCollegector
//// takes one parameter: string error
void InventoryManager::addError(string error) {
	count++;
	ostringstream temp;
	temp << count;
	errorCollector += temp.str() + ") ";
	errorCollector += error;
	errorCollector += "\n";
}

////-------------------------------------------------------------------------
//// displayErrors()
//// void type method:
//// dispalays all errors that appears during the movies file reading
void InventoryManager::displayErrors() const {
	cout << endl;
	cout << "=============================================================================" << endl;
	cout << "                                Invalid movie report" << endl << endl;
	cout << errorCollector;
	cout << endl;
	cout << "=============================================================================" << endl;

}

////-------------------------------------------------------------------------