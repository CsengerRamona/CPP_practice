#include <iostream>

bool isArmstrongNumber(int number)
{
	// TODO: implement some functionality to see if this number is an armstrong number
	int temp = number;
	int rest{ 0 };
	int sum{ 0 };

	while (temp)
	{
		rest = temp % 10;
		sum += rest * rest * rest;
		temp = temp / 10;
	}

	if (sum == number)
		return true;
	
	return false;
}

void printIsArmstrong(int number)
{
	if (isArmstrongNumber(number))
	{
		std::cout << "Armstrong" << std::endl;
	}
	else
	{
		std::cout << "NOT Armstrong" << std::endl;
	}
}

bool isNotNumber(std::string str)
{
	int i{ 0 };
	for (char c : str) {
		if (isdigit(c) == 0)
			i++;
	}
	if (i == 0)
		return false;
	return true;
}

int main(int argc, char *argv[])
{
	// What is this program expected to do?
	// - Shows whether an argument is an armstrong number.
	// (what?)
	// -	An Armstrong number is a number that is equal to the sum of cubes of its digits.
	//		For example 0, 1, 153, 370, 371 and 407 are the Armstrong numbers.
	//		Let's try to understand why 153 is an Armstrong number:
	//			1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
	//
	// How to launch it?
	// - Execute the binary and pass a parameter to it?
	// - E.g. Open CMD in bin/Debug or bin/Release
	//		  03_armstrong.exe 1		=> Output: Armstrong
	//		  03_armstrong.exe 2		=> Output: NOT Armstrong
	//		  03_armstrong.exe 			=> Output: No program arguments found.
	//		  03_armstrong.exe ABC		=> Undefined output (do whatever).
	//		  03_armstrong.exe 153		=> Output: Armstrong
	//		  03_armstrong.exe 154		=> Output: NOT Armstrong
	//

	// Make sure there are some program arguments available.
	if (argc <= 1)
	{
		std::cout << "No program arguments found." << std::endl;
		return 1;
	}

	else
	{
		int readNumber = 0;

		// Get the first argument
		std::string argumentAsString = argv[1];
		const char* argumentAsCharArray = argumentAsString.c_str();
		if (isNotNumber(argumentAsString) == true)
		{
			std::cout << "NAN";
		}
		else 
		{
			// TODO: read number / cast to integer
			readNumber = atoi(argumentAsCharArray);

			printIsArmstrong(readNumber);
		}
	}


	return 0;
}