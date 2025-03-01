#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
string s;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> s;
    sort(s.begin(), s.end());
    int res = 0;
    vector <string> v;
    do
    {
        v.push_back(s);
    } while(next_permutation(s.begin(), s.end()));
    cout << v.size() << "\n";
    for(auto i : v) cout << i << "\n";
}
