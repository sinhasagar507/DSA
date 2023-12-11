#include<stdio.h>
#include<iostream>
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

/*
Thought Process
1. Since the question is based on maximum merit points, the first approach which comes to my mind
   is a greedy one. Let's perform dry run on a particular example:
	10 40 70
	20 50 80
	30 60 90
   If I proceed greedily according to the constraints that no two merit points be same, I will pick up

*/

// Recursive Sol
/*
int ninjaPoints(vector<vector<int>> &points, int n, int last)
{
	// Base Case
	if(n == 0)
		return points[n][last];

	// Recursive Intuition
	int max_merit_1 = points[n][last] + ninjaPoints(points, n-1, (last+1)%3);
	int max_merit_2 = points[n][last] + ninjaPoints(points, n-1, (last+2)%3);

	// Self Work
	return max(max_merit_1, max_merit_2);
}

int ninjaPoints(vector<vector<int>> &points, vector<vector<int>> &dp, int n, int last)
{
	// Base Case 1
	if(n == 0)
		return points[n][last];

	// Base Case 2
	if(dp[n][last] != -1)
		return dp[n][last];

	// Recursive Intuition
	int max_merit_1 = points[n][last] + ninjaPoints(points, n-1, (last+1)%3);
	int max_merit_2 = points[n][last] + ninjaPoints(points, n-1, (last+2)%3);

	// Self Work
	return dp[n][last] = max(max_merit_1, max_merit_2);
}
*/

// Tabulation Method. Time Complexity: O(3*n) -> O(n). Space Complexity: O(n+n+1) -> O(n)
int ninjaPoints(vector<vector<int>> &points, vector<vector<int>> &dp, int n)
{
	// What does dp[i] represent? -> maximum training points uptil the ith iteration
	dp[0][0] = points[0][0];
	dp[0][1] = points[0][1];
	dp[0][2] = points[0][2];

	if (n == 0)
		return max(dp[0][0], max(dp[0][1], dp[0][2]));

	int res = INT_MIN;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][j] = points[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
			res = max(res, dp[i][j]);
		}
	}

	return res;
}

// DP-7: Striver's Space Optimization: https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=8
int ninjaTraining(vector<vector<int>> &points, int n)
{
	vector<int> dp(4, 0);
	prev[0] = max(points[0][1], points[0][2]);
	prev[1] = max(points[0][0], points[0][2]);
	prev[2] = max(points[0][0], points[0][1]);
	prev[3] = max(points[0][1], max(points[0][1]), points[0][2]);

	for (int day = 1; day < n; day++)
	{
		vector<int> temp(4, 0);
		for (int last = 0; last < 4; last++)
		{
			temp[last] = 0;

			for (int task = 0; task < 3; task++)
			{
				if (task != last)
					temp[last] = max(temp[last], points[day][task] + prev[task]);
			}
		}

		prev = temp;
	}

	return prev;
}

int ninjaTraining(vector<vector<int>> &points, int n)
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int>(3));

	return ninjaPoints(points, dp, n);
}

/*
int ninjaTraining(int n, vector<vector<int>> &points)
{
	// Write your code here.
	int res = INT_MIN;

	for(int i = 0; i < 3; i++)
		res = max(res, ninjaPoints(points, n-1, i));

	return res;
}
*/

void solve()
{
	// Do Something
	int n;
	cin >> n;

	vector<vector<int>> points(n, vector<int>(3));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> points[i][j];

	cout << ninjaTraining(points, n) << "\n";
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