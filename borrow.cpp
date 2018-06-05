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
#include "borrow.h"
////--------------------------------------------------------------------------
//// Borrow()
//// Constractor
Borrow::Borrow() {
	errorCollector = "";
}

////--------------------------------------------------------------------------
//// ~Borrow()
//// Destructor
Borrow::~Borrow() {

}

////--------------------------------------------------------------------------
//// ProccessTransaction()
//// void type method:
//// process transaction: read the line, get id and check for valid customer id
//// if cusomer is valid, call helper fancation that  continue read the data
//// three parameters: string line, refrencese to a object cus_manager, 
//// references to a object inv_mang
void Borrow::proccessTransaction(string line, CustomerManager& cus_mang, InventoryManager& inv_mang) {

	string temp;                // hold info about line
	int customer_id;            // hold customer id
	Customer * customer = NULL; // hold pointer to the object customer

	stringstream ss;            // string reader
	ss << line;

	ss >> customer_id;          // get customer id

	customer = cus_mang.getCustomer(customer_id);     // get pointer to the customer
	if (checkValidCustomer(customer, customer_id)) {  // check if customer exist
		getline(ss, temp);                            // get movie info
		readTransaction(temp, customer, inv_mang);    // procces transaction
	}
}

////--------------------------------------------------------------------------
//// readTrnasaction()
//// void type method:
//// helper fucntion for proccessTransaction. Contiue read the line. 
//// Parse  the line into small pices. Based on these pices, creates pointer 
//// to a movie and retives actual movie
//// if retrive is succefull, proccess borrowMovie()
//// three parameters: stirng info, pointer to Customer, 
//// refrenses to InventoryManager
void Borrow::readTransaction(string info, Customer* customer, InventoryManager& inv_mang){

	stringstream ss;                     // get reader 
	ss << info;                          // insert string into reader
	char movietype;                      // hold movie type
	char mediatype;                      // hold  media type
	string temp1;                        // hold movie info
	string temp2;                        // hold movie info
	string majorActor;                   // hold actor
	int _year = 0;                       // hold year
	int _month1 = 0;                     // hold month
	Movie * temp_movie = NULL;           // hold temporory pointer to the transaction movie
	Movie * customer_movie = NULL;       // hold  pointer on actual tree movie

	ss >> mediatype;                     // insert media tye                

	if (mediatype == DVD) {              // check if media type is valid
		ss >> movietype;                 // insert movie type
		switch (movietype)
		{
			// case Drama
		case 'D':
			getline(ss, temp2, ',');     // insert  director
			getline(ss, temp1, ',');     // insert title
			temp_movie = new Drama(temp1, temp2);  // allocate new object 
			customer_movie = inv_mang.retriveMovie(temp_movie, movietype);  // retrive actual pointer to movie
			borrowMovie(customer, customer_movie, temp_movie); // call helper method
			delete temp_movie;          // delete object
			temp_movie = NULL;          // NULL
			break;
			// case Comedy
		case 'F':
			getline(ss, temp2, ',');    // insert title
			getline(ss, temp1);         // hold year
			stringstream(temp1) >> _year;  // assign  year
			temp_movie = new Comedy(temp2, _year); // allocate new object 
			customer_movie = inv_mang.retriveMovie(temp_movie, movietype);  // retrive actual pointer to movie
			borrowMovie(customer, customer_movie, temp_movie); // call helper method
			delete temp_movie;          // delete object
			temp_movie = NULL;          // NULL
			break;
			// case Classics
		case 'C':
			getline(ss, temp1, ' ');     // hold space
			getline(ss, temp1, ' ');     // hold month
			stringstream(temp1) >> _month1; // assign month
			getline(ss, temp1, ' ');     // hold year
			stringstream(temp1) >> _year;   // assing year
			ss >> temp1;                 // get last name
			majorActor += temp1;
			majorActor += ' ';           // hold space between names
			ss >> temp1;                 // get first name
			majorActor += temp1;
			temp_movie = new Classics(majorActor, _month1, _year); // allocate new object
			customer_movie = inv_mang.retriveMovie(temp_movie, movietype); // retrive actual pointer to movie
			borrowMovie(customer, customer_movie, temp_movie); // call helper method
			delete temp_movie;         // delete object
			temp_movie = NULL;         // NULL
			break;
			// invalid movie type
		default:
			getline(ss, temp1);
			string a(1, movietype);
			addError("Invalid movie type: " + a + temp1); // add invalud movie type
			break;
		}
	}
	// not DVD 
	else {
		string a(1, mediatype);
		getline(ss, temp1);
		addError("Invalid  media type: " + a + temp1);	// add invalid media type
	}
}
////--------------------------------------------------------------------------
//// borrowMovie()
//// void  type method:
//// check if  cusomter can borrow movie of not.
//// Check the actual stock for a movie. Also,add error massage 
//// if movie doesn't exist in inventory manager.
//// three parameters: pointer Customer, pointer Movie , pointer Movie.
void Borrow::borrowMovie(Customer* customer, Movie *customer_movie, Movie * temp_movie) {
	if (customer_movie != NULL) {   // check if retrive was succesufull
		bool success = customer->movieBorrow(customer_movie);   // try to borrow
		if (!success) {  // can't borrow, add error massage
			addError(customer->getCustomerInfo() + ". Attempt to borrow empty stock for"
				+ "\n" + customer_movie->printInfoForCustomer());
		}
	}
	else {  // movie doesn't exists
		addError("Invalid retrive of " + temp_movie->printInfoForCustomer());   // add invalid moive
	}
}
////--------------------------------------------------------------------------