#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n;
const int Sz = 103;
bool a[Sz + 1][1000 * Sz + 1];
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    vector <int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    a[0][0] = 1;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 1000 * n; j++){
            if(!a[i][j]) continue;
            a[i + 1][j] = true;
            a[i + 1][j + v[i + 1]] = true;
        }
    }
    vector <int> res;
    for(int i = 1; i <= 1000 * n; i++){
        if(a[n][i]) res.push_back(i);
    }
    cout << res.size() << "\n";
    for(auto i : res) cout << i << ' ';
}
