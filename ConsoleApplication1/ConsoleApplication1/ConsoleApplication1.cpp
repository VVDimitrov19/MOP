#include<iostream>
#include<vector>
#include<string>
using namespace std;

// This function will swap characters for every permutation
string SwapChar(string word, int i, int j)
{
    vector<string> swapIndex;
    //word to list
    for (int it = 0; it < word.size(); it++)
    {
        swapIndex.push_back(word.substr(it, 1));
    }

    //swap
    string temp = swapIndex[i];
    swapIndex[i] = swapIndex[j];
    swapIndex[j] = temp;

    //make word
    string res = "";
    for (int it = 0; it < swapIndex.size(); it++)
        res += swapIndex[it];

    return res;
}

// Recursive function to calculate permutations of the string
void PermuteStringRec(string word, int currentIndex, vector<string>& result)
{
    // Base case: add the permutation to the result vector
    if (currentIndex == (word.size() - 1))
    {
        result.push_back(word);
        return;
    }
    for (int i = currentIndex; i < word.size(); i++)
    {
        // Swap the characters at indices i and currentIndex
        string swappedStr = SwapChar(word, currentIndex, i);
        // Recursively call the function to calculate the permutations of the swapped string
        PermuteStringRec(swappedStr, currentIndex + 1, result);
    }
}

// Function to calculate all possible permutations of the input string
vector<string> PermuteWord(string word)
{
    vector<string> result;
    // Start calculating permutations from the start of the string
    PermuteStringRec(word, 0, result);
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
    vector<string> inputWord = { "ab", "bad", "abcd" };
    for (int index = 0; index < inputWord.size(); index++)
    {
        vector<string> permutedWords = PermuteWord(inputWord[index]);
        cout << index + 1 << ".\t Input string: '" << inputWord[index] << "'" << endl;
        cout << "\t All possible permutations are: ";
        cout << PrintString(permutedWords) << endl;
        cout << string(100, '-') << endl;
    }
    return 0;
}
