//
//  WordTree.h
//  Assignment#7-2
//
//  Created by Daren Sivam on 6/6/22.
//

#ifndef WordTree_h
#define WordTree_h

#include <stdio.h>
#include <fstream>

struct WordNode
{
   std::string word;
   int count;
   WordNode()
   {
       word = "";
       count = 0;

       left = nullptr;
       right = nullptr;
   }
   WordNode(std::string word)
   {
       this->word = word;
       count = 1; //At least one word

       left = nullptr;
       right = nullptr;
   }

   WordNode * left;
   WordNode * right;
};

class WordTree
{
private:
   void insert(WordNode* & nodeptr, std::string word);
   void printSingle(WordNode * nodeptr, std::ostream & out) const;
   int CountNodesSingle(WordNode * nodeptr) const;
   int countTotalSingle(WordNode * nodeptr) const;
   void destroySingle(WordNode * nodeptr);
   WordNode * root;
public:
   WordTree()
   {
       root = NULL;
   }

   ~WordTree()
   {
       destroySingle(root);
   }

   void readFile(std::ifstream & inputFile);
   void Add(WordNode word);
   void printTree(std::ostream & out) const;
   int CountNodes() const;
   int countTotalWords() const;
   friend std::ostream& operator<< (std::ostream& outputFile, const WordTree& obj);
};
#endif /* WordTree_h */
