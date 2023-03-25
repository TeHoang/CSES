#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mod = 1e9 + 7;
 
void solve()
{
	int n, m; cin >> n >> m;
	vector <int> x(n);
	for (int& a : x) cin >> a;
	vector <vector<ll>> f(n + 1, vector<ll>(m + 2, 0));
	for (int i = 1; i <= n; ++i)
	{
		if (i == 1)
		{
			if (x[0] != 0) f[1][x[0]] = 1;
			else
			{
				for (int j = 1; j <= m; ++j) f[1][j] = 1;
			}
		}
		else
		{
			if (x[i - 1] == 0 && x[i - 2] == 0)
			{
				for (int j = 1; j <= m; ++j)
				{
					f[i][j] += f[i - 1][j] + f[i - 1][j - 1];
					if (j < m) f[i][j] += f[i - 1][j + 1];
					f[i][j] %= mod;
				}
			}
			else if (x[i - 1] == 0 && x[i - 2] != 0)
			{
				for (int j = max(1, x[i - 2] - 1); j <= min(m, x[i - 2] + 1);++j)
				{
					f[i][j] += f[i - 1][x[i - 2]];
					f[i][j] %= mod;
				}
			}
			else if (x[i - 1] != 0 && x[i - 2] == 0)
			{
				f[i][x[i - 1]] += f[i - 1][x[i - 1] + 1] + f[i - 1][x[i - 1]] + f[i - 1][x[i - 1] - 1];
				f[i][x[i-1]] %= mod;
			}
			else
			{
				if (abs(x[i - 2] - x[i - 1]) <= 1)
				{
					f[i][x[i - 1]] += f[i - 1][x[i - 2]];
					f[i][x[i-1]] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; ++i)
	{
		ans += f[n][i];
		ans %= mod;
	}
	cout << ans;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}