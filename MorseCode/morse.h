#ifndef MORSE_H
#define MORSE_H

//Intereface class for user
#include<iostream>
class Morse {
	private:
		class Internal; //for decoding user input
		Internal *internal;

	public:
		Morse();
		~Morse();
		void Interface();

};

#endif
