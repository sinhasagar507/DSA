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

/*
 Union: A type of structure that can be used where the amount of memory used is a key factor. 
		Similar to the structure, the union can contain different types of data types 
		Each time a new variable is initialized from the union it overwrites the previous in C 
		
		This is most useful when the type of data being passed through functions is unknown, 
		using a union which contains all possible data types can remedy this problem
		
		It is declared by ising the keyword "union"
		
		  
*/


union Money
{
	/* data */ 
	int rice; // 4 
	char car; // 1 
	float pounds; // 4 
}; 

/*
Enums
- Enums are user-defined types that consist of named integral constants 
- It helps to assign constants to a set of names to make the program easier to 
  read, maintain and understand 
- An enumeration is declared by using the keyword "enum", it is a user-defined data 
  type that consists of a set of named integer constants 
- Each constant within the enum is called an "enumerator", and it represents a 
  distinct value within the enumeration. Enums provide a way to assign meaningful names to integral values, enhancing code readability 
  and maintainability. 
- Advantages of using Enums: Enhance code readability. 

*/ 
 

void solve()
{   
	// Do Something 
	// Suppose there is barter system AND I want to pay using rice, car OR pounds at a time 
	// but definitely not all 3 of them. So what do I do. I use the UNION data structure in that case 
	
	Money m1; 
	m1.rice = 34; 
	m1.car = 'x'; 
	cout << m1.rice << endl; // When I print this I get a garbage value as output  
	cout << m1.car << endl;  // And when I print this I get what I desired 
	
	enum Meal{breakfast, lunch, dinner}; 
	cout << lunch << endl; 
	
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