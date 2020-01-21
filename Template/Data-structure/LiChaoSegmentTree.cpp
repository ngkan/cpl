#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct line{
    ll a, b;
    line(ll a=0,ll b=0): a(a), b(b) {}
    ll get(ll x){
        return a * x + b;
    }
};
struct liChaoSegmentTree{
    line node[4 * 1000000 + 5];
    void reset(){
        for(int i=1;i<=4000000;i++)
            node[i] = {0, (ll) 2e18};
    }
    void addLine(int id,int l,int r, line cur){     // remember to check this (upd on full segment or not)
        bool lef = cur.get(l) < node[id].get(l);
        bool mid = cur.get((l+r)/2) < node[id].get((l+r)/2);
        if (mid)
            swap(node[id], cur);
        if (l == r)
            return;
        else if (lef != mid)
            addLine(2*id, l, (l+r)/2, cur);
        else
            addLine(2*id+1, (l+r)/2+1, r, cur);
    }
    ll get(int id,int l,int r,int pos){
        if (l == r)
            return node[id].get(pos);
        else if (pos <= (l+r)/2)
            return min(node[id].get(pos), get(2*id, l, (l+r)/2, pos));
        else
            return min(node[id].get(pos), get(2*id+1, (l+r)/2+1, r, pos));
    }
};
