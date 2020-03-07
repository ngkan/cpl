/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

namespace FastIO{
    template<typename T>
    T read(){
        char c; bool neg = 0, met = 0;
        T res = 0;
        while((c = getchar())){
            if (c == '-') 
                met = neg = 1;
            else if (c < 48 || c > 57) 
                if (!met)    continue; else break;
            else
                met = 1,
                res = (res<<3) + (res<<1) + c - '0';
        }
        if (neg)    res = -res;
        return res;
    }

    template<typename T>
    void write(T x){
        if (x < 0)          putchar('-'), write(-x);
        else if (x == 0)    putchar('0');
        else{
            char c[20], n = 0;
            while(x)    c[n++] = '0' + x%10, x/=10;
            while(n--)  putchar(c[n]);
        }
    }
}

#define input FastIO::read<int>
int n, m;
int l[300005], r[300005];
vector <int> E[300005], revE[300005];

bool is_dag(){
	vector <bool> visited(n+1);
	vector <int>  in_degree(n+1);
	queue <int> q;
	
	for(int i=1;i<=n;i++)
		for(auto j: E[i])
			in_degree[j]++;
			
	for(int i=1;i<=n;i++)
		if (!in_degree[i])
			q.push(i);
	
	while(q.size()){
		int u = q.front();
		q.pop();
		visited[u] = 1;
		for(auto v: E[u]){
			if (!(--in_degree[v]))
				q.push(v);
		}
	}
	
	for(int i=1;i<=n;i++){
		if (!visited[i])
			return 0;
	}
	
	return 1;
}

int f[300005];
void cal_f(){
	vector <int>  in_degree(n+1);
	queue <int> q;
	
	for(int i=1;i<=n;i++)
		for(auto j: revE[i])
			in_degree[j]++;
			
	for(int i=1;i<=n;i++){
		if (!in_degree[i])
			q.push(i);
		f[i] = r[i];
	}
		
	while(q.size()){
		int u = q.front();
		q.pop();
		for(auto v: revE[u]){
			f[v] = min(f[v], f[u]-1);
			if (!(--in_degree[v]))
				q.push(v);
		}
	}
}

bool solve(){
	vector <int>  in_degree(n+1);
	priority_queue< pair<int,int>,
					vector<pair<int,int>>,
				    greater<pair<int,int>>> pq;
	
	vector <vector<int>> waitlist(n+1);
	
	for(int i=1;i<=n;i++)
		for(auto j: E[i])
			in_degree[j]++;
	
	for(int i=1;i<=n;i++)
		if (!in_degree[i])
			waitlist[l[i]].push_back(i);
	
	vector <int> ans;
	
	for(int i=1;i<=n;i++){
		for(auto v: waitlist[i])
			pq.push({f[v], v});
		
		if (pq.empty() || pq.top().first < i)
			return 0;
		
		int u;
		ans.push_back(u = pq.top().second);
		pq.pop();
		
		for(auto v: E[u]){
			if (!(--in_degree[v])){
				if (l[v] <= i)
					pq.push({f[v], v});
				else
					waitlist[l[v]].push_back(v);
			}
				
		}
	}
	
	for(auto v: ans)	cout << v << '\n';
	return 1;
}

void ngk(){
	n = input();
	m = input();    
	for(int i=1;i<=n;i++){
		l[i] = input();
		r[i] = input();
	}
	for(int i=1;i<=m;i++){
		int u, v;
		u = input();
		v = input();
		E[u].push_back(v);
		revE[v].push_back(u);
	}
	
	if (!is_dag()){
		printf("-1");
		return;
	}
	
	cal_f();
	
	if (!solve())
		printf("-1");
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}


