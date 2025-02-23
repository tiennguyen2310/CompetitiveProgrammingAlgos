#include <bits/stdc++.h>

using namespace std;

#define int long long

//dp[pos][last][started][bounded]
int dp[20][10][2][2];

string a, b;

int DP(vector <int>& cur, int pos, int las, bool started, bool bounded){
    if(pos == (int)cur.size()) return 1;
    int &res = dp[pos][las][started][bounded];
    if(res != -1) return res;
    res = 0;
    if(!started){
        for(int i = 0; i <= (bounded ? cur[pos] : 9); i++){
            res += DP(cur, pos + 1, i, i != 0, i == cur[pos] && bounded);
        }
    }
    else{
        for(int i = 0; i <= (bounded ? cur[pos] : 9); i++){
            if(i != las)
                res += DP(cur, pos + 1, i, started, bounded && i == cur[pos]);
        }
    }
    // cout << pos << ' ' << las << ' ' << started << ' ' << bounded << ' ' << res << "\n";
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset(dp, -1, sizeof(dp));

    int A;
    cin >> A >> b;
    vector <int> vl1, vl2;
    if(A == 0){
        for(int i = 0; i < (int)b.size(); i++) vl2.push_back(b[i] - '0');
        memset(dp, -1, sizeof(dp));
        int res2 = DP(vl2, 0, 0, 0, 1);
        cout << res2;
        return 0;
    }
    
    A--;
    a = to_string(A);
    for(int i = 0; i < (int)a.size(); i++) vl1.push_back(a[i] - '0');    
    // for(auto i : vl1) cout << i << ' '; cout << "\n"; return 0;
    int res1 = DP(vl1, 0, 0, false, true);
    // cout << res1 << '\n';
    for(int i = 0; i < (int)b.size(); i++) vl2.push_back(b[i] - '0');
    memset(dp, -1, sizeof(dp));
    int res2 = DP(vl2, 0, 0, 0, 1);
    // cout << res2 << '\n';
    cout << res2 - res1;
}
