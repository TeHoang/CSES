#include <bits/stdc++.h>
using namespace std;
 
const int inf = 1e9;
 
vector<vector<int>> d(1001,vector<int>(1001,inf)), path(1001,vector<int>(1001));
vector<vector<char>> maze(1001,vector<char>(1001));
vector<pair<int,int>> M;
pair<int,int> A,B={1e9,1e9};
 
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
 
string trace = "ULRD";
 
bool InMaze(pair<int,int> p,int n,int m)
{
    return (p.first>=0 && p.first<n && p.second>=0 && p.second<m 
    && ((maze[p.first][p.second]=='.') || (maze[p.first][p.second]=='M')));
}
 
bool Out(pair<int,int> p,int n,int m)
{
    return (p.first==0 || p.first==n-1 || p.second==0 || p.second==m-1);
}
 
void bfs(pair<int,int> p,int n,int m)
{
    if(d[p.first][p.second]==0) return;
    queue<pair<int,int>> q;
    q.push({p.first,p.second});
    d[p.first][p.second] = 0;
    while(!q.empty())
    {
        int fi = q.front().first, se = q.front().second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int x = fi + dx[i];
            int y = se + dy[i];
            if(InMaze({x,y},n,m))
            {
                if(d[x][y]!=0 && maze[x][y]=='M')
                {
                    d[x][y] = 0;
                    q.push({x,y});
                }
                else if(d[fi][se] + 1 < d[x][y])
                {
                    d[x][y] = d[fi][se] + 1;
                    q.push({x,y});
                }   
            }
        }
    }
}
 
void bfs2(pair<int,int> p,int n,int m)
{
    if(Out({p.first,p.second},n,m))
    {
        B = A;
        return;
    }
    queue<pair<int,int>> q;
    q.push({p.first,p.second});
    d[p.first][p.second] = 0;
    while(!q.empty())
    {
        int fi = q.front().first, se = q.front().second;
        q.pop();
        for(int i=0;i<4;++i)
        {
            int x = fi + dx[i];
            int y = se + dy[i];
            if(InMaze({x,y},n,m))
            {
                if(d[fi][se] + 1 < d[x][y])
                {
                    d[x][y] = d[fi][se] + 1;
                    if(Out({x,y},n,m)) B = {x,y};
                    path[x][y] = i;
                    q.push({x,y});
                }   
            }
        }
    }
}
 
void solve()
{
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin >> maze[i][j];
            if(maze[i][j]=='M') M.push_back({i,j});
            else if(maze[i][j]=='A') A = {i,j};
        }
    }
    for(auto it:M) bfs({it.first,it.second},n,m);
    bfs2({A.first,A.second},n,m);
    if(B.first==1e9)
    {
        cout << "NO\n";
        return;
    }
    vector<char> ans;
    while(A!=B)
    {
        int k = path[B.first][B.second];
        ans.push_back(trace[k]);
        B.first -= dx[k], B.second -= dy[k];
    }
    cout << "YES\n";
    cout << ans.size() << endl;
    for(int i=ans.size()-1;i>=0;--i) cout << ans[i];
}
 
int main()
{
    solve();
    return 0;
}