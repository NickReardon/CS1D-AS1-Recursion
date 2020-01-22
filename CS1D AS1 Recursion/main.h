/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #1	: Vectors
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 01 / 22 / 20
 *****************************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_

 //Standard includes
#include <iostream>
#include <iomanip>
#include <string>
#include "PrintHeader.h"

//Program Specific
#include <fstream>
#include <vector>
#endif // _HEADER_H_


// Setup function for PalindromeRecursion
// returns true if the given string IS a palindrome, else it returns false
// No change to given string
bool CheckPalindrome(const std::string& input);


// Recursively checks if a given string is a palindrome
// Uses setup function CheckPalindrome
// returns true if the given string IS a palindrome, else it returns false
// No change to given string
// Case insensitive, ignores whitespace and any non alpha numeric character
bool PalindromeRecursion(const std::string& input, int front, int back);



// Outputs a given string along with given index locations
// Used to indicate current character comparisons for palindromes
// Indicates two given indices unless both indices match
// No change to given string
void PrintStringPositions(const std::string& input, int front, int back);
