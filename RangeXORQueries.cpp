#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q;
const int Sz = 2e5 + 2;
int st[Sz * 4 + 1];

void Build(int id, int l, int r){
    if(l == r){
        int x;
        cin >> x;
        st[id] = x;
        return;
    }
    int mid = (l + r) >> 1;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    st[id] = st[id << 1] ^ st[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v){
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    if(mid < u) return get(id << 1 | 1, mid + 1, r, u, v);
    if(v < mid + 1) return get(id << 1, l, mid, u, v);
    return get(id << 1, l, mid, u, v) ^ get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    Build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << "\n";
    }
}
