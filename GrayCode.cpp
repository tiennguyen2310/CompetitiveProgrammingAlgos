#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define bit(n,i) ((n >> i) & 1)
 
int n;
const int Sz = 16;
bool vis[1 << Sz];
 
void Torch(int x)
{
    for(int i = 0; i < n; i++) cout << bit(x,i);
    cout << "\n";
    vis[x] = true;
    int new_x;
    for(int i = 0; i < n; i++)
    {
        if(bit(x, i))
        {
            new_x = x - (1 << i);
            if(!vis[new_x])
            {
                Torch(new_x);
                break;
            }
        }
        else
        {
            new_x = x + (1 << i);
            if(!vis[new_x])
            {
                Torch(new_x);
                break;
            }
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    Torch(0);
}
