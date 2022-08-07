// Includes

// C++ system headers
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// 3rd party libs headers
#include <SimpleIni.h>

/**
	Define a simple book.
*/
class Book
{
public:
	std::string name;
	std::string authors;

	void print()
	{
		std::cout << this->name << std::endl;
		std::cout << "\t(by " << this->authors << ")" << std::endl;
	}
};

/**
	Reads a vector of books from an INI file.
	Note: the INI file shall contain a general books section with the number of books contained,
	and another INI section for each book, named [book.N], where N is a number/counter

	[books]
	count = 2;

	[book.1]
	name=The origin of truth
	author=Gusti
	[book.2]
	name  = Arhanghelul Raul
	author=Ovidiu Eftimie

	@param file_name The name of the file to read from (must include path).
	@return Vector of books.
*/
std::vector<Book> readBooksFromIniFile(char* file_name)
{
	std::vector<Book> results;
	Book myBook;
	// TODO: BEGIN read the file -------------------------------------

	CSimpleIniA ini;
	ini.SetUnicode();

	SI_Error rc = ini.LoadFile(file_name);

	//CSimpleIniA::TNamesDepend sections;
	//ini.GetAllSections(sections);

	//CSimpleIniA::TNamesDepend keys;
	// ini.GetAllKeys("books", keys);
	const int booksCount = (*ini.GetValue("books", "count")) - 48;
	if (rc < 0) {
		std::cout << "Error when reading the file" << std::endl;/* handle error */
	};



	for (int i = 0; i < booksCount; i++)
	{	
		std::stringstream ss;
		ss << "book." << (i + 1);
		std::string section_name(ss.str());
		const char* charArray = section_name.c_str();
		myBook.name = ini.GetValue(charArray, "name");
		myBook.authors = ini.GetValue(charArray,"author");


		results.push_back(myBook);
	}
	//const char* pv;
	//pv = ini.GetValue("book.1", "author");
	//std::cout << pv << std::endl;

	
	// E.g. Book myBook;
	//		// build the section name (E.g. book.1)
	//		std::stringstream ss;
	//		ss << "book." << (i + 1);
	//		// Copy the stream to a string you can use
	//		std::string section_name(ss.str());

	//		...
	//		results.emplace_back(myBook);

	// TODO: END read file and add to results vector ------------------
	return results;
}

int main()
{
	// Read a collection of books from an INI file.
	// Using the SimpleINI C++ Lib: https://github.com/brofield/simpleini

	// Read the data
	//std::string input_data("D:/Cursuri/CursCpp/Tema1/CPP_practice/data/ermahgerd_berks.ini");
	char* input_data("D:/Cursuri/CursCpp/Tema1/CPP_practice/data/ermahgerd_berks.ini");
	std::cout << "Reading the data from " << input_data << std::endl;
	std::vector<Book> books_from_file = readBooksFromIniFile(input_data);


	// Print the data
	std::cout << "Here are all the books found in the data file..." << std::endl;
	for (auto book : books_from_file)
	{
		book.print();
	}

	return 0;
}