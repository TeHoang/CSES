#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 5;
 
void solve()
{
	int n; cin >> n; 
	vector <int> a(n);
	for (int& x : a) cin >> x;
	int ans = 1;
	vector <int> mine(n,0);
	mine[0] = a[0];
	for (int i = 1; i < n; ++i)
	{
		auto it = lower_bound(mine.begin(), mine.begin() + ans, a[i]);
		if (it == mine.begin() + ans)
			mine[ans++] = a[i];
		else
			*it = a[i];
	}
	cout << ans;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}