#include <bits/stdc++.h>

using namespace std;

#define int long long
#define a first
#define b second

int n;
const int Sz = 2e5 + 2;
pair <pair <int, int>, int> P[Sz + 1];;
int dp[Sz * 2 + 1];
int st[Sz * 12 + 1];

int get(int id, int l, int r, int u, int v){
    if(r < u || v < l) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

void update(int id, int l, int r, int u, int k){
    if(r < u || u < l) return;
    if(l == r){
        st[id] = max(st[id], k);
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, k);
    update(id << 1 | 1, mid + 1, r, u, k);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector <int> v;
    for(int i = 1; i <= n; i++){
        cin >> P[i].a.a >> P[i].a.b >> P[i].b;
        v.push_back(P[i].a.a); v.push_back(P[i].a.b);
        v.push_back(P[i].a.a - 1);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 1; i <= n; i++){
        P[i].a.a = lower_bound(v.begin(), v.end(), P[i].a.a) - v.begin() + 1;
        P[i].a.b = lower_bound(v.begin(), v.end(), P[i].a.b) - v.begin() + 1;
    }

    sort(P + 1, P + n + 1, [&](const pair <pair <int, int>, int> &A, const pair <pair <int, int>, int> &B){
        return A.a.b < B.a.b;
    });

    dp[0] = 0;
    int res = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = get(1, 1, n * 3, 1, P[i].a.a - 1) + P[i].b;
        update(1, 1, n * 3, P[i].a.b, dp[i]);
        res = max(res, dp[i]);
        // cout << P[i].a.a << ' ' << P[i].a.b << ' ' << P[i].b << ' ' << dp[i] << "\n";
    }
    cout << res;
}
