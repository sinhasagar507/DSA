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


// Tree Construct function. When this function is called, the entire tree is constructed  
TreeNode* treeConstruct(vector<int> v, int n, int idx) 
{ 
	TreeNode* root; 
	if(idx < n)
	{
		TreeNode* temp = new TreeNode(v[idx]);
		root = temp;
		root->lchild = treeConstruct(v, n, 2*idx+1, root->lchild);
		root->rchild = treeConstruct(v, n, 2*idx+2, root->rchild);
	}
	
	return root;
} 

// Height of a Tree. Its space complexity is O(h)
int getHeight(TreeNode *root)
{
	if(root==NULL)
		return 0;
		
	else
		return (1+max(getHeight(root->lchild), getHeight(root->rchild)));
}

void solve()
{   
	// Do Something 
	int n; 
	cin >> n; 
	vector<int> v(n); 
	
	for(int i = 0; i < n; i++)
		cin >> v[i]; 
	
	TreeNode* root = treeConstruct(v, n, 0); 
	cout << getHeight(root) << "\n"; 
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