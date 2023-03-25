#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[1000001];
int n;
 
int main(){
	cin >> n;
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=6;++j){
			if(i-j>=0){
			dp[i]+=dp[i-j];
			}
			dp[i]%=MOD;
		}
	}
	cout << dp[n] << "\n"; 
}