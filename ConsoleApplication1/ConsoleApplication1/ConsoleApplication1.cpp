#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

// Map to store the mapping of digits to letters
map<char, string> digitsMapping = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', " "}, {'1', "@"} };

// Recursive function to calculate permutations of the string
void PermuteStringRec(string digits, string currentStr, int currentIndex, vector<string>& result)
{
	// Base case: add the permutation to the result vector
	if (currentIndex == digits.size())
	{
		result.push_back(currentStr);
		return;
	}
	// Get the letters corresponding to the current digit
	string letters = digitsMapping[digits[currentIndex]];
	// Loop through all the letters and recursively call the function to calculate the permutations of the remaining digits
	for (int i = 0; i < letters.size(); i++)
	{
		PermuteStringRec(digits, currentStr + letters[i], currentIndex + 1, result);
	}
}

// Function to calculate all possible permutations of the input string
vector<string> PermuteDigits(string digits)
{
	vector<string> result;
	PermuteStringRec(digits, "", 0, result);
	return result;
}

// Function to print the elements of a vector as a string
string PrintString(vector<string> str)
{
	string out = "[";
	for (int i = 0; i < str.size(); i++)
	{
		out += str[i] + ", ";
	}
	out = out.substr(0, out.size() - 2) + "]";
	return out;
}

// Driver code
int main()
{
	// Add mapping values for digits 0 and 1
	digitsMapping['0'] = "+";
	digitsMapping['1'] = " ";
	// Calculate permutations for given numbers
	vector<string> inputDigits = { "23", "138", "828" };
	for (int index = 0; index < inputDigits.size(); index++)
	{
		vector<string> permutedStrings = PermuteDigits(inputDigits[index]);
		cout << index + 1 << ".\t All letter combinations for '" << inputDigits[index] << "': ";
		cout << PrintString(permutedStrings) << endl;
		cout << string(100, '-') << endl;
	}
	return 0;
}