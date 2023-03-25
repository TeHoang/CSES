#include <bits/stdc++.h>
using namespace std;    
#define endl "\n"
using ll = long long;
const int mod = 1e9+7;
 
ll f[1000005];
 
void solve()
{   
    int n; cin >> n;
    for(int i=0;i<=n;++i)
    {
        if(i==0) f[i]=0;
        else if(i>=1 && i<=9) f[i]=1;
        else f[i]=LLONG_MAX-5;
    }
    for(int i=10;i<=n;++i)
    {
        int tmp = i;
        while(tmp)
        {   int r = tmp%10;
            f[i]=min(f[i],f[i-r]+1);
            tmp/=10;
        }
    }
    cout << f[n];
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}