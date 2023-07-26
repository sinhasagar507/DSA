// Basic method to create a double-linked list in C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *prev, *next;
	
	Node(int d)
	{
		data = d;
		prev = NULL;
		next = NULL;
	}
};

Node *insertBegin(Node *head, int data)
{
	Node *temp = new Node(data);
	
	if(head == NULL)
		return temp;
		
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	
	return head;
}

Node *insertEnd(Node *head, int data)
{
	Node *temp = new Node(data);
	Node *curr = head;
	
	if(head == NULL)
		return temp;
		
	else
	{
		while(curr->next != NULL)
			curr = curr->next;
			
		curr->next = temp;
		temp->prev = curr;
	}
	
	return head;
}

void printList(Node *head)
{
	if(head != NULL)
	{
		cout << head->data << " ";
		printList(head->next);
	}
}

Node *reverse(Node *head)
{
	if(head == NULL or head->next == NULL) 
		return head;
	
	Node *prev = NULL, *curr = head;
	
	while(curr != NULL)
	{
		prev = curr->prev;
		curr->prev = curr->next;
		curr->next = prev;
		curr = curr->prev;
	}
	
	return prev->prev;
}

int main()
{
	Node *head = NULL;
	head = insertBegin(head, 20);
	head = insertEnd(head, 30);
	head = insertEnd(head, 40);
	head = insertBegin(head, 50);
	
	printList(head);
	cout << endl;
	
	head = reverse(head);
	
	printList(head);
		
	return 0;
}