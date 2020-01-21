#include "grader.h"
#include <bits/stdc++.h>
using namespace std;

int n;
int dsup[1505], dsusize[1505];
int cnt[1505][1505];
int dsu_p(int x){
    return dsup[x] == x ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    x = dsu_p(x);
    y = dsu_p(y);
    if (dsusize[x] < dsusize[y])
        swap(x, y);
    for(int i=0;i<n;i++){
        if (i != x && i != y && dsu_p(i) == i)
            cnt[x][i] += cnt[y][i],
            cnt[i][x] += cnt[i][y];
    }
    dsusize[x] += dsusize[y];
    dsup[y] = x;
}
void initialize(int N) {
    n = N;
    for(int i=0;i<n;i++)    dsup[i] = i, dsusize[i] = 1;
}

int hasEdge(int u, int v) {
    u = dsu_p(u);
    v = dsu_p(v);
    if (cnt[u][v] == dsusize[u] * dsusize[v] - 1){
        dsu_union(u, v);
        return 1;
    }
    else{
        ++ cnt[u][v];
        ++ cnt[v][u];
        return 0;
    }
}
