#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[1000001];
int c[101];
int n,x;
int main(){
	cin >> n >> x;
	for(int i=1;i<=n;++i){
		cin >> c[i];
	}
	for(int i=1;i<=x;++i){
		dp[i]=MOD;
	}
	for(int i=1;i<=x;++i){
		for(int j=1;j<=n;++j){
			if(i-c[j]>=0){
				dp[i]=min(dp[i],dp[i-c[j]]+1);
			}
		}
	}
	if(dp[x]==MOD) cout << "-1\n";
	else 
	cout << dp[x];
}