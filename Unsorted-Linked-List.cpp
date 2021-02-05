// Unsorted-Linked-List.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Fasil Tafesse
// Data Structures Spring, 2021.
// Due 3/2/2021
// Lab 2 C + + Unsorted Linked List

#include<iostream> // Read header file

using namespace std;

struct node
{
	int data; // Declar item
	node* next; // Declar node
	node* prev;
}*Start;
struct node2
{
	int data;
	node2* next;
	node2* prev;
}*Start2;
class DLL
{
	/*	public:
			struct node
			{
				int data;
				node *next;
				node *prev;
			}*Start;
		public:
			struct node2
			{
				int data;
				node2 *next;
				node2 *prev;
			}*Start2;*/;
public:
	DLL()
	{
		Start = NULL;
		Start2 = NULL;
	}
	void InsertItem1(int);
	void InsertItem2(int);
	void display(void);
	void addbeg(int);
	void addspec(int, int);
	void Search(int);
	void DeleteItem(int);
	void ResetList();
	void GetLength();
	void MakeEmpty();
	void Union(node* list1, node2** list2);
};
void DLL::InsertItem1(int num) // Inserting node
{
	node* temp, * q;
	if (Start == NULL)
	{
		Start = new node;
		Start->data = num;
		Start->next = NULL;
		Start->prev = NULL;
	}
	else
	{
		q = Start;
		while (q->next != NULL)
			q = q->next;
		//To New Node at the End
		temp = new node;
		temp->data = num;
		temp->next = NULL;
		q->next = temp;
		temp->prev = q;  
		//q->next->prev = q;
	}
}
void DLL::InsertItem2(int num) // Inserting node to see if it works
{
	node2* temp, * q;
	if (Start2 == NULL)
	{
		//Start2->prev = NULL;
	}
	else
	{
		q = Start2;
		while (q->next != NULL)
			q = q->next;
		temp = new node2;
		temp->data = num;
		temp->next = NULL;
		q->next = temp;
		temp->prev = q;
	}
}
void DLL::display(void)
{
	node* q = Start;
	cout << "Elements of First List\n"; // Print the first element
	do {
		cout << q->data << "\t";
		q = q->next;
	} 
	while (q != NULL);

	node2* q2 = Start2;
	cout << "Elements in Second List\n"; // Print the second element
	do {
		cout << q2->data << "\t";
		q2 = q2->next;
	} while (q2 != NULL);
}
void DLL::addbeg(int num)
{
	node* temp;
	temp = new node;
	temp->data = num;
	temp->next = Start;
	temp->next->prev = temp;
	temp->prev = NULL;
	Start = temp;
}
void DLL::addspec(int,int)
{
}
void DLL::Search(int num)
{
	node* temp, * q = Start;
	int pos = 0, flag = 0;
	do {
		if (q->data == num)
		{
			flag = 1;
			pos++;
			break;
		}
		pos++;
		q = q->next;
	} while (q->next != NULL);
	if (flag == 1)
	{
		cout << "Element found at position:- " << pos; // Print the element
	}
	else
	{
		cout << "No Element Found"; // Unable to find the element
	}
}
void DLL::DeleteItem(int num)
{
	node* q = Start;
	node* prev = NULL;
	if (q->data == num) // Locate node to be deleted
	{
		q = q->next;
		delete q;
		cout << "Element Deleted";// Delete the first element
	}
	else
	{
		do {
			if (q->data == num)
			{
				prev = q;
				q = q->next;
				prev->next = q->next;
				delete q;
				cout << "Element Deleted";
				break;
			}
			q = q->next;
		} while (q->next != NULL);// Delete node at location ->next
	}
}
void DLL::GetLength()
{
	node* q = Start;
	int pos = 1;
	do {
		pos++;
		q = q->next;
	} while (q->next != NULL);
	cout << "Length:- " << pos;
}
void DLL::MakeEmpty()
{
	node* q = Start;
	if (q == NULL)
	{
		cout << "List is Empty"; // Post, list is empty
	}
	else
	{
		do {
			q = q->next;
			delete q;
			q = q->next;
		} while (q->next != NULL);
		cout << "List is Empty now";
	}
}
void DLL::ResetList()
{
	node* q = Start; // Current node has been initialized

}
void DLL::Union(node* list1, node2** list2)
{
	node* list1_curr = list1;
	node2* list2_curr = *list2;
	node* list1_next;
	node2* list2_next;
	while (list1_curr != NULL && list2_curr != NULL)
	{
		list1_next = list1_curr->next;
		list2_next = list2_curr->next;

		//list2_curr->next = list1_next;
		//list1_curr->next = list2_next;

		list1_curr = list1_next;
		list2_curr = list2_next;

	}
	*list2 = list2_curr;
	display(); // Code to print the item
}
int main() 
{
	DLL obj;
	node* temp{};
	node2** temp2{};
	int num, ch, pos;
	do {
		cout << "\n1.Insert Item into both lists";
		cout << "\n2. Display List";
		cout << "\n3. Add Beginning";
		cout << "\n4. Search";
		cout << "\n5. Delete Item";
		cout << "\n6. Get Length";
		cout << "\n7. Make List Empty";
		cout << "\n8. Union";
		cout << "\n9. Exit";
		cout << "\n Enter your your first item."; // Adding rhe first item
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\nEnter number for first element."; // Entering integer to find element
			cin >> num;
			obj.InsertItem1(num);
			cout << "\nEnter number for second Element."; // Entering integer to find the second element
			cin >> num;
			obj.InsertItem2(num);
			break;
		case 2:
			obj.display(); // Displying an object
			break;
		case 3:
			cout << "\nEnter any number."; 
			cin >> num;
			obj.addbeg(num);
			break;
		case 4:
			cout << "\nEnter Element to search:-";
			cin >> num;
			obj.Search(num);
			break;
		case 5:
			cout << "\nEnter Element to delete:-"; 
			cin >> num;
			obj.DeleteItem(num);
			break;
		case 6:
			obj.GetLength();
			break;
		case 7:
			obj.MakeEmpty();
			break;
		case 8:
			obj.Union(temp, temp2);
			break;
		case 9:
			exit(0);
			break;

		default:
			cout << "Enter Correct Choice";
			break;
		}
	} while (1);
	return 0; 
}