/* The concept of a circular singly linked list is exactly the same as singly linked list expect that the last element is 
connected to the first element, instead of pointing to a null pointer */

/* Advantages of circular linked list */
// Any node can be a starting point. We can traverse the whole list by starting from any point. We just need to stop when the first node is visited again */
// Useful for implementation of queue. We can maintain a pointer to the last inserted node and front can alwaya be inserted as next of last
// Circular LL are useful in applicatiosn where it is necessary to go around the list. For example, when multiple applications are running on a PC, 
// it is common for the operating system to put the running applications on a list and then to cycle through them, giving each of them a slice of time to execute, and then making them wait while the CPU is given to another application. 
// It is convenient for the operating system to use a circular list so that when it reaches the end of the list it can cycle around to the front of the list.

// Mainly use din queue implementations. Hence insertion at beginning and end not necessary. But that can be achieved. 

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

Node *insertBegin(Node *head, int x, int &listLength)
{
	Node *temp = new Node(x);
	
	if(head == NULL)
	{
		temp->next=temp;
		return temp;
	}
		
	Node *curr = head;
	
	while(curr->next != head)
		curr = curr->next;
	
	temp->next = curr->next;
	curr->next = temp;
	head = temp;
	
	listLength++;
	return head;
}

Node *insertEnd(Node *head, int x, int &listLength)
{
	Node *temp = new Node(x);
	
	if(head == NULL)
	{
		temp->next=temp;
		return temp;
	}
		
	Node *curr = head;
	
	while(curr->next != head)
		curr = curr->next;
		
	curr->next = temp;
	temp->next = head;
	
	listLength++;
	return head;
}

void printList(Node *head)
{
	if(head == NULL)
		return;
		
	Node *curr = head;
	
	while(curr->next != head)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}

	cout << curr->data << endl;
}

Node *deleteBegin(Node *head, int &listLength)
{
	if(head == NULL)
		return head;
		
	Node *curr = head, *temp = head;
	
	while(curr->next != head)
		curr = curr->next;
		
	curr->next = head->next;
	head = curr->next;
	
	delete temp;
	listLength--;
	
	return head;
	
}

Node *deleteEnd(Node *head, int &listLength)
{
	if(head == NULL)
		return head;
		
	Node *curr = head;
	int cnt = 1;
	
	while(cnt <= listLength-2)
	{
		curr = curr->next;
		cnt++;
	}
	
	Node *temp = curr->next;
	curr->next = head;
	
	delete temp;
	listLength--;
	
	return head;
}

int main()
{	
	int listLength = 0;
	Node *head = new Node(34);
	listLength++;
	// head = deleteBegin(head, listLength);
	// listLength--;
	printList(head);


	 // head->next = new Node(20);
	 // listLength++;
	 // head->next->next = new Node(30);
	 // listLength++;
	 // head->next->next->next = new Node(40);
	 // listLength++;
	 // head->next->next->next->next = head;
	 // printList(head);
// 
	 // head = insertBegin(head, 50, listLength);
	 // head = insertEnd(head, 60, listLength);
	 // head = insertBegin(head, 500, listLength);
	 // head = insertEnd(head, 600, listLength);
	 // head = insertBegin(head, -500, listLength);
	 // head = insertEnd(head, -600, listLength);
// 
	 // printList(head);
// 
	// head = deleteBegin(head, listLength);

	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);
	// head = deleteEnd(head, listLength);

	// printList(head);

	return 0;
}