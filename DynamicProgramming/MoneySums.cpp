#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mod = 1e9 + 7;
 
void solve()
{
	int n; cin >> n;
	vector <int> x(n);
	int maxx = -1e9;
	for (int& a : x)
	{
		cin >> a;
		maxx = max(maxx, a);
	}
	maxx *= n;
	vector <vector<int>> f(n + 1, vector<int>(maxx + 1, 0));
	map <int,int> cnt;
	for (int i = 1; i <= n; ++i)
	{
		f[i][x[i - 1]] = 1;
		cnt[x[i - 1]]++;
		for (int j = 1; j <= maxx; ++j)
		{
			if (f[i - 1][j]) f[i][j] = 1;
			if (j >= x[i - 1] && f[i - 1][j - x[i - 1]])
			{
				f[i][j] = 1;
				cnt[j]++;
			}
		}
	}
	cout << cnt.size() << endl;
	for (int i = 1; i <= maxx; ++i)
	{
		if (f[n][i]) cout << i << ' ';
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		solve();
}