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
set <int> E[100005];
bool visited[100005];


bool check(){
	queue <int> q;
	for(int i=1;i<=n;i++){
		if (E[i].size() == 2)
			visited[i] = 1,
			q.push(i);
	}
	
	while(q.size()){
		int u = q.front();
		q.pop();
		if (E[u].size() != 2){
			visited[u] = 0;
			continue;
		}
		int p = *E[u].begin();
		E[p].erase(u);
		int v = *E[u].rbegin();
		E[v].erase(u);
		E[u].clear();
		E[p].insert(v);
		E[v].insert(p);
		
		if (E[p].size() == 2 && !visited[p])
			visited[p] = 1,
			q.push(p);
		if (E[v].size() == 2 && !visited[v])
			visited[v] = 1,
			q.push(v);
	}
	
	int cnt = 0;
	for(int i=1;i<=n;i++)
		cnt += 1 - visited[i];
	
	return cnt == 2;
}

void ngk(){
	n = input();
	m = input();
	for(int i=1;i<=m;i++){
		int u, v;
		u = input();
		v = input();
		E[u].insert(v);
		E[v].insert(u);
	}
	
	if (check())
		cout << "Yes";
	else
		cout << "No";
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}


