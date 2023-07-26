/* Parantheses Verification */
#include<bits/stdc++.h>
using namespace std;

/* Time Complexity of this algorithm is O(Length(String)) */


bool matchMaking(char ch, char ch1)
{
	if(ch == '(' and ch1 == ')')
		return true;
	else if(ch == '{' and ch1 == '}')
		return true;
	else if(ch == '[' and ch1 == ']')
		return true;
	else
		return false;
}

void solve()
{   
	string s;
	cin >> s;
	
	stack<int> s1;
	bool f = false;
	
	for(int i = 0; i < s.length(); i++)
	{
		// We only push the opening brackets into the stack 
		if(s[i] == '(' or s[i] == '{' or s[i] == '[')
			s1.push(s[i]);
		else
		{	

			// This condition stands when the string is directly composed of closing brackets or its is empty 
			if(s1.empty())
				break;
			else
			{
				f = matchMaking(s1.top(), s[i]);
				if(!f)
					break;
				else
					s1.pop();
			}
		}

	}		
			// This condition is used when both the string and stack is empty 
			if(s1.size() == s.length())
				f = true;

	
	cout << f << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	
	while(t--)
	{
		solve();
	}	
}


