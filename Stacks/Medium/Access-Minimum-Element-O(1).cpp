/*
Design a Stack that supports getMin() operation in O(1) time. Also, it should perform operations in O(1) auxiliary space
*/

// Here it is assumed that all elements are positive
// We can store minimum values as negative integers by keeping the minimum value as (value-currentmini)
// Access Minimum Elements in minimum time

#include <bits/stdc++.h>
using namespace std;
 		
int mini=-1;

struct MyStack {
 	stack<int> ms;

// Store (2*x-min) and (2*min-t) FOR WORKING WITH NEGATIVE VALUES 

// The following solution works only for POSITIVE values 
void pushElement(int x) {
 
	if(ms.empty()) 
	{
		ms.push(x);
		
		if(mini==-1)
			mini = x;
    	return;
	}
      
      
	else if(x>=mini)
		ms.push(x);
		
	else
	{
		ms.push(x - mini);
		mini = x;
	}		
}
 
void popElement() 
{
    if(ms.top()<0){
    	ms.top() = mini;
    	mini = mini+abs(ms.top());
    }
    ms.pop();
    
}

int topElement(){
    return ms.top();
}
 
int getMin(){
      return mini;  
}
};


// The solution isn't working for an empty stack. Look for a good workaround 
int main()
{
    MyStack s;
    s.pushElement(4);
    s.pushElement(3);
    s.pushElement(3);
    s.pushElement(5);
    s.pushElement(3);
    s.pushElement(2);
    s.pushElement(1);
    s.pushElement(6);
    s.pushElement(7);
    s.popElement();
    s.popElement();

	cout<<"Top Element from Stack: " << s.topElement();
 
    cout<<"Minimum Element from Stack: " << mini;
  
    return 0; 
}