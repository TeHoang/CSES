#include <bits/stdc++.h>
using namespace std;    
#define endl "\n"
using ll = long long;
const int inf = 1e9;
 
int a,b;
ll f[501][501];
 
void solve()
{      
    cin >> a >> b;
    for(int i=1;i<=a;++i)
    {
        for(int j=1;j<=b;++j)
        if(i==j) f[i][j]=0;
        else f[i][j]=inf;
    }
    for(int i=1;i<=a;++i)
    {
        for(int j=1;j<=b;++j)
        {
            for(int u=1;u<i;++u)
            f[i][j]=min(f[i][j],f[u][j]+f[i-u][j]+1);
            for(int v=1;v<j;++v)
            f[i][j]=min(f[i][j],f[i][v]+f[i][j-v]+1);
        }
    }
    cout << f[a][b];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}