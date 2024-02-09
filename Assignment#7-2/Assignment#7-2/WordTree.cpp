//
//  WordTree.cpp
//  Assignment#7-2
//
//  Created by Daren Sivam on 6/6/22.
//

#include "WordTree.h"
#include <iostream>
#include <string>

void WordTree::readFile(std::ifstream& inputFile)
{
   char currentChar;
   std::string word;

   while (inputFile.get(currentChar))
   {
       word = "";

       while (isalpha(currentChar) || currentChar == '\'')
       {
           currentChar = tolower(currentChar);
           word += currentChar;
           inputFile.get(currentChar);
       }

       if (!word.empty())
       {
           WordNode n1 = WordNode(word);
           Add(n1);
       }
   }
}

void WordTree::insert(WordNode* & nodeptr, std::string tempWord)
{
   if (nodeptr == nullptr)
   {
       nodeptr = new WordNode;
       nodeptr->word = tempWord;
       nodeptr->count++;
       return;
   }
  
   if (tempWord < nodeptr->word)
   {
       insert(nodeptr->left, tempWord);
   }

   else if (tempWord > nodeptr->word)
   {
       insert(nodeptr->right, tempWord);
   }
   else if (tempWord == nodeptr->word)
   {
       nodeptr->count++;
   }
}

void WordTree::Add(WordNode wordOBJ)
{
   insert(root, wordOBJ.word);
}

void WordTree::destroySingle(WordNode * nodeptr)
{
   if (nodeptr == nullptr) //Post order traversal
   {
       destroySingle(nodeptr->left);
       destroySingle(nodeptr->right);
       delete nodeptr;
   }
}

int WordTree::CountNodesSingle(WordNode * nodeptr) const
{
   if (nodeptr == nullptr)
   {
       return 0;
   }
    //Pre Order Traversal
   return 1 + CountNodesSingle(nodeptr->left) + CountNodesSingle(nodeptr->right);
}

int WordTree::CountNodes() const
{
   return CountNodesSingle(root);
}

int WordTree::countTotalSingle(WordNode * nodeptr) const
{
   if (nodeptr == nullptr)
   {
       return 0;
   }
    //Pre Order Traversal
   return nodeptr->count + countTotalSingle(nodeptr->left) + countTotalSingle(nodeptr->right);
}

int WordTree::countTotalWords() const
{
   return countTotalSingle(root);
}

void WordTree::printSingle(WordNode * nodeptr, std::ostream & out) const
{
   if (nodeptr == nullptr)
       return;
    //In Order Traversal
   printSingle(nodeptr->left, out);
   out << nodeptr->word << " " << nodeptr->count << std::endl;
   printSingle(nodeptr->right, out);
}

void WordTree::printTree(std::ostream & out) const
{
   printSingle(root, out);
}

std::ostream& operator<< (std::ostream& outputFile, const WordTree& myTree)
{
   if (myTree.root == nullptr)
       return outputFile;
    //In Order Traversal
   myTree.printTree(outputFile);
   return outputFile;
}
