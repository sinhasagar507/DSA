/*
Problem Statement - DP Unique Grid Paths: https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9
CodeStudio Link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

Thought Process:
-> Refer notes here: https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8/

The approach from memoization -> tabulation
1. Declare a base case
2. Express all states in for loops
3. Copy the recurrence and write again

If there is a previous row and a previous column, we can space optimize it
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
typedef long long int ll;

#define N2 100000
const int N = 2e5 + 5;
const ll N1 = 3 * 1e6;

template <class T>
ll giveNcR(ll n, ll r)
{
    ll p = 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            ll m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    return p;
}

ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}
ll nCr(ll n, ll r, ll m)
{
    if (r > n)
        return 0;
    ll a = 1, b = 1, i;
    for (i = 0; i < r; i++)
    {
        a = (a * n) % m;
        --n;
    }
    while (r)
    {
        b = (b * r) % m;
        --r;
    }
    return (a * power(b, m - 2, m)) % m;
}
int no_of_digits(ll n) { return 1 + floor(log10(n)); }

vector<int> graph[N + 1];
bool visited[N + 1];
int dist[N + 1];
int source[N + 1];
queue<int> node_queue;

void solve()
{
    // first circular tour
    int n;
    cin >> n;
    int petrol[n], distance[n];

    for (int i = 0; i < n; i++)
        cin >> petrol[i];

    for (int i = 0; i < n; i++)
        cin >> distance[i];

    int curr_petrol = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i;; j = (j + 1) % n)
        {
            curr_petrol += petrol[j] - distance[j];
            if (curr_petrol < 0)
            {
                i = j;
                break;
            }
            if (j == i)
            {
                cout << i << endl;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}