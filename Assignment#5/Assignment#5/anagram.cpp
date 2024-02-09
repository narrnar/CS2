//Daren Sathasivam
//CSCI-2, 0122
//Assignment #5
//Create a program which searches for anagrams.

#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
using namespace std;

int loadWords(istream &dictfile, string dict[]);                    //given functions with parameters
int recBlends(string word, const string dict[], int size, string
results[]);
void showResults(const string results[], int size);

int findWord(string word, const string dict[], int size, int &count, string results[], string resultFound[]); //function to find word in dict
void permute(string a, string b, const string dict[], const int &size, int &count, string results[]); //function that searches for the permuatations of a word and returns if there are
void validPermute(int i, int max, string a, string b, const string dict[], const int &size, int &count, string results[]); //compare permutations to words in dictionary to validate the permutations as words
bool noDupe(int i, int max, string word, string results[]); //function to avoid duplicate results

const int MAXRESULTS   = 20;    // Max matches that can be found
const int MAXDICTWORDS = 30000; // Max words that can be read in
int main()
{
    string results[MAXRESULTS];
    string dict[MAXDICTWORDS];
    ifstream dictfile;         // file containing the list of words
    int nwords;                // number of words read from dictionary
    string word;
    
    dictfile.open("words.txt");
    if (!dictfile)
    {
        cout << "File not found!" << endl;
        return (1);
    }
    
    nwords = loadWords(dictfile, dict);
    
    cout << "Please enter a string for an anagram: ";
    cin >> word;
    
    int numMatches = recBlends(word, dict, nwords, results);
    if (!numMatches)
        cout << "No matches found" << endl;
    else
        showResults(results, numMatches);
return 0;
}

//takes in words from dict file and saves into an array of strings
int loadWords(istream &dictfile, string dict[])
{
    string words;
    if(dictfile.eof())//if end of file, return 0
    {
        return 0;
    }
    dictfile >> words;
    int x = loadWords(dictfile, dict); //recursion until end of the file
    if(x < MAXDICTWORDS)
    {
        dict[x] = words;
        x++; //increment
        return x;
    }
    else
    {
        return MAXDICTWORDS; //if dict has 30000 words
    }
}
//function that finds the number of anagrams for a word and is then placed into a string array 'results'. The number of results should not exceed 20(MAXRESULTS)
int recBlends(string word, const string dict[], int size, string
results[])
{
    int count = 0;
    permute("", word, dict, size, count, results);
    return count;
}
//function that searches for the permuatations of a word and returns words to be checked for validity of the possible anagram
void permute(string a, string b, const string dict[], const int &size, int &count, string results[])
{
    int wordLength = b.length();
    if(wordLength == 0)
    {
        count += findWord(a, dict, size, count, results, &results[count]); //check if word exists in dictionary
    }
    else
    {
        validPermute(0, wordLength, a, b, dict, size, count, results); //check if permutation is valid
    }
}
//function which checks the validity of words by comparing results to the words in the dictionary
int findWord(string word, const string dict[], int size, int &count, string results[], string resultFound[])
{
    if(size == 0) //base case
    {
        return 0;
    }
    if(word == *dict)
    {
        if(noDupe(0, count, word, results)) //check results
            return 0;
        else
        {
            *resultFound = word;
            return 1 + findWord(word, dict + 1, size - 1, count, results, resultFound + 1); //recursive case to narrow down search
        }
    }
    else
        return findWord(word, dict + 1, size - 1, count, results, resultFound); //recursive case to narrow down search
}
//function that makes sure there are no duplicate results
bool noDupe(int i, int max, string word, string results[])
{
    if(i >= max)
    {
        return false;
    }
    else if(word == *results)
    {
        return true;
    }
    else
    {
        return noDupe(i + 1, max, word, results + 1); //recursive case to continue checking results array for duplicates
    }
}
//function that compares permutations to words in dictionary to validate the permutations as words
void validPermute(int i, int max, string a, string b, const string dict[], const int &size, int &count, string results[])
{
    string c = b;
    int n = c.length();
    char charB[n + 1];
    strcpy(charB, b.c_str());
    
    if(i >= max) //base case
        return;
    permute(a + b[i], b.substr(0, i) + b.substr(i + 1), dict, size, count, results); //search for permutation -b.substr(0, i) + b.substr(i + 1)
    validPermute(i + 1, max, a, b, dict, size, count, results); //recursive case to validate permutations found
}


void showResults(const string results[], int size)
{
    if(size == 0) //base case with no results found
    {
        return;
    }
    else
    {
        cout << "Matching word: " << *results << endl;
        showResults(results + 1, size - 1); //recursive case to go through all results
    }
}

