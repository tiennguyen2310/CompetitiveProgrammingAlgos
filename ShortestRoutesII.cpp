#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n, m, q;
int dp[505][505];
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) dp[i][j] = 1e15;
	}
	for(int i = 1; i <= n; i++) dp[i][i] = 0;
	for(int i = 1, u, v, c; i <= m; i++){
		cin >> u >> v >> c;
		dp[u][v] = min(dp[u][v], c);
		dp[v][u] = min(dp[v][u], c);
	}
	for(int k = 1; k <= n; k++){
		for(int j = 1; j <= n; j++){
			for(int i = 1; i <= n; i++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	int u, v;
	while(q--){
		cin >> u >> v;
		cout << (dp[u][v] == 1e15 ? -1 : dp[u][v]) << "\n";
	}
}
