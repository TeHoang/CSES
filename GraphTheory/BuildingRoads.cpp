#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
vector <int> sz(MAXN), parent(MAXN);
 
void make_set(int a)
{
	parent[a] = a;
	sz[a] = 1;
}
 
int find(int a)
{
	if (a == parent[a]) return a;
	int p = find(parent[a]);
	parent[a] = p;
	return p;
}
 
void Union(int a, int b)
{
	int x = find(a), y = find(b);
	if (x != y)
	{
		if (sz[x] < sz[y]) swap(x, y);
		sz[x] += sz[y];
		parent[y] = x;
	}
}
 
void solve()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) make_set(i);
	for (int i = 1; i <= m; ++i)
	{
		int a, b; cin >> a >> b;
		Union(a, b);
	}
	vector <pair<int, int>> ans;
	for (int i = 1; i < n; ++i)
	{
		int a = find(i), b = find(i + 1);
		if (a != b)
		{
			Union(a, b);
			ans.push_back({ a,b });
		}
	}
	cout << ans.size() << endl;
	for (auto it : ans) cout << it.first << ' ' << it.second << endl;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		solve();
}