#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    set <int> s;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
}
