/******************************************************************
* 
* Author: Nathaniel Palmer
* Date: 6/16/2020
* Description: Morse code conversion and insertion into binary tree
* 
*******************************************************************/

#include<iostream>
using namespace std;
#include<fstream>
#include"bintree.h"

//main area!!!

int main()
{   //-----------------------------
    //-import morse code into Tree-
    //-----------------------------
    int SIZE = 39;
    char alpha[SIZE];
    string morseCode[SIZE];
    
    ifstream iFile;
    iFile.open("code.txt");
       string Line = "";
   getline(iFile, Line); //reads in first line of txt

  for(int i = 0; i < SIZE; i++) //reads in rest of the file
  {
      iFile >> alpha[i];
      iFile >> morseCode[i];
  }  
iFile.close();  

//creating Binary Tree object
codeBinaryTree Tree;

//inserting chars and string into tree
for(int i = 0; i < SIZE; i++)
Tree.insertNode(alpha[i], morseCode[i]);

//prints out the tree in order from smallest to greatest
 cout << "Displays Tree in Order\n";
Tree.printTree();

cout << endl;
cout << endl;

//searches for a value in tree
//test example it works
cout << "Searchs for the value 'A' \n";
if(Tree.searchNode('A'))
    cout << "Value Exists in Tree\n";
else
    cout << "Value Doesn't Exist in Tree\n";

//searches for a value in tree
//test example of it can't find
cout << "Searchs for the value 'g' \n";
if(Tree.searchNode('g'))
    cout << "Value Exists in Tree\n";
else
    cout << "Value Doesn't Exist in Tree\n";

cout << endl;

//Prints out morse code for value A
cout << "Morse code value for 'A': ";
cout << Tree.searchConvert('A') << endl << endl;

//takes file and converts into morse code
//also outputs morse code to a new file

ofstream codeFile("codeConverted.txt");
ifstream charFile("convert.txt");
char value;

cout << "Converts file from characters into morse code: \n";
cout << "File contents are: ";
cout << "'This is a test of the cpts 122 Morse code conversion tool.'\n";
cout << endl;
cout << "Morse Code: \n";

while(!charFile.eof()) //loop for extracting entire file, runs til end of file
{
    charFile >> value;
    if(!Tree.searchNode(value))
    cout << "Not found in tree\n";
   
cout << Tree.searchConvert(value) << " ";
codeFile << Tree.searchConvert(value) << " "; //reads into new file morse code
}
//closing out file
charFile.close();
codeFile.close();

    return 0;
}



























