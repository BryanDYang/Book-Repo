#include "Repo.h"
void Repo::parse(string bookdata)/*this parses out each row - one at a time*/
{
	BookType bt = UNDECIDED; /*Default value*/
	if (bookdata.at(0) == 'F') bt = FICTION; /*The first character tells us the book type*/
	else if (bookdata.at(0) == 'N') bt = NONFICTION;

	int rhs = bookdata.find(",");//find the comma
	string bID = bookdata.substr(0, rhs);//extract the substring in front of the comma

	int lhs = rhs + 1; //move past the previous comma
	rhs = bookdata.find(",", lhs);
	string ttl = bookdata.substr(lhs, rhs - lhs);//book title

	lhs = rhs + 1; //keep going
	rhs = bookdata.find(",", lhs);
	string aut = bookdata.substr(lhs, rhs - lhs); //book author

	lhs = rhs + 1; //keep going
	rhs = bookdata.find(",", lhs);
	double p1 = stod(bookdata.substr(lhs, rhs - lhs));//first price - convert to double
	lhs = rhs + 1;
	rhs = bookdata.find(",", lhs);
	double p2 = stod(bookdata.substr(lhs, rhs - lhs));//second price
	lhs = rhs + 1;
	rhs = bookdata.find(",", lhs);
	double p3 = stod(bookdata.substr(lhs, rhs - lhs));//third price
	//Already determined the book type - it was the first thing we did - call add() method

	add(bID, ttl, aut, p1, p2, p3, bt); //prices go in separately
}

//The infamous, redundant, and wholly unnecessary add method - it only does one thing
void Repo::add(string bookID, string title, string author, double price1, double price2, double price3, BookType bt)
{
	//put prices back into an array for constructor - execute two things
	double parr[3] = { price1, price2, price3 };
	//make the new book object. Remember that lastIndex starts at -1 and Not 0
	//remember to use the prefix form of ++. Using postfix will mess you up
	bookRepoArray[++lastIndex] = new Book(bookID, title, author, parr, bt); //use full constructor
}

//display all books using tab-separated output
void Repo::printAll()
{
	Book::printHeader(); //quick way to do this part
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		cout << bookRepoArray[i]->getID(); cout << '\t';
		cout << bookRepoArray[i]->getTitle(); cout << '\t';
		cout << bookRepoArray[i]->getAuthor(); cout << '\t';
		cout << bookRepoArray[i]->getPrices()[0]; cout << '\t';
		cout << bookRepoArray[i]->getPrices()[1]; cout << '\t';
		cout << bookRepoArray[i]->getPrices()[2]; cout << '\t';
		cout << bookTypeStrings[bookRepoArray[i]->getBookType()] << std::endl;
	}
}

//display only books which match given book type
void Repo::printByBookType(BookType bt)
{
	Book::printHeader();
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		if (Repo::bookRepoArray[i]->getBookType() == bt) bookRepoArray[i]->print();
	}
	cout << std::endl;
}

//each book's ID must contain an underscore and either an upper case 'X' or a lower case 'x'
void Repo::printInvalidIDs()
{
	bool any = false;
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		string bID = (bookRepoArray[i]->getID());
		if (bID.find('_') == string::npos || (bID.find('X') == string::npos && bID.find('x') == string::npos))
		{
			any = true;
			cout << bID << ': ' << bookRepoArray[i]->getTitle() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Repo::printAveragePrices()
{
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		cout << bookRepoArray[i]->getID() << ": ";
		cout << (bookRepoArray[i]->getPrices()[0]
			+ bookRepoArray[i]->getPrices()[1]
			+ bookRepoArray[i]->getPrices()[2]) / 3.0 << std::endl;
	}
	cout << std::endl;
}

void Repo::removeBookByID(string bookID) //book to be removed comes in as parameter
{
	bool success = false; //assume it's not here
	for (int i = 0; i <= Repo::lastIndex; i++)
	{
		if (bookRepoArray[i]->getID() == bookID)
		{
			success = true; //found
			if (i < numBooks - 1)
			{
				Book* temp = bookRepoArray[i]; //swap it with last book
				bookRepoArray[i] = bookRepoArray[numBooks - 1];
				bookRepoArray[numBooks - 1] = temp;
			}
			Repo::lastIndex--;//last book no longer visible
			//notice I did not actually delete the book! You can't see it now!
		}
	}
	if (success)
	{
		cout << bookID << " removed from repository." << std::endl << std::endl;
		this->printAll();//display the books - the removed one should not display
	}
	else cout << bookID << " not found." << std::endl << std::endl;
}

Repo::~Repo()
{
	cout << "DESTRUCTOR CALLED!!!" << std::endl << std::endl;
	for (int i = 0; i < numBooks; i++)
	{
		cout << "Destroying book #" << i + 1 << std::endl;
		delete bookRepoArray[i];
		bookRepoArray[i] = nullptr;
	}
}