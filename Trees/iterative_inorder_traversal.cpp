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
	TreeNode *left, *right; 
	TreeNode(int x) 
	{ 
		data = x; 
		left = right = nullptr;
	} 
};

void iterativeInorderTraversal(TreeNode* root)
{
	stack<TreeNode*> st; 
	TreeNode* curr = root; 
	
	while(!st.empty() or curr!=nullptr)
	{
		while(curr != nullptr)
		{
			st.push(curr); 
			curr = curr->left; 
		}
		
		curr = st.top(); 
		cout << curr->data << " "; 
		st.pop(); 
		
		curr = curr->right; 
	}
}

void solve()
{   
	// Do Something 
	TreeNode *root = new TreeNode(10); 
	root->left = new TreeNode(20); 
	root->right = new TreeNode(30); 
	root->left->left = new TreeNode(40); 
	root->left->right = new TreeNode(50); 
	
	iterativeInorderTraversal(root); 
	
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