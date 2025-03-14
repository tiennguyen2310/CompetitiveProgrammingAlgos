#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll n;
const ll Sz = 1e6;
int a[Sz + 1];
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    ll res = n * (n + 1LL) / 2LL;
    if(res % 2 != 0)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    res /= 2LL;
    ll n1 = n;
    while(res - n1 >= 0)
    {
        a[n1]++;
        res -= n1;
        n1--;
    }
    a[res]++;
    vector <int> v1, v2;
    for(int i = 1; i <= n; i++)
    {
        if(a[i]) v1.push_back(i);
        else v2.push_back(i);
    }
    cout << v1.size() << "\n";
    for(int i = 0; i < v1.size(); i++) cout << v1[i] << ' ';
    cout << "\n";
    cout << v2.size() << '\n';
    for(int i = 0; i < v2.size(); i++) cout << v2[i] << ' ';
}
