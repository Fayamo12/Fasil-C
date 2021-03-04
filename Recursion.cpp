// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Fasil Tafesse
// Data Structures Spring, 2021
// Due 3/5/2021
// Lab 4 Recursion

#include <iostream>

using namespace std;

//Node structure of linked list
struct node
{
    double data;
    struct node* next;
};

class Stack
{
private:
    struct node* head; //head will point to the top of the stack
public:

    Stack()
    {
        head = NULL;
    }

    //To push a new element in stack
    void push(double val)
    {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = head;
        head = newnode;
    }

    //To show the top-most element in stack
    double top() 
    {
        if (head == NULL) 
        {
            cout << "\nStack is Empty";
            return -1;
        }
        return head->data;
    }

    //To pop topmost element from stack
    void pop() 
    {
        if (head == NULL)
            cout << "\nStack Underflow";
        else 
        {
            head = head->next;
        }
    }

    //To show if the stack is empty
    bool isEmpty() 
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

    //To print the elements of the stack
    void display()
    {
        struct node* ptr;
        if (head == NULL)
            cout << "\nStack is empty";
        else
        {
            ptr = head;
            cout << "\nStack elements are: ";
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }
        cout << endl;
    }

    ~Stack()
    {

    }

};

//Helper function for stack reversal
void insertAtBottom(Stack& s, double x)
{
    if (s.isEmpty()) 
    {
        s.push(x);
        return;
    }
    double y = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(y);
}

//To reverse the stack using recursion
void reverseStackRec(Stack& s)
{
    if (s.isEmpty()) return;

    double x = s.top();
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s, x);
}

//Main- driver function 
int main() 
{
    //Sample test case for stack reversal using recursion 
    Stack s;
    s.push(3);
    s.push(5);
    s.push(2021);
    cout << "Original Stack:";
    s.display();
    cout << endl;
    reverseStackRec(s);
    cout << "Stack after reversal:";
    s.display();
}

