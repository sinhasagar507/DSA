/* Entire Linked List discussion. The primitive way. There is no inherent structure in linked list. Its entirely stored in dynamic memory(heap) */
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	
	/* define a self-referencing pointer */
	Node* next;
	
	/* define a node constructor */
	Node(int x)
	{
		data=x;
		next=NULL;
	}	
};

/*
When asked for reversing a linked list, use this thing. Insertion at the beginning. 
When I don't initialize using the 'new' keyword, only a pointer is created. Memory space is allocated for that pointer using the 'new' keyword.
Insertion and deletion at specific positions is accomplished. It will be updated later. 
*/

Node *insertBegin(Node *head, int x, int &listLength)
{
	Node *temp = new Node(x); 

	temp->next = head;
	head = temp;
	
	listLength++;
	return head;	
}

/* Insertion at end of single-linked list */
Node *insertEnd(Node *head, int x, int &listLength)
{
	Node *temp = new Node(x);
	Node *curr = head;
	
	if(head == NULL)
		return temp;
		
	else
	{
		while(curr->next != NULL)
			curr = curr->next;
	
		
		curr -> next = temp;
	}
	
	listLength++;
	return head;
}

/* Insert at a given position */
Node *insertPosition(Node *head, int pos, int data, int &listLength)
{
	
	Node *temp = new Node(data);
	Node *curr = head;
	int cnt=1;
	
	if(pos == 1)
		return insertBegin(head, data, listLength);
		
	else if(pos == listLength+1)
		return insertEnd(head, data, listLength);

	else if(pos > listLength+1)
		return head;
		
	else
	{
		while(cnt <= pos-2)
		{
			curr = curr->next;
			cnt++;
		}
		
		temp->next=curr->next;
		curr->next=temp;
	}
	
	listLength++;
	return head;
}

/* Insertion at a given position(enhanced version) */
   Node *insertPosition(Node head, int pos, int data)
   {
   		Node temp = new Node(data);
   		if(pos==1)
   		{
   			temp->next=head;
   			return head;
   		}
   		
   		Node *curr=head;
   		
   		for(int i=1; i<=pos-2 and curr!=NULL; i++)
   			curr = curr->next;
   	
   		
   		if(curr == null)
   			return head;
   			
   		temp->next = curr->next;
   		curr->next = temp;
   }
*/

/* Deletion at beginning */
Node* deleteBegin(Node *head, int &listLength)
{
	Node *temp;
	
	if(head == NULL)
		return head;
		
	temp = head;
	head = head->next;
	
	delete temp;
	
	listLength--;
	return head;
}


/* Deletion at end. Why its behaving in this manner over here? */
Node *deleteEnd(Node *head, int &listLength)
{
	Node *curr;
	
	if(head == NULL)
		return head;
		
	if(head->next == NULL)
	{
		delete head;
		return NULL;
	}
		
	curr = head;
	
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	
	delete curr;
	
	listLength--;
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

/* Reversal of a singly linked list */
Node *reverse(Node *head)
{
	if(head == NULL or head->next == NULL)
		return head;
		

	Node *curr = head, *prev = NULL, *next = NULL;
		
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
		
	return prev;
}

int main()
{	
	// Also try maintaining a head pointer 
	Node *head=NULL;
	int listLength=0;
	
	head = insertBegin(head, 20, listLength);
	head = insertBegin(head, 30, listLength);
	head = insertBegin(head, 40, listLength);
	head = insertEnd(head, 60, listLength);
	head = insertEnd(head, 70, listLength);
	head = insertEnd(head, 80, listLength);
	head = insertPosition(head, 7, 900, listLength);
	head = deleteBegin(head, listLength);
	head = deleteBegin(head, listLength);
	head = deleteBegin(head, listLength);
	head = deleteBegin(head, listLength);
	head = deleteBegin(head, listLength);
	head = deleteBegin(head, listLength);
	
	
	printList(head);
	
	/*....*/cout<<endl;
	/*....*/head = deleteBegin(head);
	/*....*/printList(head);
	/*....*/cout<<endl;
	/*....*/head = deleteEnd(head);
	/*....*/printList(head);
	
	return 0;
}