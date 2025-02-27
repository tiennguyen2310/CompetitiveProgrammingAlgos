#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n;
const int Sz = 2e5 + 2;
int a[Sz + 1], dp[Sz + 1];
int st[Sz << 2 | 1];
int A, B;
 
void Build(int id, int l, int r){
    if(l == r){
        st[id] = dp[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}
 
int get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 1e16;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i];
    }
    Build(1, 1, n);
 
    int res = -1e16;
    int l, r;
    for(int i = A; i <= n; i++){
        l = max(0LL, i - B);
        r = i - A;
        assert(l <= r);
        if(l * r == 0LL) res = max(res, dp[i]);
        res = max(res, dp[i] - get(1, 1, n, l, r));
    }
    cout << res;
}
