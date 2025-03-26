#include <bits/stdc++.h>

using namespace std;

#define int long long

#define x1 fefhwoejfiojeio
#define x2 seoifjh3yrgv
#define y1 weifhiorvi
#define y2 qweonniosdpf

int n;
const int Sz = 2e6 + 6;

struct Dat{
    int up, down, val;

    Dat(int _u, int _d, int _v){
        up = _u;
        down = _d;
        val = _v;
    }
};

vector <Dat> a[Sz + 1];

int st[Sz << 2 | 1];
int lazy[Sz << 2 | 1];

void update(int id, int l, int r, int u, int v, int k){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        lazy[id] += k;
        if(lazy[id] > 0) st[id] = r - l + 1;
        else{
            //lazy[id] == 0
            if(l < r) st[id] = st[id << 1] + st[id << 1 | 1];
            else st[id] = 0;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, u, v, k);
    update(id << 1 | 1, mid + 1, r, u, v, k);
    if(lazy[id] == 0) st[id] = st[id << 1] + st[id << 1 | 1];
    else assert(st[id] == r - l + 1);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int x1, x2, y1, y2;
    for(int i = 1; i <= n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6 + 1;
        y1 += 1e6 + 1;
        x2 += 1e6 + 1;
        y2 += 1e6 + 1;
        if(y1 + 1 > y2) continue;
        a[x1].push_back(Dat(y1 + 1, y2, 1));
        a[x2].push_back(Dat(y1 + 1, y2, -1));
    }
    int res = 0;
    for(int i = 0; i <= 2e6; i++){
        for(int j = 0; j < (int)a[i].size(); j++) update(1, 1, 2e6 + 1, a[i][j].up, a[i][j].down, a[i][j].val);
        //if(i <= 25) cout << i <<  ' ' << st[1] << "\n";
        res += st[1];
    }
    cout << res;
}
