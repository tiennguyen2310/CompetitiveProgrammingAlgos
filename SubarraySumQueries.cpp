#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define int ll
 
int n, m;
const int Sz = 2e5;
int a[Sz + 1];
struct Dat
{
    int pre;
    int suf;
    int sum;
    int best;
}st[Sz * 4 + 1];
 
Dat combine(Dat s1, Dat s2)
{
    Dat res;
    res.pre = max(s1.pre, s1.sum + s2.pre);
    res.suf = max(s2.suf, s2.sum + s1.suf);
    res.sum = s1.sum + s2.sum;
    res.best = max(max(s1.best, s2.best), s1.suf + s2.pre);
    return res;
}
 
void Build(int id, int l, int r)
{
    if(l == r)
    {
        st[id].best = max(a[l], 0LL);
        st[id].pre = max(a[l], 0LL);
        st[id].suf = max(a[l], 0LL);
        st[id].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(id * 2, l, mid);
    Build(id * 2 + 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}
 
void update(int id, int l, int r, int i, int x)
{
    if(r < i || i < l) return;
    if(l == r)
    {
        st[id].best = max(a[l], 0LL);
        st[id].pre = max(a[l], 0LL);
        st[id].suf = max(a[l], 0LL);
        st[id].sum = a[l];
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, x);
    update(id * 2 + 1, mid + 1, r, i, x);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
 
    Build(1, 1, n);
 
    int k, x;
    while(m--)
    {
        cin >> k >> x;
        a[k] = x;
        update(1, 1, n ,k, x);
        cout << st[1].best << "\n";
    }
}
