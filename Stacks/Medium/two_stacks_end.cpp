#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;
 
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

struct twoStacks
{
	int* arr; 
	int size; 
	int top1, top2; 
	
	public: 
		twoStacks(int n) // constructor
		{
			size = n; 
			arr = new int[n];
			top1 = -1; 
			top2 = size; 
		}
		
		// Method to push an element into stack1 
		void push1(int x)
		{
			// There is atleast one empty space for new element 
			if(top1 < top2 - 1)
			{
				top1++; 
				arr[top1] = x; 
			}
			
			else 
			{
				cout << "Stack Overflow"; 
				exit(1); 
			}
		}
		
		// Method to push an element x to stack2 
		void push2(int x)
		{
			// There is atleast one empty 
			// spce for new element 
			if(top1 < top2 - 1)
			{
				top2--; 
				arr[top2] = x; 
			}
			
			else
			{
				cout << "Stack Overflow"; 
				exit(1); 
			}
		}
		
		// Method to pop an element from first stack 
		int pop1()
		{
			if(top1 >= 0)
			{
				int x = arr[top1]; 
				top1--; 
				return x; 
			}
			
			else 
			{
				cout << "Stack Underflow"; 
				exit(1); 
			}
		}
		
		// Method to pop an element from second stack 
		int pop2()
		{
			if(top2 < size)
			{
				int x = arr[top2]; 
				top2++; 
				return x; 
			}
			
			else
			{
				cout << "Stack Underflow"; 
				exit(1); 
			}
		}
}; 

/* Driver program to test twoStacks class */


void solve()
{   
	// Do Something 
	twoStacks ts(5); 
	ts.push(1); 
	ts.push2(10); 
	ts.push2(15); 
	ts.push1(11); 
	ts.push2(7); 
	cout << "Popped element from stack1 is: " << ts.pop1(); 
	ts.push2(40); 
	cout << "\nPopped element from stack2 is: " << ts.pop2(); 
	return 0; 
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