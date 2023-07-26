/* 
Circular Queue-BASED Implementation  
*/



// Here the rear pointer behaves in a similar manner as the top pointer of a stack. If the queue is empty, it should simply point to -1 
// The front pointer, on the other hand, should always point to the index from where the element will be first deleted

#include<bits/stdc++.h>
using namespace std;


// Check if the queue is full
// bool isFull(int &cap, int &size)
// {
	// return (cap==size);
// }

bool isEmpty(int &front, int &rear)
{
	// return rear==front-1;
	return rear==-1;
}

bool isFull(int &cap, int &rear, int &front)
{
	return (rear+1)%cap==front and !(isEmpty(front, rear));
}

	
// Check if the queue is empty 
// bool isEmpty(int &size)
// {
	// return size==0;
// }



// GetRear
// int getRear(int &front, int &size, int &cap)
// {
	// if(isEmpty(size))
		// return -1; 
// 	
	// else
		// return (front+size-1)%cap;
// }


// Get the next rear element's index
int getRear(vector<int> &v, int &rear, int &cap)
{
	return v[rear];
}

// Get the next element from the start 
int getFront(vector<int> &v, int &cap, int &front)
{
	return v[front];
}

// Enqueue operation 
// vector<int> enqueue(vector<int> &v, int &cap, int &size, int &front, int x)
// {	
// 
	// if(isFull(cap, size))
	// {
		// cout << "The queue is full" << endl;
	// }
// 	
	// else{
	// int rear = getRear(front, size, cap);
	// rear = (rear+1)%cap;
// 	
	// v[rear] = x;
	// size++;
	// }
// 	
	// return v;
// }

vector<int> enqueue(vector<int> &v, int &cap, int &front, int &rear, int x)
{	

	if(isFull(cap, rear, front))
	{
		cout << "The queue is full" << endl;
	}
	
	else{
	rear = (rear+1)%cap;
	v[rear] = x;

	}
	
	return v;
}
	
// Dequeue operation
// vector<int> dequeue(vector<int> &v, int &cap, int &size, int &front)
// {
	// if(isEmpty(size))
	// {
		// cout << "The queue is empty" << endl;
	// }
// 	
	// else{
	// front = (front+1)%cap;
	// size--;
	// }
// 		
	// return v; 
// 	
// }

vector<int> dequeue(vector<int> &v, int &cap, int &front, int &rear)
{
	if(isEmpty(front, rear))
	{
		cout << "The queue is empty" << endl;
	}
	
	if(front==rear)
	{
		rear=-1;
	}
	
	else{
		front = (front+1)%cap;
	}
	
	
		
	return v; 
	
}

int main()
{
	int cap;
	cin >> cap;
	int front=0, rear=-1;
	vector<int> v(cap);
	
	// cout << getFront(front, rear) << endl;
	
	v = enqueue(v, cap, front, rear, 6);
	
	v = enqueue(v, cap, front, rear, 4);
	
	v = enqueue(v, cap, front, rear, 5); 
	
	v = enqueue(v, cap, front, rear, 8);
	
	v = enqueue(v, cap, front, rear, 9);
	
	v = enqueue(v, cap, front, rear, 10);
	// cout << getRear(front, rear, cap) << endl;
	
	// v = enqueue(v, cap, size, front, 10);
	// v = dequeue(v, cap, size, front, rear);
	
	v = dequeue(v, cap, front, rear);
	
	
	v = dequeue(v, cap, front, rear);
	
	v = dequeue(v, cap, front, rear);
	
	v = dequeue(v, cap, front, rear);
	
	v = dequeue(v, cap, front, rear);
		
	// cout << getFront(front, rear) << endl; 
	
	
	for(auto it : v)
		cout << it << " ";
	cout << endl;

}

