//Napalmj
//Creating a simple char calculator
//Will have 2 double inputs
//calculator contains + - / *
//This is written in C++

#include <iostream>
using namespace std;

int main(){
    //Var Declarations
    char symbol;
    double x, y; //values are of type double

    //Introduction
    cout << "This is a simple 2 integer calculator. \n";
    cout << "When divising a value. The denominator may not = 0\n";
    //Take value user input 
   
   //First user input
    cout << "Select your first value: " << endl;
    cin >> x;
    //Second user input
    cout << "Select your second value: " << endl;
    cin >> y;

    //Take Character user input
   
   do{ //start of do-while loop
    cout << "Select the operation for your values (+, -, /, *): " << endl;
    cin >> symbol;
    
    if(symbol == '/' && y == 0) //Tells user they may not divide with denominator as zero
        cout << "User may not divide with a denominator of zero.\n";
    
   }while(symbol == '/' && y == 0); //boolean statement to maintain loop if conditions are met
   
    //switch statement for calculating both values
    switch(symbol){
        default: //default in case of input of non-designated char values
            cout << "Non-designated operation input value entered\n";
            break;
        case '+':
           cout << x + y << endl;
            break;
        case '-':
            cout << x - y << endl;
            break;
        case '/':
            cout << x / y << endl;
            break;
        case '*':
            cout << x * y << endl;
            break;
    }
            
    return 0;
}