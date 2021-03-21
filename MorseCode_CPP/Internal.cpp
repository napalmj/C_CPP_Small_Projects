#include "morse.h"
#include<iostream>
#include<string>
using namespace std;


enum enumAlpha_Upper{A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};
enum enumAlpha_Lower{a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};


const int size = 100;

class Morse::Internal
{
private:
    //symbol key for morse code:
	//A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z : 1,2,3,4,5,6,7,8,9,0
	string Alpha_M[26] = {".-",/*A*/"-...",/*B*/"-.-.",/*C*/"-..",/*D*/".",/*E*/"..-.",/*F*/"--.",/*G*/"....",/*H*/"..",/*I*/".---",/*J*/"-.-",/*K*/".-..",/*L*/"--",/*M*/"-.",/*N*/"---",/*O*/".--.",/*P*/"--.-",/*Q*/".-.",/*R*/"...",/*S*/"-",/*T*/"..-",/*U*/"...-",/*V*/".--",/*W*/"-..-",/*X*/"-.--",/*Y*/"--..",/*Z*/};
	string Digit_M[10] = {"-----",/*0*/".----",/*1*/"..---",/*2*/"...--",/*3*/"....-",/*4*/".....",/*5*/"-....",/*6*/"--...",/*7*/"---..",/*8*/"----.",/*9*/};
	char Alpha_Upper[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char Alpha_Lower[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char Digit[10] = {'0','1','2','3','4','5','6','7','8','9'};

	char inputStr[size]; //holds the string of user
	string codeStr[size]; //holds the coded string
	int inputStrCounter;
public:
	void encode();
	void decode();
	void getString();
	void menuItems();
	void menuSwitch();
	
};

//reference chart
//A-0,B-1,C-2,D-3,E-4,F-5,G-6,H-7,I-8,J-9,K-10,L-11,M-12,N-13,O-14,P-15,Q-16,R-17,S-18,T-19,U-20,V-21,W-22,X-23,Y-24,Z-25

void Morse::Internal::encode()
{
	int i, j, k = 0, c = inputStrCounter;

	for(i = 0; i < size; i++)
	{
		if(inputStr[i] != '\0')
		{
			if(inputStr[i] == ' ')
			{
				codeStr[i] = ' ';
				continue;
			}
			for(j = 0; j < 36; j++)
			{ //cout << "Count J " << j;
				if(j < 26)
				{
					if(inputStr[i] == Alpha_Lower[j])
					{
						codeStr[i] = Alpha_M[j];
						break;
					}
					if(inputStr[j] == Alpha_Upper[j])
					{
						codeStr[i] = Alpha_M[j];
						break;
					}
				}else{
					if(inputStr[i] == Digit[k])
					{
						codeStr[i] = Digit_M[k];
						k++;
						break;
					}
				}
			}
		}
	}
	cout << "Input encoded as: \n";
	int l;
	for(l = 0; l<inputStrCounter; l++)
		cout << codeStr[l] << " ";
	cout << endl;

}
void Morse::Internal::decode()
{

}
void Morse::Internal::getString()
{
	int i = 0;
	inputStrCounter = 0;
	char str[100]; //char to store string from user

	cout << "Input string: ";
	cin.ignore();
	cin.getline(str,100); //gets string from user

	for(i = 0; i < size; i++){
		if(str[i] != '\0'){ 
			inputStr[i] = str[i]; //stores chars in the char ptr passed as parameter
			inputStrCounter++;
		}else
			break;
	}
}
void Morse::Internal::menuItems() //instructing user for how to proceed in program
{
	cout << "This program is designed to convert from or to morse code.\n";
	cout << "Options for this program are as follows:\n";
	cout << "1. Decode\n2. Encode\n";
	cout << "\nSelect 1 or 2 and press 'Enter' too continue...\n";
}
void Morse::Internal::menuSwitch()
{
	menuItems();
	int choice = 0; //stores choices
	cin >> choice;

	switch (choice)
	{
		case 1:
		getString();
		decode();
		break;
		case 2:
		getString();
		encode();
		break;
		
		default:
			cout << "Enter corret option\n";
	}
}
Morse::Morse()
{

}
Morse::~Morse()
{

}
void Morse::Interface()
{
	Internal internal;

	internal.menuSwitch();
}




