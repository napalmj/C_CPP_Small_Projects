#include<iostream>
using namespace std;

int main()
{
   char str[20]; 
    cout << "Enter Your Name::"; 
  
    // see the use of getline() with array 
    // str also replace the above statement 
    // by cin >> str and see the difference 
    // in output 
    cin.getline(str, 20); 
  
    cout << "\nYour Name is:: " << str; 

    for(int i = 0; i<20; i++){
    	if(str[i] != '\0')
    		cout << str[i] << " " << endl;
    	else
    		break;
    }
    return 0;

}