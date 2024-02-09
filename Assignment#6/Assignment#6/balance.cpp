//Daren Sathasivam
//CSCI-2 0122
//Professor Ambrosio
//Assignment 6
//Program prompts user to use a specific file. Then, the input from the file must be balanced. For example, brackets, quotes, '/*' and '*/'. Before checking, a message must be diplayed to state that a pair from the file is being matched. If it runs into an error, print out a message stating the specific line the balance-error ocurred on then exits the program.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <algorithm>
#include <csignal>
#include <regex>
#include <type_traits>
#include <set>
using namespace std;

void printFile(istream &dictfile);
bool balanceFile(istream &dictfile);
void nextChar(char &c, istream &infile, int &i);
/*
void printFile(istream &dictfile);
bool balanceFile(istream &dictfile);
bool Matching(char, char);
void getChar(char& c, istream&infile, int& i); */

class streambuf_switcher
{
public:
streambuf_switcher(ios& dest, ios& src)
: dest_stream(dest), saved_streambuf(dest.rdbuf(src.rdbuf()))
{}
~streambuf_switcher()
{
dest_stream.rdbuf(saved_streambuf);
}
private:
ios & dest_stream;
streambuf* saved_streambuf;
};
void testone(int n)
{
ostringstream strCout;
streambuf_switcher sso(cout, strCout);
switch (n)
{
default: {
cout << "Bad argument" << endl;
} break; case  1: {
istringstream iss("{}");
assert(balanceFile(iss));
string str = strCout.str();
regex e(R"(pair *matching *\{ *and *\})");
assert(regex_search(str, e));
} break; case  2: {
istringstream iss("[]");
assert(balanceFile(iss));
string str = strCout.str();
regex e(R"(pair *matching *[ *and *])");
assert(regex_search(str, e));
} break; case  3: {
istringstream iss("()");
assert(balanceFile(iss));
string str = strCout.str();
regex e("pair *matching *\\( *and *\\)");
assert(regex_search(str, e));
} break; case  4: {
istringstream iss("/* */");
assert(balanceFile(iss));
    string str = strCout.str();
    regex e(R"(pair *matching */\* *and *\*/)");
    assert(regex_search(str, e));
    } break; case  5: {
    istringstream iss("\" \"");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e(R"(pair *matching *\" *and *\")");
    assert(regex_search(str, e));
    } break; case  6: {
    istringstream iss("' '");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e(R"(pair *matching *' *and *')");
    assert(regex_search(str, e));
    } break; case  7: {
    istringstream iss("{\n}");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e(R"(pair *matching *\{ *and *\})");
    assert(regex_search(str, e));
    } break; case  8: {
    istringstream iss("{(\n)}");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e("pair *matching *\\( *and *\\).*\\npair *matching *\\{ *and *\\}");
    assert(regex_search(str, e));
    } break; case  9: {
    istringstream iss("() {}");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e("pair *matching *\\( *and *\\).*\\npair *matching *\\{ *and *\\}");
    assert(regex_search(str, e));
    } break; case  10: {
    istringstream iss("\" ][ \"");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e(R"(pair *matching *\" *and *\")");
    assert(regex_search(str, e));
    } break; case  11: {
    istringstream iss("/* \n ][ */ { * }");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e(R"(pair *matching */\* *and *\*/.*\npair *matching *\{ *and
    *\})");
    assert(regex_search(str, e));
    } break; case  12: {
    istringstream iss("/* \n ][ */");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e(R"(pair *matching */\* *and *\*/)");
    assert(regex_search(str, e));
    } break; case  13: {
    istringstream iss("\n{\n(\n//']\n)}");
    assert(balanceFile(iss));
    string str = strCout.str();
    regex e("pair *matching *\\( *and *\\).*\\npair *matching *\\{ *and *\\}");
            assert(regex_search(str, e));
            } break; case  14: {
            istringstream iss("\n{\n(\n//*]\n)}");
            assert(balanceFile(iss));
            string str = strCout.str();
            regex e("pair *matching *\\( *and *\\).*\\npair *matching *\\{ *and *\\}");
            assert(regex_search(str, e));
            } break; case  15: {
            istringstream iss("\n{\n(]\n)}");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced).*(\\(|\\]).*3");
            assert(regex_search(str, e));
            } break; case  16: {
            istringstream iss("\n{(\n)");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced).*\\{.*2");
            assert(regex_search(str, e));
            } break; case  17: {
            istringstream iss("\n\n{(\n')}");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced).*'.*4");
            assert(regex_search(str, e));
            } break; case  18: {
            istringstream iss("{");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced)");
            assert(regex_search(str, e));
            } break; case  19: {
            istringstream iss("}");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced)");
            assert(regex_search(str, e));
            } break; case  20: {
            istringstream iss("{ /* }");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced)");
            assert(regex_search(str, e));
            } break; case  21: {
            istringstream iss("'*");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced)");
            assert(regex_search(str, e));
            } break; case  22: {
            istringstream iss("()[]{ * }}");
            assert(!balanceFile(iss));
            string str = strCout.str();
            regex e("(unmatched|unbalanced)");
            assert(regex_search(str, e));
            } break; case  23: {
            istringstream iss("()([{}]) /* */");
                assert(balanceFile(iss));
                } break; case  24: {
                istringstream iss("/* ]][()) ' */");
                assert(balanceFile(iss));
                } break; case  25: {
                istringstream iss(" ][ ");
                assert(!balanceFile(iss));
                string str = strCout.str();
                regex e("(unmatched|unbalanced)");
                assert(regex_search(str, e));
                } break;
                }
                }
int main()
{
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed" << endl;
}

struct balance
{
    int line;
    char balanceChar;
};
//Prints the file with preceding line numbers for each line.
void printFile(istream &dictfile)
{
    int i = 1; //start at 1 so line numbers are proper
    string line; //String for the whole line of code
    while (dictfile.peek() != EOF) //loop until the end of the file
    {
        getline(dictfile, line);
        cout << i << " " << line << endl; //print out file number and the stuff on the line
        i++;
    }
    dictfile.clear();               //A file that you have read all the way to the end can be read again
    dictfile.seekg(0, dictfile.beg);
}
//Takes a file dictfile and prints the matching code elements. Returns true if the file is balanced, false otherwise.
bool balanceFile(istream &dictfile)
{
    char character;
    char save;
    bool balanced = true; //if balanced, return true
    int numLine = 1;
    stack <balance> stack;
    while (dictfile.peek() != EOF) // Read till at the end of the file
    {
        nextChar(character, dictfile, numLine);
        if (character == '/' && dictfile.peek() == '*') // Check for a block comment
        {
            dictfile.get(character);
            int errorLine = numLine; // Save line number from first block comment
            nextChar(character, dictfile, numLine);
            while ((character != '*' || dictfile.peek() != '/') && dictfile.peek() != EOF) // Loop till at the end of Block Comment
            {
                nextChar(character, dictfile, numLine);
            }
            if (dictfile.peek() == EOF) // Return false, if the file cant find the end of the Block Comment
            {
                balanced = false;
                cout << "unmatched /* symbol on line " << errorLine << endl; //Output saved line from starting open block comment
                return balanced;
            }
            cout << "pair matching /* and * /" << endl;
        }
        else
        {
            if (character == '/' && dictfile.peek() == '/') // Check for a comment(same line bc '//')
            {
                string newLine;
                getline(dictfile, newLine);
            }
        }

        if (character == '"' || character == '\'')
        { // Check for " or ' quotes
           /*
            char setChar;
            int errorLine;
            setChar = character;
            errorLine = numLine;
            nextChar(character, dictfile, numLine);
            while (character != setChar && character != '\n')
            {
                nextChar(character, dictfile, numLine);
            }
            if (character == '\n') //If the end of the line is reached wihtout finding char, return false.
            {
                balanced = false;
                cout << "unmatched " << setChar << " symbol on line " << errorLine << endl;
                return balanced;
            }
            if (character != setChar && dictfile.peek() == EOF && dictfile.peek() != '\n') // Return false, if the program cant find the closing quotation.
            {
                balanced = false;
                cout << "unmatched " << setChar << " symbol on line " << errorLine << endl;
                return balanced;
            }
            cout << "pair matching " << setChar << " and " << setChar << endl; //Required output
            */
            char setChar;
            setChar = save;
            nextChar(character, dictfile, numLine);
            while (save != setChar && dictfile.peek() != EOF) {
                nextChar(character, dictfile, numLine);
                if (save == '\n') {
                    balanced = false;
                    cout << "unmatched " << setChar << " symbol on line " << numLine << endl;
                    break;
                }
            }
            if (save != setChar && dictfile.peek() == EOF && dictfile.peek() != '\n') {
                balanced = false;
                cout << "unmatched " << setChar << " symbol on line " << numLine << endl;
                break;
            }
            cout << "pair matching " << setChar << " and " << setChar << endl;
        }
        //Check for bracket style chars
        if (character == '(' || character == '{' || character == '[') { //Add onto stack if a beginning bracket is found
            balance bracket; //Data gathered for bracket
            bracket.line = numLine;
            bracket.balanceChar = character;
            stack.push(bracket);
        }
        else if (character == ')' || character == '}' || character == ']') //If closing bracket is found
        {
            if(stack.empty()) //Return false when the stack is empty
            {
                cout << "unmatched \"" << character << "\" symbol on line " << numLine << endl;
                balanced = false;
                return balanced;
            }
            balance opening; //Used for opening brackets
            opening = stack.top();
            stack.pop();
            if ((opening.balanceChar == '{' && character == '}') || (opening.balanceChar == '[' && character == ']') || (opening.balanceChar == '(' && character == ')')) //If open brackets have closing brackets stored in character
            {
                cout << "pair matching " << opening.balanceChar << " and " << character << endl;
            }
            else
            {
                balanced = false;
                cout << "unmatched \"" << opening.balanceChar << "\" symbol on line " << opening.line << endl;
                return balanced;
            }
        }
    }
    if (!stack.empty()) //Stack is not empty
    { 
        cout << "unmatched \"" << stack.top().balanceChar << "\" symbol on line " << stack.top().line << endl;
        balanced = false;
    }
    return balanced;
}
//The next char is searched and keeps count of the number of lines
void nextChar(char &c, istream &dictfile, int &i)
{
    dictfile.get(c);
    if (c == '\n') //If char is at endl
    {
        i++; //Increment
    }
}


/*
 Notes:
 *To reread files
 -infile.clear();
 -inflile.seekg(0, infile.beg);
 *Possible helper functions
 -bool isOpeningBrace(int c) -returns true for an opening brace
 -bool opensBlockComment(...) -returns true if c and the char following form the opening of a comment
 -'\'' for single apostrophe symbol
 */

/*
char save;
save = c;
getChar(c, infile, numberOfLine);
while (c != save && infile.peek() != EOF) {
    getChar(c, infile, numberOfLine);
    if (c == '\n') {
        match = false;
        cout << "unmatched " << save << " symbol on line " << numberOfLine << endl;
        break;
    }
}
if (c != save && infile.peek() == EOF && infile.peek() != '\n') {
    match = false;
    cout << "unmatched " << save << " symbol on line " << numberOfLine << endl;
    break;
}
cout << "pair matching " << save << " and " << save << endl; */
