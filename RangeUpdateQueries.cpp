#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define int ll
 
int n;
const int Sz = 2e5;
int x[Sz + 1];
 
struct Dat
{
    int val;
    int lazy;
}st[Sz * 4 + 1];
 
void down(int id)
{
    int t = st[id].lazy;
    st[id * 2].val += t;
    st[id * 2].lazy += t;
    st[id * 2 + 1].val += t;
    st[id * 2 + 1].lazy += t;
    st[id].lazy = 0;
}
 
void update(int id, int l, int r, int u, int v, int k)
{
    if(r < u || v < l) return;
    if(u <= l && r <= v)
    {
        st[id].val += k;
        st[id].lazy += k;
        return;
    }
    int mid = (l + r) / 2;
    down(id);
    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);
    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}
 
int get(int id, int l, int r, int u, int v)
{
    if(r < u || v < l) return -1e18;
    if(u <= l && r <= v) return st[id].val;
    int mid = (l + r) / 2;
    down(id);
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    int q;
    cin >> q;
    for(int i = 1; i <= n; i++) cin >> x[i];
 
    int type, a, b, u, k;
    int res;
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u);
        }
        else
        {
            cin >> k;
            res = get(1, 1, n, k, k);
            res += x[k];
            cout << res << "\n";
        }
    }
}
