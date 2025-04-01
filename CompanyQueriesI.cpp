#include <bits/stdc++.h>
 
using namespace std;
 
int n, q;
const int Sz = 2e5 + 2;
int par[Sz + 1];
vector <int> adj[Sz + 1];
int lv[Sz + 1];
 
void dfs(int u, int p){
	int v;
	
	for(int i = 0; i < (int)adj[u].size(); i++){
		v = adj[u][i];
		if(v != p){
			lv[v] = lv[u] + 1;
			dfs(v, u);
		}
	}
}
 
int dp[Sz + 1][19];
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> q;
	for(int i = 2; i <= n; i++){
		cin >> par[i];
		adj[i].push_back(par[i]);
		adj[par[i]].push_back(i);
	}
	
	lv[1] = 1;
	dfs(1, 1);
	
	for(int i = 1; i <= n; i++) dp[i][0] = par[i];
	for(int j = 1; (1 << j) <= n; j++){
		for(int i = 1; i <= n; i++){
			if(lv[i] - (1 << j) >= 1){
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
		}
	}
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 2; j++) cout << dp[i][j] << ' ';
		cout << "\n";
	}
	return 0; 
	*/
	
	int x, k;
	
	while(q--){
		cin >> x >> k;
		if(lv[x] - k < 1){
			cout << "-1\n";
			continue;
		}
		for(int i = 17; i >= 0; i--){
			if(k < (1 << i)) continue;
			k -= (1 << i);
			x = dp[x][i];
		}
		cout << x << "\n";
	}
}
