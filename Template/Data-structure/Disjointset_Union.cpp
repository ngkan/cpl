#include <bits/stdc++.h>
using namespace std;

struct Dsu{
    vector <int> p, sz;
    Dsu(int n = 0){
        p.assign(n+1, 0);
        sz.assign(n+1, 0);
        for(int i=1;i<=n;i++)
            p[i] = i,
            sz[i] = 1;
    }
    int tree(int x){
        return x == p[x] ? x : p[x] = tree(p[x]);
    }
    int treeSize(int x){
        return sz[tree(x)];
    }
    void merge(int x,int y){
        x = tree(x);    y = tree(y);    
        if (x == y) return;
        if (sz[x] < sz[y])  swap(x, y);
        sz[x] += sz[y];
        p[y] = x;
    }
};