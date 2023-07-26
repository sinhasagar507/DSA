/* 
Evaluating a Prefix Expression 
*/

#include<bits/stdc++.h>
using namespace std;

/* Time Complexity : Amortized Time Complexity = Theta(n) */


// Function to check for operand
bool isOperand(char ch)
{
	if(ch>=48 and ch<=57)
		return true;
		
	else
		return false;
}

// Function to check for operator
bool isOperator(char ch1)
{
	if(ch1=='+' or ch1=='-' or ch1=='*' or ch1=='/')
		return true;
		
	else
		return false;
}

int main()
{
	string s1;
	cin >> s1;
	

	stack<int> s;
	
	for(int i=s1.length()-1; i>=0; i--)
	{
		if(isOperand(s1[i]))
			s.push(s1[i]-48);

		else
		{
			// Pop the stack two times and store the operators 
			int a = s.pop();
			int b = s.pop();
			
			// Check the type of operator and perform the necessary computations
			if(s1[i]=='+')
			{
				// Perform Computation 
				int result = b+a;
				
				// Push the result into the stack 
				s.push(result);
			}
			
			else if(s1[i]=='-')
			{
				// Perform computation
				int result = abs(a-b);
				
				// Push the result into the stack 
				s.push(result);
			}
			
			else if(s1[i]=='*')
			{
				// Perform computation
				int result = b*a;
				
				// Push the result into the stack 
				s.push(result);
			}
			
			else if(s1[i]=='/')
			{
				// Perform computation
				int result = b/a;
			
				// Push the result into the stack 
				s.push(result);
			}
			
		}
	}
	
	cout << s.top() << endl;
}