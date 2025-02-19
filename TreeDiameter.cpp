#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
 
int n;
const int Sz = 2e5;
vector <int> a[Sz + 1];
 
void Read()
{
    cin >> n;
    int u, v;
    for(int i = 2; i <= n; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
 
int Len[Sz + 1];
 
void DFS(int u, int p)
{
    for(int v : a[u])
    {
        if(v != p)
        {
            Len[v] = Len[u] + 1;
            DFS(v, u);
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
 
    DFS(1, 0);
 
    int Max = 0;
    int u = 0;
    for(int i = 1; i <= n; i++)
    {
        if(Len[i] > Max)
        {
            Max = Len[i];
            u = i;
        }
    }
    for(int i = 1; i <= n; i++) Len[i] = 0;
    DFS(u, 0);
    Max = 0;
    for(int i = 1; i <= n; i++) Max = max(Max, Len[i]);
    cout << Max;
}
