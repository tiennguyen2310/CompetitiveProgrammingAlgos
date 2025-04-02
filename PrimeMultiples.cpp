#include <bits/stdc++.h>
 
using namespace std;
 
#define int __int128_t
typedef long long ll;
 
 
ll n, k;
const ll Sz = 20;
ll a[Sz + 1];
ll d[Sz + 1];
ll res = 0;
 
void xulikq()
{
    int tmp = 1;
    ll Cnt = 0;
    for(ll i = 1; i <= k; i++)
    {
        if(d[i])
        {
            tmp *= a[i];
            Cnt++;
            if(tmp > n) return;
        }
    }
    if(Cnt == 0) return;
    if(Cnt % 2 != 0) res += (n / tmp);
    else res -= (n / tmp);
}
 
void duyet(ll x)
{
    if(x > k) xulikq();
    else
    {
        for(ll i = 0; i <= 1; i++)
        {
            d[x] = i;
            duyet(x + 1);
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> k;
    for(ll i = 1; i <= k; i++) cin >> a[i];
 
    duyet(1);
    cout << res;
}
