#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
const int Sz = 5e3 + 10;
int dp[Sz][Sz];
int a[Sz];

int DP(int l, int r){
    if(l == r) return a[l];
    if(l + 1 == r) return max(a[l], a[r]);

    int &res = dp[l][r];
    if(res != -1e18) return res;

    //pick l, then next player picks between [l + 1, r]
    res = min(a[l] + DP(l + 2, r), a[l] + DP(l + 1, r - 1));

    //pick r, then next player picks between [l, r - 1]
    res = max(res, min(a[r] + DP(l + 1, r - 1), a[r] + DP(l, r - 2)));
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++) dp[i][j] = -1e18;
    }
    cout << DP(1, n);
}
