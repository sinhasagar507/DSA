#include <bits/stdc++.h>
using namespace std;

/* // The following piece of code will definitely break under space and time limitations 
void kPeriodic(string s, int K){
        // code here
        
        int length = s.length();
        
        if((length%K) == 0)
        {
            // Do something 
            int cntDiff=0; // Counts the unique number of characters in the string 
            unordered_map<char, int> us; // Stores a single occcurence of each unique character in the string 
            vector<char> v;
            for(int i=0; i<length; i++)
            {
                if(us.find(s[i]) == us.end())
                {
                    cntDiff++;
                    us[s[i]]++;
                    v.push_back(s[i]);
                }
                
                else
                    us[s[i]]++;
            }
            
            if(cntDiff!=K)
                cout << "-1" << endl;
                
            else
            {
                // Check if frequency of each character is same 
                bool flg = true;
                int currFreq = us[s[0]];
                for(auto it: us)
                {
                    if(it.second != currFreq)
                    {
                        flg = false;
                        break;
                    }
                }
                
                if(flg == false)
                	cout << "-1" << endl;
                
                else
                {
                    string s1 = "";
                    int moves = (length/K);
                    
                    for(int i=0; i<moves; i++)
                    {
                        for(auto it: v)
                        {
                        	cout << it << " ";
                            s1 += it;
                        }
                    }
                    
                }
            }
        }
        
        else
           cout << "-1" << endl;
}
*/ 


// The following piece of code would do wonders 
string kPeriodic(string s, int k)
{
	int n = s.size();
	int block_size = __gcd(n, k);
	map<char, int> mpp;
	
	for(auto it: s)
	{
		mpp[it]++;
	}
		
	int no_of_blocks = n / block_size; 
	for(auto it: mpp)
	{
		if(it.second % no_of_blocks != 0)
			return "-1";	
	}
	
	
	string ss = "";
	
	for(auto it: mpp)
	{
		char c = it.first;
		
		int howManyTimes = it.second / no_of_blocks;
		
		while(howManyTimes--)
		{
			ss += c;
		}
	}
	
	string ans = "";
	
	while(no_of_blocks--)
	{
		ans += ss;
	}
	
	return ans;
}

int main()
{	
	string s;
	int K; 
	cin >> s >> K;
	cout << kPeriodic(s, K) << endl;

	return 0;
	
}