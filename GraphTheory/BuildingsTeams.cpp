#include <bits/stdc++.h>
using namespace std;

int n, m; 
vector <int> adj[MAXN];
vector <int> Colour(MAXN);
bool flag = 0;
 
void dfs(int u, int colour)
{
	if (flag) return;
	Colour[u] = colour;
	for (int v : adj[u])
	{
		if (Colour[v] == colour)
		{
			flag = 1;
			return;
		}
		else if (!Colour[v]) dfs(v, colour % 2 + 1);
	}
}
 
void solve()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!Colour[i]) dfs(i, 1);
	}
	if (!flag)
		for (int i = 1; i <= n; ++i) cout << Colour[i] << ' ';
	else cout << "IMPOSSIBLE\n";
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}