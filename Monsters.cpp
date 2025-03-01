#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int m, n;
const int Sz = 1000 + 7;
char a[Sz + 1][Sz + 1];
 
void Read(){
	cin >> m >> n;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
}
 
const int hx[4] = {0, 1, 0, -1};
const int hy[4] = {1, 0, -1, 0};
 
bool vis[Sz + 1][Sz + 1];
bool visM[Sz + 1][Sz + 1];
int LenM[Sz + 1][Sz + 1];
int LenA[Sz + 1][Sz + 1];
 
bool Ck(pair <int, int> &A){
	return (A.first >= 1 && A.first <= m && A.second >= 1 && A.second <= n && !visM[A.first][A.second] && a[A.first][A.second] != '#');
}
 
bool Ck2(pair <int, int> &A){
	return (A.first >= 1 && A.first <= m && A.second >= 1 && A.second <= n && !vis[A.first][A.second] && a[A.first][A.second] != '#');
 
}
 
void BFSM(){
	queue <pair <int, int> > q;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 'M'){
				visM[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	pair <int, int> u, v;
	
	while(q.size()){
		u = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			v = make_pair(u.first + hx[i], u.second + hy[i]);
			if(Ck(v)){
				visM[v.first][v.second] = true;
				LenM[v.first][v.second] = LenM[u.first][u.second] + 1;
				q.push(v);
			}
		}
	}
}
 
char Trace[Sz + 1][Sz + 1];
 
void BFSA(){
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++) Trace[i][j] = 'P';
	}
	queue <pair <int, int> > q;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j] == 'A'){
				LenA[i][j] = 0;
				vis[i][j] = true;
				q.push(make_pair(i, j));
				break;
			}
		}
	}
	pair <int, int> u, v;
	while(q.size()){
		u = q.front();
		q.pop();
		for(int i = 0; i < 4; i++){
			v = make_pair(u.first + hx[i], u.second + hy[i]);
			
			if(Ck2(v)){
				if(LenA[u.first][u.second] + 1 < LenM[v.first][v.second] || !visM[v.first][v.second]){
					LenA[v.first][v.second] = LenA[u.first][u.second] + 1;
					vis[v.first][v.second] = true;
					if(i == 0) Trace[v.first][v.second] = 'R';
					else if(i == 1) Trace[v.first][v.second] = 'D';
					else if(i == 2) Trace[v.first][v.second] = 'L';
					else Trace[v.first][v.second] = 'U';
					q.push(v);
				}
			}
		}
	}
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Read();
	
	BFSM();
	
	BFSA();
	
	pair <int, int> kt = make_pair(-1, -1);
	
	for(int i = 1; i <= m; i++){
		if(vis[i][1]){
			kt = make_pair(i, 1);
			break;
		}
		if(vis[i][n]){
			kt = make_pair(i, n);
			break;
		}
	}
	for(int j = 1; j <= n; j++){
		if(vis[1][j]){
			kt = make_pair(1, j);
			break;
		}
		if(vis[m][j]){
			kt = make_pair(m, j);
			break;
		}
	}
	if(kt.first == -1 || kt.second == -1){
		cout << "NO";
		return 0;
	}
	cout << "YES\n" << LenA[kt.first][kt.second] << "\n";
	deque <char> res;
	while(Trace[kt.first][kt.second] != 'P'){
		res.push_front(Trace[kt.first][kt.second]);
		if(Trace[kt.first][kt.second] == 'R'){
			kt.second--;
		}
		else if(Trace[kt.first][kt.second] == 'D'){
			kt.first--;
		}
		else if(Trace[kt.first][kt.second] == 'L'){
			kt.second++;
		}
		else{
			kt.first++;
		}
	}
	for(auto i : res) cout << i;
}
