#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e8 + 5;

template <class T>
	ll giveNcR(ll n, ll r){ll p = 1, k = 1; if(n-r < r) r = n - r; if(r != 0){while(r) {p *= n; k *= r; ll m = __gcd(p, k); p /= m; k /= m; n--; r--;}} else p = 1; 
	return p;}
	
ll power(ll x,ll y,ll m){if(y==0)return 1;ll p=power(x,y/2,m)%m;p=(p*p)%m;return (y%2==0)?p:(x*p)%m;}
ll nCr(ll n,ll r,ll m){if(r>n)return 0;ll a=1,b=1,i;for(i=0;i<r;i++){a=(a*n)%m;--n;}while(r){b=(b*r)%m;--r;}return (a*power(b,m-2,m))%m;}

struct TwoStacks{
		int *arr, cap, top1, top2;
		TwoStacks(int n){
		cap = n; arr = new int[n]; top1 = -1; top2 = cap-1;}
	};

void push1(int x)
	{
		if(top1 < top2-1)
		{
			arr[top1] = x;
			top1++;
			cout << "The element is pushed into thhe array through the first stack" << endl;
		}
		else
		{
			cout << "Overflow stack 1" << endl;
		}
	}
	
void push2(int x)
{
       if(top1 < top2-1)
       {
			arr[top2] = x;
			top2--;
			cout << "The element is pushed into the array through the second stack" << endl;
       }
       
       else
       {
			cout << "Overflow stack 2" << endl;
       }
}
	
int pop1()
{
	if(top1 >= 0)
	{
		int res = arr[top1];
		top1--;
		}
	else
	{
		cout << "Underflow stack 1" << endl;
	}
	return res;
}
	
int pop2()
{
	if(top2 < cap)
	{
		int res = arr[top2];
		top2++;
	}
	
        else
	{
	        cout << "Underflow stack 2" << endl;
		
	}
}
	
void solve()
{   
	// Do the necessary things
	// Like sending the value of n and all
}
	
int main()
{
    solve();
}
