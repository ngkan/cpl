#include <bits/stdc++.h>
using namespace std;
struct edge{
	int v,w;
	edge(int v=0,int w=0): v(v), w(w) {}
};
const int N = (int) 5e5;
typedef pair<int,int> ii;
int n,m,p,k;
vector <ii> condition[N];
vector <int> a[N], mark[N];
vector <int> G[N];
int seg[400005];
int cnt;
int d[N][2];
int sum[N];
void seg_upd(int id,int l,int r,int pos, int val){
	if (r < pos || pos < l) return;
	if (l == r){
		seg[id] = min(seg[id], val);
		return;
	}
	seg_upd(2*id,l,(l+r)/2,pos,val);
	seg_upd(2*id+1,(l+r)/2+1,r,pos,val);
	seg[id] = min(seg[2*id], seg[2*id+1]);
} 
int seg_get(int id,int l,int r,int u,int v){
	if (r < u || v < l) return (int) 1e9;
	if (u <= l && r <= v) return seg[id];
	return min(seg_get(2*id,l,(l+r)/2,u,v), seg_get(2*id+1,(l+r)/2+1,r,u,v));
}
void init(){
	iostream::sync_with_stdio(0);
	cin >> n >> m >> p >> k;
	for(int i=1;i<=p;i++){
		int ni,mi,t;
		cin >> ni >> mi >> t;
		if (t == 0)	condition[ni].push_back(ii(mi,1));
		else 		condition[ni+1].push_back(ii(mi,-1));
		a[ni].push_back(mi);
		a[ni+1].push_back(mi);
	}
	for(int i=1;i<=n;i++){
		a[i].push_back(0);
		a[i].push_back(m);
	}
	/////////////////////////////////////////////////////////
	for(int i=1;i<=n;i++){
		sort(a[i].begin(), a[i].end());
		a[i].resize(unique(a[i].begin(), a[i].end()) - a[i].begin());
		for(int j=0;j<(int)a[i].size();j++) mark[i].push_back(++cnt);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)condition[i].size();j++){
			int dis = condition[i][j].first;
			int pos = lower_bound(a[i].begin(), a[i].end(), dis) - a[i].begin();
			
			if (condition[i][j].second == 1){
				// co canh tu i -> i+1 tren graph
				int pos2 = lower_bound(a[i+1].begin(), a[i+1].end(), dis) - a[i+1].begin();
				G[mark[i][pos]].push_back(mark[i+1][pos2]);
			}
			else{
				// co canh tu i -> i-1 tren graph
				int pos2 = lower_bound(a[i-1].begin(), a[i-1].end(), dis) - a[i-1].begin();
				G[mark[i][pos]].push_back(mark[i-1][pos2]);
			}
		}
	}
}
int main(){
	init();
	for(int i=0;i<N;i++) d[i][0] = d[i][1] = (int) 1e9;
	
	for(int i=0;i<=400004;i++) seg[i] = (int) 1e9;
	for(int j=0;j<(int)a[1].size();j++){
		d[mark[1][j]][0] = 0;
		seg_upd(1,1,m+1,a[1][j]+1,-1);
			//for(int jjj=1;jjj<=m+1;jjj++) cout << seg_get(1,1,m+1,jjj,jjj) << ' '; cout << endl;

	}
	//for(int j=1;j<=m+1;j++) cout << seg_get(1,1,m+1,j,j) << ' '; cout << endl;
	
	for(int i=2;i<=n;i++){
		//cout << i << endl;
		for(int j=a[i].size()-1;j>=0;j--){
			for(int jj=0;jj<(int)G[mark[i][j]].size();jj++)
				d[mark[i][j]][0] = min(d[mark[i][j]][0], d[G[mark[i][j]][jj]][0]);
			//cout << d[mark[i][j]][0] << ' ';
			d[mark[i][j]][0] = min(d[mark[i][j]][0], seg_get(1,1,m+1,a[i][j]+1,m+1) + i);
			//cout << d[mark[i][j]][0] - i << endl;
			seg_upd(1,1,m+1,a[i][j]+1, d[mark[i][j]][0] - i);
		}
		//for(int j=1;j<=m+1;j++) cout << seg_get(1,1,m+1,j,j) << ' '; cout << endl;
	}
	
	for(int i=0;i<=400004;i++) seg[i] = (int) 1e9;
	for(int j=0;j<(int)a[n].size();j++){
		d[mark[n][j]][1] = 0;
		seg_upd(1,1,m+1,a[n][j]+1,-1);
	}
	
	//cout << "? " << a[1][0]<< ' ' << a[1][1] << ' ' << mark[1][0] << ' '<< mark[1][1] << endl;;;
	for(int i=n-1;i>=1;i--){
		//cout << i << ' ' << a[i].size() << endl;
		for(int j=a[i].size()-1;j>=0;j--){
			//cout << j << ' ';
			for(int jj=0;jj<(int)G[mark[i][j]].size();jj++)
				d[mark[i][j]][1] = min(d[mark[i][j]][1], d[G[mark[i][j]][jj]][1]);
				
			d[mark[i][j]][1] = min(d[mark[i][j]][1], seg_get(1,1,m+1,a[i][j]+1,m+1) + (n+1-i));
			
			seg_upd(1,1,m+1,a[i][j]+1, d[mark[i][j]][1] - (n+1-i));
		}
	}
	
	//cout << "k\n";
	int ans = 0;
	
	for(int i=1;i<=n;i++)
		sum[i] = sum[i-1] + (d[mark[i][0]][0] + d[mark[i][0]][1] == 0); // n0 of already good
	int ctrl = 1;
	for(int i=1;i<=n;i++){
		//cout << i << endl;
		while(ctrl <= n && d[mark[i][0]][0] + d[mark[ctrl][0]][1] > k) ctrl++;
		if (i >= ctrl) ans = max(ans,  i - ctrl + 1 - sum[i] + sum[ctrl-1]);
		//cout << i << ' ' << ctrl << ' ' << d[mark[i][0]][0]  << ' ' << d[mark[i][0]][1] << endl;
	}
	cout << ans;
}
