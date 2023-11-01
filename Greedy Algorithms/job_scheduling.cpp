/*
Problem Statement: Job Scheduling Algorithm 
Given an array of jobs where every job has a deadline and associated profit 
if the job is finished before the deadline. It is also given that every job takes 
a single unit of time, so the minimum possible deadline for any job is 1. 
How to maximize total profit if only one job can be scheduled at a time.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
const int CHAR = 256; 
 
template <class T>
	ll giveNcR(ll n, ll r){ll p = 1, k = 1; if(n-r < r) r = n - r; if(r != 0){while(r) {p *=n; k *=r; ll m = __gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; 
	return p;}
	
 
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}
int no_of_digits(ll n){return 1 + floor(log10(n));}
 
vector<int> graph[N+1];
bool visited[N+1];
int dist[N+1];
int source[N+1];
queue<int> node_queue;

// A structure to represent a job 
struct Job
{
	char id; // Job Id 
	int deadline; // Job deadline 
	
	// Profit if job gets over before or 
	// by the due time 
	int profit; 
}; 

// This function is used for sorting 
// jobs according to profit 
bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

// Returns the order of jobs to maximize the profit 
void printJobScheduling(vector<Job> &v, int n)
{
	// Sort all jobs according to decreasing 
	// order of profit 
	sort(v.begin(), v.end(), comparison); 
	
	vector<int> result(n); // to store result(sequence of jobs)
	vector<int> slot(n, false); //  to keep track of free time slots, and initialize all slots to be free
	
	// Iterate through all given jobs 
	for(int i = 0; i < n; i++)
	{
		// Find a free slot for this job 
		// (Note, that we start from the last possible slot). Agr ek job ka jo max. slot haina vo bhrdo and aage bdho 
		// I don't have to leave any given day
		// Also if the deadline of a particular job exceeds the total no of jobs, 
		// we do it earlier cause we can't waste a day without generating profit 
		for(int j = min(n, v[i].deadline); j >= 0; j--) 
		{
			if(!slot[j]){ // 
				result[j] = i; 
				slot[j] = true; 
				break;
			}
		}
	}
	
	// Print the result 
	for(int i = 0; i < n; i++)
	{
		// Free slot found 
		if(slot[i])
			cout << v[result[i]].id << " "; 
	}
	
	cout << endl; 
}

void solve() 
{   
	// Do Something
	// No of jobs 
	int n; 
	cin >> n; 
	vector<Job> v(n); 
	
	for(int i = 0; i < n; i++)
	{
		int identity; 
		int dead;
		int pr; 
		
		cin >> identity >> dead >> pr;  
	}
	
	printJobScheduling(v, n); 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int t;
	cin >> t;
 
	while(t--){
	solve(); 
	}
}