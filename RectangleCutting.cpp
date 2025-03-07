#include <bits/stdc++.h>

using namespace std;

#define int long long

int m, n;
const int Sz = 502;
int dp[Sz][Sz];
//dp[i][j] = k: minimum # of cuts to get (i, j)

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = 1e18;
    }
    for(int i = 1; i <= m; i++) dp[i][1] = i - 1;
    for(int j = 1; j <= n; j++) dp[1][j] = j - 1;

    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }

            //cut j
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }

            //cut i
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
        }
    
    }
    // for(int i = 1; i <= m; i++){
    //     for(int j = 1; j <= n; j++) cout << dp[i][j] << ' '; cout << "\n";
    // }
    cout << dp[m][n];
}
