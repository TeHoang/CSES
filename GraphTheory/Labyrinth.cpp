#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MAXN = 1e5 + 5;
const int mod = 1e9 + 7;
 
int n, m;
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,-1,1,0,0 };
string dir = "0LRUD";
int parent[1001][1001];
char arr[1001][1001];
 
void bfs(int i, int j)
{
	queue <pair<int, int>> q;
	q.push({ i,j });
	parent[i][j] = 0;
	while (!q.empty())
	{
		auto top = q.front();
		q.pop();
		for (int k = 1; k <= 4; ++k)
		{
			int i1 = top.first + dx[k];
			int j1 = top.second + dy[k];
			if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && arr[i1][j1] != '#' && !parent[i1][j1])
			{
				parent[i1][j1] = k;
				q.push({ i1,j1 });
			}
		}
	}
}
 
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> arr[i][j];
	int i_end, j_end;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (arr[i][j] == 'A')
			{
				bfs(i, j);
			}
			else if (arr[i][j] == 'B')
			{
				i_end = i, j_end = j;
			}
		}
	}
	if (!parent[i_end][j_end]) cout << "NO\n";
	else
	{
		cout << "YES\n";
		string ans_dir = "";
		int cnt = 0;
		while (arr[i_end][j_end]!='A')
		{
			++cnt;
			int tmpi = i_end, tmpj = j_end;
			ans_dir += dir[parent[tmpi][tmpj]];
			i_end -= dx[parent[tmpi][tmpj]];
			j_end -= dy[parent[tmpi][tmpj]];
		}
		cout << cnt << endl;
		reverse(begin(ans_dir), end(ans_dir));
		cout << ans_dir << endl;
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		solve();
}