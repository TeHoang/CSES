#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MAXN = 1e5+5;
const int mod = 1e9 + 7;
const ll oo = (1ll << 63) - 1;
 
int n, m; 
vector <int> adj[MAXN];
vector <int> Distance(MAXN, MAXN + 1), parent(MAXN);
 
void bfs(int u)
{
	queue <int> q;
	q.push(u);
	Distance[u] = 1, parent[u] = u;
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		for (int v : adj[top])
		{
			if (Distance[v] == MAXN + 1)
			{
				Distance[v] = Distance[top] + 1;
				parent[v] = top;
				q.push(v);
			}
		}
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
	bfs(1);
	if (Distance[n] == MAXN + 1) cout << "IMPOSSIBLE\n";
	else
	{
		cout << Distance[n] << endl;
		vector <int> path;
		while (parent[n]!=n)
		{
			path.push_back(n);
			n = parent[n];
		}
		path.push_back(1);
		for (int i = path.size() - 1; i >= 0; --i) cout << path[i] << ' ';
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
}