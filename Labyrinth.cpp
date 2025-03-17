#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
 
int m, n;
const int Sz = 1000;
char a[Sz + 1][Sz + 1];
pair <int, int> xp, kt;
 
void Read()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 'A') xp = {i, j};
            else if(a[i][j] == 'B') kt = {i, j};
        }
    }
}
 
int hx[4] = {0, 1, 0, -1};
int hy[4] = {1, 0, -1, 0};
pair <int, int> pre[Sz + 1][Sz + 1];
int Len[Sz + 1][Sz + 1];
bool d[Sz + 1][Sz + 1];
 
bool Ckdiem(int x, int y)
{
    return (x >= 1 && x <= m && y >= 1 && y <= n && d[x][y] == 0);
}
 
void xuli()
{
    cout << "YES\n" << Len[kt.fi][kt.se] << "\n";
    vector <pair <int, int> > res;
    pair <int, int> tmp = kt;
    while(tmp != xp)
    {
        res.push_back(tmp);
        tmp = pre[tmp.fi][tmp.se];
    }
    res.push_back(tmp);
    reverse(res.begin(), res.end());
    pair <int, int> trc, sau;
    string s = "";
    for(int i = 0; i < res.size() - 1; i++)
    {
        trc = res[i];
        sau = res[i + 1];
        if(trc.fi == sau.fi)
        {
            if(trc.se < sau.se) s += 'R';
            else s += 'L';
        }
        else
        {
            if(trc.fi < sau.fi) s += 'D';
            else s += 'U';
        }
    }
    cout << s;
}
 
void BFS(int x, int y)
{
    d[x][y] = 1;
    queue <pair <int, int> > q;
    q.push({x, y});
    pair <int, int> u, v;
    while(q.size())
    {
        u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            v = {u.fi + hx[i], u.se + hy[i]};
            if(Ckdiem(v.fi, v.se) && a[v.fi][v.se] != '#')
            {
                q.push(v);
                d[v.fi][v.se] = 1;
                Len[v.fi][v.se] = Len[u.fi][u.se] + 1;
                pre[v.fi][v.se] = u;
                if(v == kt)
                {
                    xuli();
                    exit(0);
                }
            }
        }
    }
    cout << "NO";
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
 
    if(xp == kt)
    {
        cout << "YES\n0";
        return 0;
    }
 
    BFS(xp.fi, xp.se);
}
