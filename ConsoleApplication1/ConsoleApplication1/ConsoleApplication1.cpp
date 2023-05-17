#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map<char, string> digitsMapping = { {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', " "}, {'1', "+"} };

void PermuteStringRec(string digits, string currentStr, int currentIndex, vector<string>& result)
{
	if (currentIndex == digits.size())
	{
		result.push_back(currentStr);
		return;
	}

	string letters = digitsMapping[digits[currentIndex]];

	for (int i = 0; i < letters.size(); i++)
	{
		PermuteStringRec(digits, currentStr + letters[i], currentIndex + 1, result);
	}
}

vector<string> PermuteDigits(string digits)
{
	vector<string> result;
	PermuteStringRec(digits, "", 0, result);
	return result;
}

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

int main()
{
	digitsMapping['0'] = "+";
	digitsMapping['1'] = " ";

	vector<string> inputDigits = { "2", "12", "72" };
	for (int index = 0; index < inputDigits.size(); index++)
	{
		vector<string> permutedStrings = PermuteDigits(inputDigits[index]);
		cout << index + 1 << ".\t All letter combinations for '" << inputDigits[index] << "': ";
		cout << PrintString(permutedStrings) << endl;
		cout << string(100, '-') << endl;
	}
}