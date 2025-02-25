#include <bits/stdc++.h>

using namespace std;

#define int long long

int Cnt(int n){
    int notValid = 4LL * (n - 4) * (n - 2) + 3LL * 2LL * (n - 2) + 2LL * 2LL * (n - 2) + 2LL * (n - 4) + 4;
    return (n * n) * (n * n - 1) / 2LL - notValid;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << Cnt(i) << "\n";
    }
}
