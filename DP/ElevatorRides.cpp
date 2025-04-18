#include <bits/stdc++.h>

using namespace std;

#define int long long
#define bit(n,i) ((n >> i) & 1)
#define fi first
#define se second

void minimize(pair <int, int> &a, pair <int, int> b){
    if(a > b) a = b;
}

int n, x;
const int Sz = 22;
pair <int, int> dp[1 << Sz];
int w[Sz];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> w[i];

    dp[0].fi = 1;//{} takes 1 ride
    dp[0].se = 0;//last ride has weight = 0
    for(int i = 1; i < (1 << n); i++) dp[i].fi = 1e18;

    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if(!bit(mask, i)){
                //add i to the ride
                if(dp[mask].se + w[i] <= x){
                    minimize(dp[mask + (1 << i)], {dp[mask].fi, dp[mask].se + w[i]});
                }

                //add i to the next ride
                else{
                    minimize(dp[mask + (1 << i)], {dp[mask].fi + 1, w[i]});
                }
            }
        }
    }
    cout << dp[(1 << n) - 1].fi;
}
