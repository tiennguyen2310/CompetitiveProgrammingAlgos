#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n, x;
const int Sz = 42;
int a[Sz + 1];
int mid;
 
int d1[Sz + 1], d2[Sz + 1];
 
vector <int> v1;
 
void xuli1(){
    int tmp = 0;
    for(int i = 1; i <= mid; i++) tmp += d1[i] * a[i];
    v1.push_back(tmp);
}
 
void duyet1(int x){
    if(x > mid) xuli1();
    else{
        for(int i = 0; i <= 1; i++){
            d1[x] = i;
            duyet1(x + 1);
        }
    }
}
 
vector <int> v2;
 
void xuli2(){
    int tmp = 0;
    for(int i = mid + 1; i <= n; i++) tmp += d2[i] * a[i];
    v2.push_back(tmp);
}
 
void duyet2(int x){
    if(x > n) xuli2();
    else{
        for(int i = 0; i <= 1; i++){
            d2[x] = i;
            duyet2(x + 1);
        }
    }
}
 
vector <pair <int, int> > compress(vector <int> &v){
    vector <pair <int, int> > res;
    sort(v.begin(), v.end());
    int cur = v[0];
    int cnt = 0;
    for(int i = 0; i < (int)v.size(); i++){
        if(v[i] == cur) cnt++;
        else{
            res.push_back(make_pair(cur, cnt));
            cur = v[i];
            cnt = 1;
        }
    }
    res.push_back(make_pair(cur, cnt));
    return res;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
 
    mid = n / 2;
    duyet1(1);
    duyet2(mid + 1);
 
    vector <pair <int, int> > vp1 = compress(v1);
    vector <pair <int, int> > vp2 = compress(v2);
    //for(auto i : vp2) cout << i.first << ' ' << i.second << "\n";
    int k;
    int res = 0;
    for(int i = 0; i < (int)vp1.size(); i++){
        k = lower_bound(vp2.begin(), vp2.end(), make_pair(x - vp1[i].first, -1LL)) - vp2.begin();
        if(vp1[i].first + vp2[k].first == x) res += (vp1[i].second * vp2[k].second);
    }
    cout << res;
}
