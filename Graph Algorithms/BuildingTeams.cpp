#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
 
int n;
const int Sz = 1e5;
int m;
vector <int> a[Sz + 1];
pair <int, int> p[Sz * 2 + 1];
 
void Read()
{
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        p[i] = {u, v};
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
 
int vis[Sz + 1];
int Len[Sz + 1];
 
void DFS(int u, int p)
{
    vis[u] = 1;
    for(int v : a[u])
    {
        if(v == p) continue;
        if(vis[v]) continue;
        Len[v] = Len[u] + 1;
        DFS(v, u);
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
 
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            DFS(i, 0);
        }
    }
    for(int i = 1; i <= n; i++) Len[i] = Len[i] % 2 + 1;
    for(int i = 1; i <= m; i++)
    {
        if(Len[p[i].fi] == Len[p[i].se])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) cout << Len[i] << ' ';
}
