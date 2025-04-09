#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define int ll
 
int n;
const int Sz = 1000;
int q;
int dp[Sz + 1][Sz + 1];
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> q;
    char x;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> x;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (x == '*');
        }
    }
    int lx, ly, rx, ry;
    while(q--)
    {
        cin >> lx >> ly >> rx >> ry;
        cout << dp[rx][ry] - dp[rx][ly - 1] - dp[lx - 1][ry] + dp[lx - 1][ly - 1] << "\n";
    }
}
