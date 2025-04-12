#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int n, q;
const int Sz = 2e5 + 2;
vector <int> adj[Sz + 1];
int lv[Sz + 1];
 
void Read(){
    cin >> n >> q;
    for(int i = 2, u, v; i <= n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
 
int lift[Sz + 1][19];
 
void dfs(int u, int p){
    for(int v : adj[u]){
        if(v == p) continue;
        lv[v] = lv[u] + 1;
        lift[v][0] = u;
        dfs(v, u);
    }
}
 
void Prep(){
    for(int i = 1; (1 << i) <= n; i++){
        for(int j = 1; j <= n; j++){
            if(lv[j] - (1 << i) <= 0) continue;
            lift[j][i] = lift[lift[j][i - 1]][i - 1];
        }
    }
}
 
int lca(int a, int b){
    if(lv[a] < lv[b]) swap(a, b);
    int k = lv[a] - lv[b];
    for(int i = 18; i >= 0; i--){
        if(k >= (1 << i)){
            a = lift[a][i];
            k -= (1 << i);
        }
    }
    if(a == b) return a;
    for(int i = 18; i >= 0; i--){
        if(lv[a] >= (1 << i)){
            if(lift[a][i] != lift[b][i]){
                a = lift[a][i];
                b = lift[b][i];
            }
        }
    }
    return lift[a][0];
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Read();
    lv[1] = 1;
    dfs(1, 1);
    Prep();
 
    int a, b;
    int ll;
    for(int i = 1; i <= q; i++){
        cin >> a >> b;
        ll = lca(a, b);
        if(ll == a || ll == b){
            cout << abs(lv[a] - lv[b]);
        }
        else{
            cout << abs(lv[ll] - lv[a]) + abs(lv[ll] - lv[b]);
        }
        cout << "\n";
    }
}
