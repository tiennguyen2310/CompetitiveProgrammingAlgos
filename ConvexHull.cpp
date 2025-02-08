#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define Point pair <int, int> 
#define bit(n,i) ((n >> i) & 1)
#define x first
#define y second
 
int cross(Point A, Point B, Point C){
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}
 
vector <Point> convex_hull(vector <Point> &a){
	vector <Point> up, down;
	sort(a.begin(), a.end());
	Point p1 = a[0];
	Point p2 = a.back();
	up.push_back(p1);
	down.push_back(p1);
	
	for(int i = 1; i < (int)a.size(); i++){
		if(i == (int)a.size() - 1 || cross(p1, a[i], p2) <= 0){
			while(up.size() >= 2 && cross(up[up.size() - 2], up.back(), a[i]) > 0) up.pop_back();
			up.push_back(a[i]);
		}
		
		if(i == (int)a.size() - 1 || cross(p1, a[i], p2) >= 0){
			while(down.size() >= 2 && cross(down[down.size() - 2], down.back(), a[i]) < 0) down.pop_back();
			down.push_back(a[i]);
		}
	}
	vector <Point> res = up;
	for(int i = (int)down.size() - 2; i > 0; i--) res.push_back(down[i]);
	return res;
}
 
int n;
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	vector <Point> a;
	for(int i = 1, x, y; i <= n; i++){
		cin >> x >> y;
		a.push_back({x, y});
	}
	a = convex_hull(a);
	cout << a.size();
	for(auto i : a) cout << '\n' << i.x << ' ' << i.y;
}
