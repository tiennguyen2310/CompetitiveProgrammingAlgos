#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
const int Sz = 1e6 + 2;
int uoc[Sz + 1];
 
void Sieve(){
	for(int i = 1; i <= 1e6; i++){
		for(int j = i; j <= 1e6; j += i) uoc[j]++;
	}
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Sieve();
	
	int t;
	cin >> t;
	int x;
	
	while(t--){
		cin >> x;
		cout << uoc[x] << "\n";
	}
}
