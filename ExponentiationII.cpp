#include <bits/stdc++.h>

using namespace std;

#define int long long

/**
 * With MOD being a prime number
 * Little Fermat: a ^ (MOD - 1) % MOD = 1
 * 
 * Let b^c = d * (MOD - 1) + r
 * 
 * => a^b^c = a ^ [d(MOD - 1) + r] = a ^ [d(MOD - 1)] * (a ^ r) % MOD = (a ^ r)
 */

 int pow(int a, int b, int MOD){
    if(b == 0) return (1 % MOD);
    if(b == 1) return (a % MOD);

    int res = pow(a, b >> 1, MOD);
    res = (res * res) % MOD;
    if(b & 1) res = (res * a) % MOD;
    return res;
 }

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    int a, b, c;
    const int MOD = 1e9 + 7;
    while(q--){
        cin >> a >> b >> c;
        int bc = pow(b, c, MOD - 1);
        cout << pow(a, bc, MOD) << "\n";
    }
}
