#include <bits/stdc++.h>
using namespace std;


int main()
{	
	int n;
	long long int y;
	cin >> n >> y;
	
	vector<long long int> v(n);
	unordered_map<long long int, int> freq;
	
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		freq[v[i]]++;
	}
	
	int maxfreq=1;
	
	for(int i=0; i<n; i++)
		maxfreq = max(maxfreq, freq[v[i]]);
	
	cout << maxfreq << endl;

	return 0;
	
}