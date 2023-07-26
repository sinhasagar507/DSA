/* Entire Linked List discussion. The primitive way. There is no inherent structure in linked list. Its entirely stored in dynamic memory(heap) */
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	
	// define a self-referencing pointer 
	Node* next;
	
	// define a node constructor
	Node(int x)
	{
		data=x;
		next=NULL;
	}	
};

// When asked for reversing a linked list, use this thing. Insertion at the beginning. 
// When I don't initialize using the 'new' keyword, only a pointer is created. 
// Insertion and deletion at specific positions is accomplished. It will be updated later. 


Node *reverseN(Node *head, int n)
{
	Node *curr=head, *prevFirst = curr;
	bool firstPass = true;
	
	while(curr != NULL)
	{
		int count = 0;
		Node* first = curr, *prev=NULL, *next=NULL;
		
		while(count < n and curr != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		
		if(firstPass)
		{
			head = prev;
			firstPass = false;
		}
		
		else
		{
			prevFirst->next = prev;
			prevFirst = first;
		}
			
	}
	
	return head;
}

void printList(Node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main()
{	
	int listLength = 0;
	
	Node *head = new Node(10);
	listLength++;
	
	head->next = new Node(20);
	listLength++;
	
	head->next->next = new Node(30);
	listLength++;
	
	head->next->next->next = new Node(40);
	listLength++;
	
	head->next->next->next->next = new Node(50);
	listLength++;
	
	int n; cin >> n;
	head = reverseN(head, n);
	
	printList(head);
	
	return 0;
}