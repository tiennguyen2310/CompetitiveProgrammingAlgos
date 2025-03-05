#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define fi first
#define se second
#define int ll
 
string s;
map <char, int> mp;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    int Cnt = 0;
    for(auto i : mp) Cnt += (i.se % 2);
    if(Cnt > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    string res = "";
    string thua = "";
    for(auto i : mp)
    {
        if(i.se % 2 == 0)
        {
            for(int j = 1; j <= i.se / 2; j++) res += i.fi;
        }
        else
        {
            for(int j = 1; j <= i.se; j++) thua += i.fi;
        }
    }
    string rres = res;
    reverse(rres.begin(), rres.end());
    cout << res << thua << rres;
}
