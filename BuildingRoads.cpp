#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
 
int n;
const int Sz = 1e5;
vector <int> a[Sz + 1];//adj
int m;
int d[Sz + 1];//color
 
void Read()
{
    cin >> n >> m;
    int u, v;
    while(m--)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
 
void DFS(int x)
{
    d[x] = 1;
    for(int v : a[x])
    {
        if(d[v]) continue;
        DFS(v);
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
 
    vector <int> v;//contains an element representing a vung lien thong
 
    for(int i = 1; i <= n; i++)
    {
        if(!d[i])
        {
            v.push_back(i);
            DFS(i);
        }
    }
//    for(auto i : v) cout << i << ' ';
    cout << v.size() - 1 << "\n";
    for(int i = 1; i < v.size(); i++)
    {
        cout << 1 << ' ' << v[i] << "\n";
    }
}
