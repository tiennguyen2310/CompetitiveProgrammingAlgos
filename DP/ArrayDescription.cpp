#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
const int Sz = 1e5 + 2;
int dp[Sz][102];
int a[Sz];
const int MOD = 1e9 + 7;

int L(int i){
    if(a[i] == 0) return 1;
    return a[i];
}

int R(int i){
    if(a[i] == 0) return m;
    return a[i];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    // for(int i = 1; i <= n; i++) cout << L(i) << ' ' << R(i) << "\n";
    
    for(int i = L(1); i <= R(1); i++) dp[1][i] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = L(i); j <= R(i); j++){
            for(int k = max(1LL, j - 1); k <= min(m, j + 1); k++){
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                // cout << i << ' ' << j << ' ' << k << "\n";
            }
        }
    }
    int res = 0;
    for(int i = L(n); i <= R(n); i++) res = (res + dp[n][i]) % MOD;
    // for(int i = 1; i <= n; i++){
    //     for(int j = L(i); j <= R(i); j++) cout << dp[i][j] << ' '; cout << "\n";
    // } cout << "\n";
    cout << res;
}
