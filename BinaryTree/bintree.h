/******************************************************************
* 
* Author: Nathaniel Palmer
* Date: 6/16/2020
* Description: Morse code conversion and insertion into binary tree
* 
*******************************************************************/
#ifndef BINTREE_H
#define BINTREE_H

#include<string>


class codeBinaryTree
{
private:
   struct TreeNode
   {
      char alphabet;         //english alphabet values
      string code;          //morse code values
      TreeNode *left;    // left side nodes
      TreeNode *right;   // right side nodes
   };

   TreeNode *root;       // root node
   
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void printTree(TreeNode *) const;

   void nodeCounter();
   
public:
   // Constructor
   codeBinaryTree()
      { root = nullptr; }
      
   // Destructor
   ~codeBinaryTree()
      { destroySubTree(root); }
      
   // methods
   void insertNode(char, string);
   bool searchNode(char);
   string searchConvert(char);
   
   void printTree() const
      {  printTree(root); }
      


};

#endif