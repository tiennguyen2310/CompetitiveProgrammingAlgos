#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll n;
const ll Sz = 2e5;
ll a[Sz + 1];
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll res = 0;
    cin >> n;
    ll tmp;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 2; i <= n; i++)
    {
        if(a[i - 1] <= a[i]) continue;
        //a[i - 1] >= a[i]
        tmp = a[i - 1] - a[i];
        //cout << tmp << ' ';
        res += tmp;
        a[i] += tmp;
    }
    cout << res;
}
