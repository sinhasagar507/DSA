/* 
	Problem Statement: 

*/
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

struct TreeNode { 
	int data; 
	TreeNode *lchild, *rchild; 
	TreeNode(int x) 
	{ 
		data = x; 
		lchild = rchild = NULL;
	} 
}; 


void traversal(Node *root)
{
	map<int, vector<int>> mp; 
	queue<pair,<TreeNode*, int>> q; 
	q.push({root, 0}); 
	
	while(!q.empty())
	{
		auto p = q.front(); 
		Node *curr = p.first; 
		int hd = p.second; 
		mp[hd].push_back(curr->data); 
		q.pop(); 
		if(curr->left != NULL)
			q.push({curr->left, hd-1}); 
		if(curr->right != NULL)
			q.push({curr->right, hd+1});  
	}
	
	// Print the map contents line by line 
	for(auto it: mp)
	{
		vector<int> v = it.second; 
		for(int x: v)
			cout << x << " "; 
		cout << endl; 
	}
}

void solve()
{   
	// Do Something 
	TreeNode* root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	traversal(root); 
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