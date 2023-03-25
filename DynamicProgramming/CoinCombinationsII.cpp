#include <bits/stdc++.h>
using namespace std;    
#define endl "\n"
using ll = long long;
const int mod = 1e9+7;
 
ll f[1000005];
 
void solve()
{   
    int n,x; cin >> n >> x;
    int c[n];
    for(int i=0;i<n;++i) cin >> c[i];
    f[0]=1;
    for(int j=0;j<n;++j)
    {
        for(int i=1;i<=x;++i)
        {
            if(i>=c[j])
            {
                f[i]+=f[i-c[j]];
                f[i]%=mod;
            }
        }
    }
    cout << f[x];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}