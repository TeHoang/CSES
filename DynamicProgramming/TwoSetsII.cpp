#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int mod = 1e9 + 7;
 
void solve()
{
	int n; cin >> n;
	if (n * (n + 1) / 2 % 2)
	{
		cout << 0;
		return;
	}
	int sum = n * (n + 1) / 4;
	vector <vector <int> > f(n, vector<int>(sum + 1, 0));
	f[0][0] = 1;
	for (int i=1; i < n; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
				f[i][j] += f[i - 1][j];
				if (j >= i) f[i][j] += f[i - 1][j - i];
				f[i][j] %= mod;
		}
	}
	cout << f[n-1][sum];
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}