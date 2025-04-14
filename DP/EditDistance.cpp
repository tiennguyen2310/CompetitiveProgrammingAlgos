#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
string s1, s2;
const int Sz = 5002;
int dp[Sz][Sz];
 
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cin >> s1 >> s2;
    int m = (int)s1.size(), n = (int)s2.size();
    s1 = ' ' + s1; s2 = ' ' + s2;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++) dp[i][j] = 1e18;
    }
    for(int i = 0; i <= m; i++) dp[i][0] = i;
    for(int j = 0; j <= n; j++) dp[0][j] = j;
 
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(s1[i] == s2[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
 
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1]) + 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
 
    cout << dp[m][n];
}
