/******************************************************************
* 
* Author: Nathaniel Palmer
* Date: 6/16/2020
* Description: Morse code conversion and insertion into binary tree
* 
*******************************************************************/
#include<iostream>
using namespace std;
#include"bintree.h"

//navigates where to insert into tree

void codeBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->alphabet < nodePtr->alphabet)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//takes values to insert

void codeBinaryTree::insertNode(char alph, string morse)
{
   TreeNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->alphabet = alph;
   newNode->code = morse;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

//deletes nodes in tree

void codeBinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//searchs to see if value is in tree

bool codeBinaryTree::searchNode(char alph)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->alphabet == alph)
         return true;
      else if (alph < nodePtr->alphabet)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

string codeBinaryTree::searchConvert(char alph)
{
    TreeNode *nodePtr = root;
    
    while(nodePtr)
    {
        if(nodePtr->alphabet == alph)
            return nodePtr->code;
        else if(alph < nodePtr->alphabet)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return "Invalid_Char";
}

//------------------------------
//----function for printing-----
//------------------------------
void codeBinaryTree::printTree(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      printTree(nodePtr->left);
      cout << nodePtr->alphabet << endl;
      cout << nodePtr->code << endl;
      printTree(nodePtr->right);
   }
}



































