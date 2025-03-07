#include <bits/stdc++.h>

using namespace std;

#define int long long
#define a first
#define b second

int n;
const int Sz = 501;
int dp[2][Sz * Sz / 2];
const int MOD = 1e9 + 7;
//dp[k]: the number of way that the first half is equal to k

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp[0][0] = 1;
    int Sum = n * (n + 1) / 2;
    if(Sum & 1){
        cout << 0;
        return 0;
    }
    Sum /= 2;

    int flag = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 0; k <= Sum; k++) dp[flag][k] = 0;
        flag = 1 - flag;
        for(int k = 0; k <= Sum; k++){
            dp[1 - flag][k] = (dp[1 - flag][k] + dp[flag][k]) % MOD;
            if(k + i <= Sum) dp[1 - flag][k + i] = (dp[1 - flag][k + i] + dp[flag][k]) % MOD;
        }
    }
    cout << dp[flag][Sum];
}
