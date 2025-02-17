#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define Point pair <int, int>
#define x first
#define y second
 
int cross(Point A, Point B, Point C){
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}
 
int ToTheLeft(Point A, Point B, Point C){
	//return true if C is to the left of AB
	if(A.y < B.y) swap(A, B);
	else if(A.y == B.y){
		return 0LL;
	}
	if(min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y)){
		if(cross(C, A, B) < 0 && C.y != min(A.y, B.y)) return 1LL;
		return 0LL;
	}
	return 0LL;
}
 
int n, m;
const int Sz = 1007;
Point a[Sz + 1];
Point b[Sz + 1];
 
void Prep(){
	a[n + 1] = a[1]; a[n + 2]  = a[2];
}
 
Point p;
 
void Query(){
	for(int i = 1; i <= n; i++){
		if(cross(a[i], p, a[i + 1]) == 0LL && min(a[i].x, a[i + 1].x) <= p.x && p.x <= max(a[i].x, a[i + 1].x) && min(a[i].y, a[i + 1].y) <= p.y && p.y <= max(a[i].y, a[i + 1].y)){
			cout << "BOUNDARY";
			return;
		}
	}
	//Inside or Outside
	int res = 0;
	for(int i = 1; i <= n; i++){
		res += ToTheLeft(a[i], a[i + 1], p);
//		cout << "threele: " << i << ' ' << i + 1 << ' ' << ToTheLeft(a[i], a[i + 1], p) << "\n";
	}
//	cout << res;
	if(res & 1) cout << "INSIDE";
	else cout << "OUTSIDE";
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	for(int i = 1; i <= m; i++) cin >> b[i].x >> b[i].y;
	
	Prep();
	
	for(int i = 1; i <= m; i++){
		p = b[i];
		Query(); cout << "\n";
	}
}
