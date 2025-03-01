#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
 
int n;
 
void duyet(int x, int start, int finish, int tmp)
{
    if(x == 1)
    {
        cout << start << ' ' << finish << "\n";
        return;
    }
    duyet(x - 1, start, tmp, finish);
    cout << start << ' ' << finish << "\n";
    duyet(x - 1, tmp, finish, start);
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    int res = 1;
    for(int i = 1; i <= n; i++) res *= 2;
    res--;
    cout << res << "\n";
    duyet(n, 1, 3, 2);
}
