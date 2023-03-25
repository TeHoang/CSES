#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mod = 1e9 + 7;
 
void solve()
{
	int n, x; cin >> n >> x;
	vector <int> h(n), s(n);
	for (int& x : h) cin >> x;
	for (int& x : s) cin >> x;
	vector <vector <int>> f(2, vector<int>(x + 1, 0));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= x; ++j)
		{
			f[1][j] = f[0][j];
			if (j >= h[i - 1]) f[1][j] = max(f[1][j], f[0][j - h[i - 1]] + s[i - 1]);
		}
		vector <int> tmp = f[0];
		f[0] = f[1];
		f[1] = f[0];
	}
	cout << f[1][x];
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}