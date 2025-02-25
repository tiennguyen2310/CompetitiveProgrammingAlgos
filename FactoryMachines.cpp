#include <bits/stdc++.h>
 
using namespace std;
 
#define int unsigned long long
 
int n, m;
const int Sz = 2e5 + 2;
int a[Sz + 1], b[Sz + 1];
 
string to_String(int N){
	stringstream ss;
	ss << N;
	return ss.str();
}
 
string operator * (string A, int B){
	string res = "";
	int cs, du = 0;
	for(int i = (int)A.size() - 1; i >= 0; i--){
		cs = (A[i] - '0') * B + du;
		res += char(cs % 10 + '0');
		du = cs / 10;
	}
	reverse(res.begin(), res.end());
	if(du != 0) res = to_String(du) + res;
	return res;
}
 
string operator + (string A, string B){
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	while(A.size() < B.size()) A += '0';
	while(B.size() < A.size()) B += '0';
 
	string res = "";
	int cs, du = 0;
	for(int i = 0; i < (int)A.size(); i++){
		cs = (A[i] - '0') + (B[i] - '0') + du;
		res += char(cs % 10 + '0');
		du = cs / 10;
	}
	if(du != 0) res += '1';
	reverse(res.begin(), res.end());
	return res;
}
 
int to_Int(string s){
	int res = 0;
	for(int i = 0; i < (int)s.size(); i++) res = (res * 10) + (s[i] - '0');
	return res;
}
 
bool Ck(int x){
	int nghi, lam;
 
	int res = 0;
 
	for(int i = 1; i <= n; i++){
		lam = x / a[i];
		res += lam;
		if(res >= m) return true;
	}
	return false;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
 
	int l = 1;
	int r = 1e18;
	int mid;
	int res = r;
	while(l <= r){
		mid = l + (r - l) / 2;
		if(Ck(mid)){
			r = mid - 1;
			res = mid;
		}
		else l = mid + 1;
	}
	cout << res;
}
