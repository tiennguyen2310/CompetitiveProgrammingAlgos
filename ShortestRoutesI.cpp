#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int n, m;
const int Sz = 1e5;
vector <pair <int, ll> > a[Sz + 1];
const ll inf = 1e18;
int vis[Sz + 1];
 
void Read()
{
    cin >> n >> m;
    int u, v;
    ll c;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v >> c;
        a[u].push_back({v, c});
    }
}
 
priority_queue <pair <ll, int>, vector <pair <ll, int> >, greater<pair <ll, int> > > pq;
//first: distance
//second: number
 
ll Len[Sz + 1];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
 
    pq.push({0, 1});
    for(int i = 2; i <= n; i++) Len[i] = inf;
 
    pair <ll, int> u;
 
 
    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();
        if(vis[u.second]) continue;
        vis[u.second] = 1;
        for(pair <int, ll> &v : a[u.second])
        {
            if(Len[v.first] > Len[u.second] + v.second)
            {
                Len[v.first] = Len[u.second] + v.second;
                pq.push({Len[v.first], v.first});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << Len[i] << ' ';
}
