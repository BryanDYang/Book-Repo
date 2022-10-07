#include "Repo.h"
//using std::endl;
int main()
{
	//the long strings to parse
	const string bookData[] =
	{
		"NX_1,Forensics for Housewives!,Genevieve Valentin,23.4, 45.99, 35,NONFICTION",
		"Fx0_F2,Useless Cyberpunk Gamer Chat,SuperKool CyberDog,0,19.99,200,FICTION",
		"UXU1x,A Primer of Educational Wisdom,Sage the Divine Goddess,0.99,123.45,987.65,UNDECIDED",
		"F3-F,Mein Kampf est NICHT Fiction!,Adolf Hitler's Corpse,0,1,2.49,FICTION",
		"N_w1,An Agonizing Death from C++,Bryan Yang,999.99,3.14,123,NONFICTION"
	};
	
	const int numBooks = 5;//it's too bad arrays dont record their own size
	Repo repo; //this creates the repo using the default parameterless constructor

	for (int i = 0; i < numBooks; i++) repo.parse(bookData[i]);
	cout << "Displaying all books: " << std::endl;
	repo.printAll();
	cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by book type: " << bookTypeStrings[i] << std::endl;
		repo.printByBookType((BookType)i); //cast the integer to a BookType
	}

	cout << "Displaying books with invalid IDs" << std::endl;
	repo.printInvalidIDs();
	cout << std::endl;

	cout << "Displaying average prices: " << std::endl;
	repo.printAveragePrices();

	cout << "Removing book with ID N_W1:" << std::endl;
	repo.removeBookByID("N_W1"); //this method does its own output

	cout << "Removing book with ID N_W1:" << std::endl;
	repo.removeBookByID("N_W1");
	cout << std::endl;

	system("pause");
	return 0;
}