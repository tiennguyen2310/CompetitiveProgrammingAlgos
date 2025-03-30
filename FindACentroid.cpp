#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n;
const int Sz = 2e5 + 2;
vector <int> adj[Sz + 1];
int sz[Sz + 1];
 
void dfs(int u, int p){
	sz[u] = 1;
	for(int v : adj[u]){
		if(v != p){
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}
 
int FindCentroid(int u, int p){
	int vcl = 0;
	for(int v : adj[u]){
		if(v == p) continue;
		if(sz[v] > n / 2){
			vcl = v; break;
		}
	}
	if(!vcl) return u;
	return FindCentroid(vcl, u);
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	dfs(1, 1);
	cout << FindCentroid(1, 1);
}
