#include <bits/stdc++.h>
 
using namespace std;
 
const int Sz = 1e6 + 1;
int cc[Sz + 1];
 
bool ck(int x){
    int cnt = 0;
    for(int i = x; i <= 1e6; i += x){
        cnt += cc[i];
    }
    return (cnt >= 2);
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    int x;
 
    while(n--){
        cin >> x;
        cc[x]++;
    }
 
    int res = 0;
    for(int i = 1; i <= 1e6; i++){
        if(ck(i)) res = i;
    }
    cout << res;
}
