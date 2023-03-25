#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int n,x;
int c[1000001];
ll dp[1000001];
int main(){
	cin >> n >> x;
	for(int i=1;i<=n;++i){
		cin >> c[i];
	}
	dp[0]=1;
	for(int i=1;i<=x;++i){
		for(int j=1;j<=n;++j){
			if(i-c[j]>=0){
				dp[i]+=dp[i-c[j]];
			}
			dp[i]%=MOD;
		}
	}
	cout << dp[x];
}