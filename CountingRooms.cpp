#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int n, m;
const int Sz = 1000;
char a[Sz + 1][Sz + 1];
int d[Sz + 1][Sz + 1];
int k = 0;
int hx[4] = {1, 0, -1, 0};
int hy[4] = {0, 1, 0, -1};
 
bool Ck(int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n);
}
 
void DFS(int x, int y)
{
    int X, Y;
    for(int i = 0; i < 4; i++)
    {
        X = x + hx[i];
        Y = y + hy[i];
        if(Ck(X, Y) && !d[X][Y] && a[X][Y] == '.')
        {
            d[X][Y] = k;
            DFS(X, Y);
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!d[i][j] && a[i][j] == '.')
            {
                k++;
                d[i][j] = k;
                DFS(i, j);
            }
        }
    }
    cout << k;
}
