#include<iostream>
using namespace std;
#include<fstream>
#include<string>

//stores file contents
struct Node{
	string word;
	Node *next;
};
//used as compare for replicas
struct Check{
	string word;
	Check *next;
	int flag = 0; //checks number of times word is in a file
};

//-----------------------
//-function declarations-
//-----------------------
void print_list(Node* head); //prints out file contents
int search_list(Node* head, string name); //searches list and returns number of times a word is found

bool verify_same(Check* head, string str); //verifies how many times a word is in a file

//------------------
//-------Main-------
//------------------
int main(int argc, char *argv[]){ //takes argument from command line
	//head and temp pointers to linked lists
	Node *head_Node = NULL, *temp_Node = NULL;
	Check *head_Check = NULL, *temp_Check = NULL;

	//variable declarations
	string line, item;
	ifstream fin;
	int co = 0; //counts number of times in file

		fin.open(argv[1]); //first time opening file

		if(!fin.is_open()){ //checks if file opened
			cout << "File could not open\n";
			return -1;
		}

		while(fin >> item){  //input contents into both linked lists
			temp_Node = new Node;
			temp_Node->word = item;
			temp_Node->next = head_Node;
			head_Node = temp_Node;

			temp_Check = new Check;
			temp_Check->word = item;
			temp_Check->next = head_Check;
			head_Check = temp_Check;
		}
		fin.close();

		cout << "\n~FILE CONTENTS~\n";
		print_list(head_Node);
		cout << endl;

		cout << endl << endl;

		fin.open(argv[1]); //second time opening file

		while(fin >> item){
			if(verify_same(head_Check, item) == true){ //prevents program from printing a duplicate word
				continue; //contines with while loop without proceeding to search_list function
			}
			co = search_list(head_Node, item);
			cout << item << " [ " << co << " ]" << endl; // prints 'String' [ '#' ]
		}
		
		fin.close();

	return 0;
}
//----------------------
//-function definitions-
//----------------------
void print_list(Node* head){ 

	if(head == NULL)
		return;
	print_list(head->next); //prints out list

	cout << head->word << " ";
}

int search_list(Node* head, string name){
	Node* temp = head;
	int co = 0;

	while(temp != NULL){ //looping through file for matching strings
		if(temp->word == name)
			co++;
		temp = temp->next;
	}
		return co; //returns number of times string found in file
}

bool verify_same(Check* head, string str){
	Check* temp = head;
	bool sign = false;

	while(temp != NULL){
		if(temp->word == str) //if string matches, incriment the string flag value in struct Check
			temp->flag++;
		if(temp->flag >= 2) //if String flag 2 or great then return sign as true
			sign = true;
		temp = temp->next; //incriments to next Check node
	}
	return sign;
}