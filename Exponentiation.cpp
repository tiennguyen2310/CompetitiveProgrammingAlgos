#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int MOD = 1e9 + 7;
 
int Pow(int a, int b){
	if(b == 0) return 1;
	if(b == 1) return (a % MOD);
	int res = Pow(a, b / 2);
	res = (res * res) % MOD;
	if(b & 1) res = (res * a) % MOD;
	return res;
}
 
int a, b;
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << Pow(a, b) << "\n";
	}
}
