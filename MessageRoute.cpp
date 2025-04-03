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
 
int pre[Sz + 1];
int d[Sz + 1];
 
void BFS(int x)
{
    queue <int> q;
    d[x] = 1;
    q.push(x);
    int u;
    while(q.size())
    {
        u = q.front();
        q.pop();
        for(int v : a[u])
        {
            if(d[v]) continue;
            d[v] = 1;
            q.push(v);
            pre[v] = u;
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
 
    BFS(1);
 
    if(!d[n])
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int tmp = n;
    vector <int> res;
    while(tmp != 1)
    {
        res.push_back(tmp);
        tmp = pre[tmp];
    }
    res.push_back(tmp);
    reverse(res.begin(), res.end());
    cout << res.size() << "\n";
    for(int i : res) cout << i << ' ';
}
