#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define int ll
 
int n;
const int Sz = 2e5;
int a[Sz + 1];
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
 
    int res = 0;
    vector <int> v;
    for(int i = 1; i <= n; i++)
    {
        int k = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        if(k == v.size()) v.push_back(a[i]);
        else v[k] = a[i];
    }
    cout << v.size() << "\n";
//    for(auto i : v) cout << i << ' ';
}
