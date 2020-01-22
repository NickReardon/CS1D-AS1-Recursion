/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #1	: Vectors
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 01 / 22 / 20
 *****************************************************************************/
#include "main.h"

using std::cout; using std::endl;


int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/

	// input file variable setup
	std::ifstream iFile;
	iFile.open("Input.txt");

	std::vector<std::string> inputVect;
	cout << "   ** Populating vector with strings read from file" << endl;

	// reading from input file into vector
	while (iFile)
	{
		std::string temp;
		std::getline(iFile, temp);
		inputVect.push_back(temp);
	}

	cout << "   ** Testing each string in the vector for palindrome" << endl;

	//Checking each string for palindromes in a loop by calling CheckPalindrome function
	for (int i = 0; i < inputVect.size() - 1; i++)
	{
		cout << endl << "-------------------------" << endl << endl;

		if (CheckPalindrome(inputVect[i]))
		{
			cout << " This IS a palindrome" << endl;
		}
		else
		{
			cout << " This is NOT a palindrome" << endl;

		}
	}
	cout << endl << "-------------------------" << endl << endl;

	system("pause");
	return 0;
}


// Setup function for PalindromeRecursion
// returns true if the given string IS a palindrome, else it returns false
// No change to given string
bool CheckPalindrome(const std::string& input)
{
	int back = input.length() - 1;

	return PalindromeRecursion(input, 0, back);
}


// Recursively checks if a given string is a palindrome
// Uses setup function CheckPalindrome
// returns true if the given string IS a palindrome, else it returns false
// No change to given string
// Case insensitive, ignores whitespace and any non alpha numeric character
bool PalindromeRecursion(const std::string& input, int front, int back)
{
	bool match;
	bool validChar = false;

	while (validChar == false)
	{
		if (input[front] < '0' || (input[front] > '9' && input[front] < 'A') ||
			(input[front] > 'Z' && input[front] < 'a') || input[front] > 'z')
		{
			front++;
		}
		else
		{
			validChar = true;
		}

		if (input[front] < '0' || (input[front] > '9' && input[front] < 'A') ||
			(input[front] > 'Z' && input[front] < 'a') || input[front] > 'z')
		{
			back--;
			validChar = false;

		}
		else
		{
			validChar = true;
		}

		if (!validChar && back <= front)
		{
			return true;
		}
	}

	PrintStringPositions(input, front, back);

	if (toupper(input[front]) != toupper(input[back]))
	{
		return false;
	}
	else if ((back - front) < 2)
	{
		return true;
	}
	else
	{
		return PalindromeRecursion(input, ++front, --back);
	}
}


// Outputs a given string along with given index locations
// Used to indicate current character comparisons for palindromes
// Indicates two given indices unless both indices match
// No change to given string
void PrintStringPositions(const std::string& input, int front, int back)
{

	if ((front - back) == 0)
	{
		cout << " | " << input << " | " << endl;
		cout << "   " << std::string(front, ' ') << '^' << endl;
	}
	else
	{
		cout << " | " << input << " | " << endl;
		cout << "   " << std::string(front, ' ') << '^'
			<< std::string(back - front - 1, ' ') << '^' << endl;
	}


}