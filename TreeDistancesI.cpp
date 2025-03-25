#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void File(){
	freopen(".inp", "r", stdin);
	freopen("ck.out", "w", stdout);
}
 
int n;
const int Sz = 2e5 + 7;
vector <int> adj[Sz + 1];
int len1[Sz + 1];
int len3[Sz + 1];
 
void dfs(int u, int p){
	for(int v : adj[u]){
		if(v == p) continue;
		len1[v] = len1[u] + 1;
		dfs(v, u);
	}
}
 
int len2[Sz + 1];
 
void dfs1(int u, int p){
	for(int v : adj[u]){
		if(v == p) continue;
		len2[v] = len2[u] + 1;
		dfs1(v, u);
	}
}
 
void dfs2(int u, int p){
	for(int v : adj[u]){
		if(v == p) continue;
		len3[v] = len3[u] + 1;
		dfs2(v, u);
	}
}
 
signed main(){
	//File();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for(int i = 2, u, v; i <= n; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1);
	pair <int, int> Max = {-1, -1};
	for(int i = 1; i <= n; i++) Max = max(Max, {len1[i], i});
	
	dfs1(Max.second, Max.second);
	
	Max = {-1, -1};
	for(int i = 1; i <= n; i++) Max = max(Max, {len2[i], i});
	
	dfs2(Max.second, Max.second);
	
	for(int i = 1; i <= n; i++) cout << max(len2[i], len3[i]) << ' ';
}
