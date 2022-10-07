#pragma once
#include "Book.h"
class Repo
{
private:
	int lastIndex = -1;
	const static int numBooks = 5;
	Book* bookRepoArray[numBooks];/*NOT declared dynamically*/

public:
	/*Note that Repo has no constrcutor; r Does it...?*/
	/*The parse method goes through a set of coma delimited strings and extracts the data of a book*/
	void parse(string row);
	/*All book data is then passed into add method which creates the Book object and places it in the */
	void add(string bID,
		string bTitle,
		string bAuthor,
		double bprice1,
		double bprice2,
		double bprice3,
		BookType bt);
	void printAll();/*Just calls the print() method in Book class for each book*/
	void printByBookType(BookType bt);/*BookType is passed in*/
	void printInvalidIDs();/*Each book's ID needs an underscore and either an upper case 'X' or a lower case 'x'*/
	void printAveragePrices(); /*Prints the average price for each book*/
	void removeBookByID(string bookID);/*Find the book with supplied ID and remove*/
	~Repo();
};