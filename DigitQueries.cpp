#include <bits/stdc++.h>
 
using namespace std;
 
#define int unsigned long long
 
int k;
 
string to_String(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}
 
void giai()
{
    cin >> k;
    int socs = 1;
    int soso = 9;
    int whocare = 0;
    while(whocare + soso * socs < k)
    {
        whocare += (soso * socs);
        socs++;
        soso *= 10;
    }
    //whocare + soso * socs >= k && whocare < k
    //so can tim co (socs) chu so
    int kcach = k - whocare;
    int sobatdau = 1;
    for(int i = 1; i < socs; i++) sobatdau *= 10;
    int sothumay = (kcach + socs - 1) / socs;
    //cout << kcach << ' ';
    int sodo = sobatdau + sothumay - 1;
    string taocare = to_String(sodo);
    int momke = kcach % socs;
    if(momke == 0) cout << taocare[taocare.size() - 1];
    else cout << taocare[momke - 1];
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    cin >> t;
    while(t--)
    {
        giai();
        cout << "\n";
    }
}
