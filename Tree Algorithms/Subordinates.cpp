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
    int x;
    for(int i = 2; i <= n; i++)
    {
        cin >> x;
        a[x].push_back(i);
    }
}
 
int dp[Sz + 1];
 
void DFS(int u, int p)
{
    for(int v : a[u])
    {
        DFS(v, u);
        dp[u] += dp[v];
    }
    dp[u]++;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
 
    DFS(1, 0);
 
    for(int i = 1; i <= n; i++) cout << dp[i] - 1 << ' ';
}
