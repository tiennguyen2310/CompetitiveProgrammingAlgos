#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
string s;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> s;
    int res = 1;
    int tmpres = 0;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(i == s.size() - 1 || s[i] != s[i + 1])
        {
            res = max(res, tmpres + 1);
            tmpres = 0;
        }
        else tmpres++;
    }
    cout << res;
}
