#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<ll,ll> ii;
#define qual first
#define len second
#define fi first
#define se second
int m,n;
int player[505];
ii val[505];
vector <ii> event[500005];
int beg[10];
bool cmp(int x,int y){
	return val[x].qual > val[y].qual;
}
int main(){
	iostream::sync_with_stdio(0);
	cin >> m >> n;
	for(int i=1;i<=n;i++){
		cin >> val[i].qual >> val[i].len;
		player[i] = i;
	}
	sort(player+1,player+n+1,cmp);
	int len = 0, pivot = 1;
	ll sum = 0;
	int last = 0;
	
	for(int cnt=1;cnt<=6;){
		if (len != 0)
			event[len].push_back(ii(last, player[pivot]));
		else 
			beg[cnt] = last;
			
		last = player[pivot];
		ll x = min(1ll*m - len, val[player[pivot]].len);
		len += x;
		sum += val[player[pivot]].qual * x;
		val[player[pivot]].len -= x;
		
		if (val[player[pivot]].len == 0) pivot ++;
		
		if (len == m) len = 0, cnt++, last = 0;
	}
	
	cout << sum << endl;
	for(int i=1;i<=6;i++) cout << beg[i] << ' '; cout << '\n';
	int cnt = 0;
	for(int i=1;i<=m;i++) cnt += event[i].size();
	cout << cnt << '\n';
	for(int i=1;i<=m;i++){
		for(int j=0;j<event[i].size();j++){
			cout << i << ' ' << event[i][j].fi << ' ' << event[i][j].se << '\n';
		}
	}
}
