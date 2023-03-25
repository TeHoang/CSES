#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
char a[1001][1001];
ll dp[1001][1001];
int dx[2] = {1,0};
int dy[2] = {0,1};
int main(){
	int n; cin >> n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin >> a[i][j];
		}
	}
	if(a[1][1]=='.') dp[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=0;k<=1;++k){
				int i1 = i + dx[k];
				int j1 = j + dy[k];
				if(i1>=1 && i1<=n && j1>=1 && j1<=n && a[i1][j1]=='.'){
					dp[i1][j1]+=dp[i][j];
					dp[i1][j1]%=MOD;
				}
			}
		}
	}
	cout << dp[n][n];
}