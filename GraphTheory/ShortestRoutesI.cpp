#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int maxn = 100005;
const ll INF = 1e16;
const int mod = 1e9+7;
int n, m, s, t;
vector <pair<ll,ll>> adj[maxn];
 
void nhap(){
	cin >> n >> m;
	for(int i=1;i<=m;++i){
		ll x,y,w; cin >> x >> y >> w;
		adj[x].push_back(make_pair(y,w));
	}
}
void dijkstra(){
	vector <ll> d(n+1,INF);
	d[1]=0;
	priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater <pair<ll,ll>>> Q;
	Q.push({0,1});
	while(!Q.empty()){
		pair <ll,ll> top = Q.top(); Q.pop();
		ll u = top.second;
		ll kc = top.first;
		if(kc>d[u]) continue;
		for(auto it:adj[u]){
			ll v = it.first;
			ll w = it.second;
			if(d[v]>d[u]+w){
				d[v] = d[u]+w;
				Q.push({d[v],v});
			}
		}
	}
	for(int i=1;i<=n;++i){
		cout << d[i] << " ";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	nhap();
	dijkstra(); 
}