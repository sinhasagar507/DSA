/* Basic method to describe a linked list */
#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
	
	// Default constructor
	Node()
	{
		data=0;	
		next=NULL;
	}
	
	// Paramterized constructor
	Node(int data)
	{
		this->data=0;
		this->next=NULL;
	}
};
	
class LinkedList
{
	Node *head;
	
	public:
		LinkedList()
		{
			head=NULL;
		}
		
		// Function to insert a node at the end of linked list
		void insertNode(int);
		
		// Function to print the given list
		void printList();
		
		// Function to delete the node at a given position
		void deleteNode(int);
};

// This is one of the ways through which I can access C++ methods outside their classes
void LinkedList::insertNode(int data)
{	
	Node *temp1=head, *temp2=NULL;
	
	// Create a new node
	Node* node = new Node(data);
	temp2=node;
	
	// Check if there exists a linked list
	if(head==NULL)
	{
		head=node;
		head->data=data;
		head->next=NULL;
	}
	
	temp1=head;
	
	// Initializing temp2 with the required parameters
	temp2=temp1->next;
	temp2->data=data;
	temp2->next=temp1->next->next;	
}

// This is one of the ways through which I can access C++ methods outside their classes
void LinkedList::printList()
{
	Node *temp1=head;
	
	// Check if list is empty
	if(head==NULL)
		cout<<"There are no elements in the linked list"<<endl;
		
	while(temp1->next != NULL)
	{
		cout<<temp1->data<<" ";
		temp1=temp1->next;
	}
}

// This is one of the ways through which I can access C++ methods outside their classes
void LinkedList::deleteNode(int nodeOffset)
{
	// Following is the declaration of utility pointers
	// One pointer is used for traversing the elements of linked list
	// The other one is used for required operation : insertion or deletion
	Node* temp1=head;
	Node* temp2=NULL;
	int Listlen=0, cnt=1;
	
	if(head==NULL)
	{
		cout<<"List Empty"<<endl;
	}
	
	// Find the length of the linked list
	while(temp1!=NULL)
	{
		temp1=temp1->next;
		Listlen++;
	}
	
	// Check if the position to be deleted
	// is less than the length of the linked list
	if(Listlen<nodeOffset)
	{
		cout<<"Index out of range"<<endl;
		return;
	}
	
	// Redeclare temp1
	temp1=head;
	
	// Traverse the list to find the node to be deleted
	while(cnt<nodeOffset)
	{
		// Update temp2
		temp2=temp1;
		
		// Update temp1
		temp1=temp1->next;
	}	
	
	temp2->next=temp1->next;
	
	// Delete temp1
	delete temp1;
}
	
// Searching a linked list
// Driver Code
int main()
{
	LinkedList list;
	
	// Inserting nodes
	list.insertNode(1);
	list.insertNode(2);
	list.insertNode(3);
	list.insertNode(4);
	
	cout<<"Elements of the list are : ";
	
	// Print list
	list.printList();
	cout<<endl;
	
	// Delete node at position 2
	list.deleteNode(2);
	
	cout<<"Elements of the list are: ";
	list.printList();
	cout<<endl;
	
	return 0;
}