#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n;
const int Sz = 2e5 + 2;
int a[Sz + 1];
int st[Sz << 2 | 1];
 
void Build(int id, int l, int r){
    if(l == r){
        st[id]++;
        return;
    }
    int mid = (l + r) >> 1;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
 
void Prep(){
    Build(1, 1, n);
}
 
void Walk(int id, int l, int r, int pos){
    //cout << id << ' ' << l << ' ' << r << ' ' << pos << "\n";
    if(l == r){
        cout << a[l];
        st[id] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= st[id << 1]) Walk(id << 1, l, mid, pos);
    else{
        Walk(id << 1 | 1, mid + 1, r, pos - st[id << 1]);
    }
 
    st[id] = st[id << 1] + st[id << 1 | 1];
}
 
int pos;
 
void Touch(){
    //cout << "walk " << 1 << ' ' << 1 << ' ' << n << ' ' << pos << "\n";
    Walk(1, 1, n, pos);
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n;
    //cout << "nnn " << n << "\n";
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    Prep(); //return 0;
 
    for(int i = 1; i <= n; i++){
        cin >> pos;
        Touch();
        cout << ' '; //return 0;
    }
}
