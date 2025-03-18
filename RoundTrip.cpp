#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
 
int n, m;
const int Sz = 1e5;
vector <int> a[Sz + 1];
 
void Read()
{
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
 
int vis[Sz + 1];
int Pre[Sz + 1];
 
void DFS(int u, int p)
{
    vis[u] = 1;
    for(int v : a[u])
    {
        if(v == p) continue;
        if(vis[v])
        {
            vector <int> res;
            res.push_back(v);
            res.push_back(u);
            while(u != v)
            {
                u = Pre[u];
                res.push_back(u);
            }
            cout << res.size() << "\n";
            for(auto i : res) cout << i << ' ';
            exit(0);
        }
        Pre[v] = u;
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
    cout << "IMPOSSIBLE";
}
