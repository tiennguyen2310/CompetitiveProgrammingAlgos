#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
ll n;
const ll Sz = 2e5;
ll d[Sz + 1];
ll x;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
 
    for(ll i = 1; i < n; i++)
    {
        cin >> x;
        d[x] = 1;
    }
    for(ll i = 1; i <= n; i++)
    {
        if(!d[i])
        {
            cout << i;
            return 0;
        }
    }
}
