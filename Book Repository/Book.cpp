#include "Book.h"
Book::Book()/*Parameterless constructor sets to defualt values*/
{
	this->bookID = ""; /*Empty string is something, nullptr is nothing - a big difference*/
	this->title = "";
	this->author = "";
	for (int i = 0; i < priceArraySize; i++) this->prices[i] = 0;
	this->bookType = BookType::UNDECIDED;
}

Book::Book(string bookID, string title, string author, double prices[], BookType bookType)
{
	this->bookID = bookID;
	this->title = title;
	this->author = author;
	for (int i = 0; i < priceArraySize; i++) this->prices[i] = prices[i];
	this->bookType = bookType;
}

Book::~Book(){}/*destructor does nothing - the Book class creates nothing dynamically*/

string Book::getID() { return this->bookID; }
string Book::getTitle() { return this->title; }
string Book::getAuthor() { return this->author; }
double* Book::getPrices() { return this->prices; }//An array name Is a pointer!
BookType Book::getBookType() { return this->bookType; }

void Book::setID(string ID) { this->bookID = ID; }
