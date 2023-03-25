#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

vector<int> adj[MAXN];
vector<int> parent(MAXN,0),visited(MAXN,0);
vector<int> ans;

void dfs(int u,int par,int &s)
{
    if(visited[u]) return;
    parent[u] = par;
    visited[u] = 1;
    for(int x:adj[u])
    {
        if(s!=-1) return;
        if(x==par) continue;
        if(!visited[x]) dfs(x,u,s);
        else
        {
            ans.push_back(x);
            visited[x] = 0;
            s = u;
            return;
        }
    }
    return;
}

void solve()
{
    int n,m,s=-1; cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;++i)
    {
        dfs(i,i,s);
        if(s!=-1) break;
    }
    if(s==-1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    while(visited[s]>=0)
    {
        ans.push_back(s);
        visited[s]--;
        if(visited[s]<0) break;
        s = parent[s];
    }
    cout << ans.size() << endl;
    for(int x:ans) cout << x << ' ';
}

int main()
{
    solve();
    return 0;   
}