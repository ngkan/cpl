#include <bits/stdc++.h>
using namespace std;
const int N = (int) 8e4+5;
typedef pair<int,int> ii;
typedef pair<ii,int> iiI;
const int father = (int) 1e5;
#define fi first
#define se second
#define ID fi.fi
#define X fi.se
#define TYPE se
int n,m;
int n_NEW;
int x[N][2], y[N][2];
int ballx[N], bally[N], color[N];
vector <int> G[100005];
int ans[100005];

set <int> mjk[100005];
int set_id[100005];
void dfs(int u){
	set_id[u] = u;
	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i];
		dfs(v);
		if (mjk[set_id[v]].size() > mjk[set_id[u]].size()) set_id[u] = set_id[v]; 
	}
	
	set<int>::iterator it;
	
	if (set_id[u] != u){
		for(it = mjk[u].begin(); it != mjk[u].end(); it++) mjk[set_id[u]].insert(*it);
	}
	
	for(int i=0;i<(int)G[u].size();i++){
		int v = G[u][i];
		if (set_id[v] == set_id[u]) continue;
		for(it = mjk[set_id[v]].begin(); it != mjk[set_id[v]].end(); it++) mjk[set_id[u]].insert(*it);
	}
	ans[u] = mjk[set_id[u]].size();
}

vector <int> tmpx;
vector <int> tmpy;
vector <int> tmpc;
vector <iiI> event;

stack <ii> seg[8*N];

int opened[8*N];

bool cmp(iiI a,iiI b){
	if (a.X == b.X){
		return a.TYPE < b.TYPE;
	}
	return a.X < b.X;
}
int GLOB_TIME;
void upd(int id,int l,int r,int u,int v,int val){
	if (r < u || v < l) return;
	if (u <= l && r <= v){
		seg[id].push(ii(val,GLOB_TIME));
		return;
	}
	upd(2*id,l,(l+r)/2,u,v,val);
	upd(2*id+1,(l+r)/2+1,r,u,v,val);
}
void remove(int id,int l,int r,int u,int v){
	if (r < u || v < l) return;
	if (u <= l && r <= v){
		seg[id].pop();
		return;
	}
	remove(2*id,l,(l+r)/2,u,v);
	remove(2*id+1,(l+r)/2+1,r,u,v);
}
ii get(int id,int l,int r,int pos){
	if (r < pos || pos < l) return ii(father, -1);
	if (l == r){
		if (seg[id].size()) return seg[id].top();
		return ii(father, -1);
	}
	ii v1 = get(2*id,l,(l+r)/2,pos);
	if (seg[id].size() && seg[id].top().se > v1.se)
		v1 = seg[id].top();
	ii v2 = get(2*id+1,(l+r)/2+1,r,pos);
	if (v1.se > v2.se) return v1;
	return v2;
}
void prep(){
	iostream::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
		tmpx.push_back(x[i][0]);
		tmpy.push_back(y[i][0]);
		tmpx.push_back(x[i][1]);
		tmpy.push_back(y[i][1]);
	}
	for(int i=1;i<=m;i++){
		cin >> ballx[i] >> bally[i] >> color[i];
		tmpx.push_back(ballx[i]);
		tmpy.push_back(bally[i]);
		tmpc.push_back(color[i]);
	}
	sort(tmpx.begin(), tmpx.end());
	sort(tmpy.begin(), tmpy.end());
	sort(tmpc.begin(), tmpc.end());
	tmpx.resize(unique(tmpx.begin(),tmpx.end()) - tmpx.begin());
	tmpy.resize(unique(tmpy.begin(),tmpy.end()) - tmpy.begin());
	tmpc.resize(unique(tmpc.begin(),tmpc.end()) - tmpc.begin());
	
	for(int i=1;i<=n;i++){
		x[i][0] = lower_bound(tmpx.begin(),tmpx.end(), x[i][0]) - tmpx.begin() + 1;
		x[i][1] = lower_bound(tmpx.begin(),tmpx.end(), x[i][1]) - tmpx.begin() + 1;
		y[i][0] = lower_bound(tmpy.begin(),tmpy.end(), y[i][0]) - tmpy.begin() + 1;
		y[i][1] = lower_bound(tmpy.begin(),tmpy.end(), y[i][1]) - tmpy.begin() + 1;
	}
	for(int i=1;i<=m;i++){
		ballx[i] = lower_bound(tmpx.begin(),tmpx.end(), ballx[i]) - tmpx.begin() + 1;
		bally[i] = lower_bound(tmpy.begin(),tmpy.end(), bally[i]) - tmpy.begin() + 1;
		color[i] = lower_bound(tmpc.begin(),tmpc.end(), color[i]) - tmpc.begin() + 1;
	}
}
int main(){
	prep();
	for(int i=1;i<=n;i++){
		event.push_back(iiI(ii(i, x[i][0]), -1)); // id, open or close, sheet or ball
		event.push_back(iiI(ii(i, x[i][1]), 1));	// change ^ to pos
	}
	for(int i=1;i<=m;i++){
		event.push_back(iiI(ii(i, ballx[i]), 0));
	}
	sort(event.begin(), event.end(), cmp);
	int n_NEW = tmpy.size();
	
	for(int i=0;i<(int)event.size();i++){
		iiI dis = event[i];
		int type = dis.TYPE;
		int id = dis.ID;
		
		GLOB_TIME = i+1;
		if (type != 0){
			if (!opened[id]){
				ii ez = get(1,1,n_NEW,y[id][0]);
				G[ez.fi].push_back(id);
				upd(1,1,n_NEW,y[id][0],y[id][1], id);
				opened[id] = 2;
			}
			else{
				remove(1,1,n_NEW,y[id][0],y[id][1]);
			}
		}
		else
			mjk[get(1,1,n_NEW,bally[id]).fi].insert(color[id]);
		}
	}
	
	dfs(father);

	for(int i=1;i<=n;i++) cout << ans[i] << '\n';
}
