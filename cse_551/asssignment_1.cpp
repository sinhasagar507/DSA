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

void solve()
{   
	// Do Something 
	
	// A stable-matching scenario based National Resident Matching Program (NMRP) algorithm 
	// I can just store the preferences in a 2D array for now 
	// In the problem statement, its properly given that there are more students graduating (n) than there are slots in the available hospitals (m) 
	// So So m*no_of_slots_each_hospital != n*order_of_preferences 
	// I am assuming that each hospital lists out the same no. of student preferences AND each student lists out the same no. of hsopital preferences 
	
	int n, m; // No. of students, no. of hospitals  
	cin >> n >> m; 
	
	vector<vector<int>> student_pref(n, vector<int>(m)); 
	vector<vector<int>> hospital_pref(m, vector<int>(n)); 
	vector<bool> student_slot(n, false), hospital_slot(m, false); 
	
	
	// Hospital ke paas multiple slots toh hain hi 
	// And assigning each student to atmost one hospital taaki usse saare hospital slots bhr jaaye, yeah that would be good 
	
	for(int i = 0; i < n; i++)
	{
		// Check if a particular hospital slot is empty AND that stays on his list of preferences 
		// How would I be check the preferences list? 
			// I would iterate over each of the preferences AND 3 scnearios may occur 
			// If its student's current preference AND hospital's current preference as well, its a match AND I set both slots to true
			// Agr vo student ka preference hai but hospital ka nai hai (toh dedo if slot is available), then kya kruin? And vo student ka nai hai, but hospital ka hai? 
			// Abb ye case bhi aayega ki student wants a slot AND that slot is already filled by someone else 
			// If its none of their current preferences, I won't fill it 
	}


	
	
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