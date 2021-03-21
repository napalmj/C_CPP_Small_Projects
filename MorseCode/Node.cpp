#include<iostream>
#include<string>

class Node 
{
private:
	char input;
	Node *next;
public:
	char getData(Node *n);
	void setData(char in);
	void inList(Node *head, char)
};

char Morse::Node::getData(Node *n)
{
	return n->input;
}
char Morse::Node::setData(char in)
{
	next->input = in;
}