#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n;
const int Sz = 1000;
pair <int, int> p[Sz + 7];
 
int DoubleArea(pair <int, int> a, pair <int, int> b, pair <int, int> c)
{
    c.first -= b.first;
    c.second -= b.second;
 
    b.first -= a.first;
    b.second -= a.second;
 
    int res = b.first * c.second - b.second * c.first;
 
    return res;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].first >> p[i].second;
 
    int res = 0;
 
    for(int i = 1; i < n; i++)
    {
        res += DoubleArea({0, 0}, p[i], p[i + 1]);
    }
    res += DoubleArea({0, 0}, p[n], p[1]);
    cout << abs(res);
}
