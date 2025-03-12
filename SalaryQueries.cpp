#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q;
const int Sz = 2e5 + 2;
int a[Sz + 1];
char c[Sz + 1];
int s1[Sz + 1], s2[Sz + 1];
int st[Sz * 3 * 4 + 1];

void update(int id, int l, int r, int u, int k){
    if(r < u || u < l) return;
    if(l == r){
        st[id] += k;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, k);
    update(id << 1 | 1, mid + 1, r, u, k);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    vector <int> v;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    for(int i = 1; i <= q; i++){
        cin >> c[i] >> s1[i] >> s2[i];
        if(c[i] == '?') v.push_back(s1[i]);
        v.push_back(s2[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int m = (int)v.size();

    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        update(1, 1, m, a[i], 1);
    }
    for(int i = 1; i <= q; i++){
        s2[i] = lower_bound(v.begin(), v.end(), s2[i]) - v.begin() + 1;
        if(c[i] == '!'){
            update(1, 1, m, a[s1[i]], -1);
            a[s1[i]] = s2[i];
            update(1, 1, m, s2[i], 1);
        }
        else{
            s1[i] = lower_bound(v.begin(), v.end(), s1[i]) - v.begin() + 1;
            cout << get(1, 1, m, s1[i], s2[i]) << "\n";
        }
    }
}
