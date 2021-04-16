/********************************************************
Author: Nathaniel

This Program counts the number of strings in a file and the number of certain designinated strings
*********************************************************/

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[]){ //passing an argument in main 
    
    ifstream fin; //defined file in
    ofstream fout;//defined file out
    
    //defining int for counting number of strings
    int numcat = 0;
    int numbunny = 0;
    int numdog = 0;
    int count = 0;
    
    string line;
    string item; //Used for counting 
   
    cout << "Code Exe: " << argv[0] << endl;
    
    fin.open(argv[1]); //opens file from argument line
    while(getline(fin, line)) //gets each line of code
    {      
        count++; //counts total of strings in file
        
    fin >> item;
        if(item == "cat") //counts cats
            numcat++;
        if(item == "bunny")//counts bunnies
            numbunny++;
        if(item == "dog")//counts dogs 
            numdog++;
    }
    
    cout << "Number of Strings: " << count << endl; //prints out # of strings
    cout << "Number of Cats: " << numcat << endl; //prints out # of cats
    cout << "Number of Bunnies: " << numbunny << endl; //prints out # of bunnies
    cout << "Number of Dogs: " << numdog << endl; //prints out # of dogs
    
    //defined down here otherwise array is set to 0 
    string cat[numcat];
    string bunny[numbunny];
    string dog[numdog]; 

    //assigns string to each slot of memory in array
    for(int i = 0; i < numcat; i++)
        cat[i] = "cat";
    for(int i = 0; i < numbunny; i++)
        bunny[i] = "bunny";
    for(int i = 0; i < numdog; i++)
        dog[i] = "dog";

    
    fin.close(); //closes file
 
    fout.open("animalsorder.txt"); //opens new file
    //reads out array into file
    for(int i = 0; i < numbunny; i++)
        fout << bunny[i] << endl;
    for(int i = 0; i < numcat; i++)
        fout << cat[i] << endl;
    for(int i = 0; i < numdog; i++)
        fout << dog[i] << endl;
    fout.close(); //closes file

    return 0;
}
