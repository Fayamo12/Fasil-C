// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Fasil Tafesse
// Data Structures Spring, 2021
// Due 2/17/2021
// Lab 3 Stack

#include <iostream>
using namespace std;

int max_size;
struct node//node that is stored in the stack
{
	double value;
	struct node* next;
};
class Stack //this class Stack will contain a linked list
{
private:
	struct node* head; //the top most element of the stack
public:
	Stack(); //constructor
	~Stack(); //destructor
	void push(double element);
	void pop();
	double top();
	bool isEmpty();
	bool isFull();
	int numOfElements();
	void printELements();
};
Stack::Stack()//this constructor will initialize the Stack list
{
	head = NULL;
}
Stack::~Stack()//Destructor
{
	node* current = head; //pointer to head
	node* next; //pointer to store next node
	while (current != NULL)
	{
		next = current->next;
		(current); //free up the memory
		current = next;
	}
	/* deref head_ref */
	head = NULL;
}
void Stack::push(double val)//adding element in the stack at the top
{
	int count = 0; //stores number of elements in the stack
	node* iter = head; // it will iterate
	while (iter != NULL) //count the number of elements in the stack
	{	count++; //increment the count
		iter = iter->next;
	}
	if (count >= max_size) 
	{
		cout << "Stack is full" << endl;
		return; //postcondition
	}
	node* newObject; //creating new node
	newObject = new node;
	newObject->value = val; //adding value to the new node
	newObject->next = head; //putting head as the next element to the new node
	head = newObject; // putting head = newObject 
	return;
}
void Stack::pop()//removing the top most element from the stack
{
	if (head == NULL) 
		return;
	else 
	{
		head = head->next; //pointing head to the next element of stack
		return;
	}
}                 
double Stack::top() //Return the top element of the stack
{
	if (head == NULL) //the stack is isEmpty
		return NULL;

	return head->value;
}
bool Stack::isEmpty() //this function will check whether the stack is empty or not
{
	if (head == NULL) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}
bool Stack::isFull()
{
	return false;
}
int Stack::numOfElements()//this function will calculate the number of elements in the stack
{
	int count = 0;
	node* iter = head; // iterator
	while (iter != NULL) 
	{
		count++; //increment the count
		iter = iter->next;
	}
	return count; 
}
void Stack::printELements()//print all the elements of the stack
{
	node* iter = head; // iterator
	cout << "Printing the elements of the Stack:" << endl;
	while (iter != NULL) 
	{ 
		cout << (iter->value) << endl;//count the number of elemenets in the stack
		iter = iter->next;
	}
	return; 
}
int main()
{
	Stack* stack = new Stack();
	cout << "Please enter the maximum size of stack :"; //taking input maximum size of the stack 
	cin >> max_size;
	cout << endl;
	cout << "Stack is empty or not: " << (((stack->isEmpty()) == 1 ? "Empty" : "Not Empty")) << endl;//check whether the stack is empty of not
	cout << endl;
	cout << "Pushing elements in the stack " << endl;//pushing elements to the stack
	stack->push(3.5);
	stack->push(4.5);
	stack->push(5);
	stack->push(6.5);
	stack->push(1.5);
	cout << "Stack is empty or not: " << (((stack->isEmpty()) == 1 ? "Empty" : "Not Empty")) << endl;//check whether the stack is empty of not
	cout << endl;
	if (stack->numOfElements() == max_size)//precondition
		cout << "Stack is Full\n";//Checking if Stack is full or not
	else 
		cout << "Stack is not full\n";
	cout << "Number of elemnts in the Stack: " << (stack->numOfElements()) << endl; //print number of elements in the stack
	cout << endl;
	stack->printELements();//print the elements of the stack
	cout << endl;
	cout << "Popping elements from the stack twice" << endl;//pop elements of the stack
	stack->pop();
	stack->pop();
	cout << "Top element of stack: " << stack->top() << endl;//Checking the top element of stack
	cout << "Stack is empty or not: " << (((stack->isEmpty()) == 1 ? "Empty" : "Not Empty")) << endl;//check whether the stack is empty of not
	cout << endl;
	cout << "Number of elements in the Stack: " << (stack->numOfElements()) << endl;//print number of elements in the stack
	cout << endl;
	stack->printELements();//print the elements of the stack
	cout << endl;
	return 0;
}