#include <bits/stdc++.h>
using namespace std;
struct vertex{
    int open,close,now;
    vertex (int x,int y,int z): open(x), close(y), now(z) {}
};
struct segment_tree{
    int n;
    string s;
    vector <vertex> node;
    void init(){
        node.assign(4*n+5,vertex(0,0,0));
        s = "0" + s;
    }
    void build_tree(int id,int l,int r){
        if (r-l == 0){
            if (s[l] == '(') node[id].open ++;
            else node[id].close ++;
            return;
        }
        int mid = (l+r)/2;
        build_tree(2*id,l,mid);
        build_tree(2*id+1,mid+1,r);
        int create = min(node[2*id].open, node[2*id+1].close);
        node[id].now   = node[2*id].now   + node[2*id+1].now   + create;
        node[id].open  = node[2*id].open  + node[2*id+1].open  - create;
        node[id].close = node[2*id].close + node[2*id+1].close - create;
    }
    vertex get(int id,int l,int r,int L,int R){
        if (r < L || R < l) return vertex(0,0,0);
        if (L <= l && r <= R) return node[id];
        int mid = (l+r)/2;
        vertex x1 = get(2*id,l,mid,L,R);
        vertex x2 = get(2*id+1,mid+1,r,L,R);
        int create = min (x1.open, x2.close);
        vertex tmp = vertex(x1.open + x2.open - create, x1.close + x2.close - create, x1.now + x2.now + create);
        return tmp;
    }
};
segment_tree a;
int q,l,r;
int main(){
    iostream::sync_with_stdio(0);
    cin >> a.s;
    a.n = a.s.size();
    a.init();
    a.build_tree(1,1,a.n);
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << a.get(1,1,a.n,l,r).now * 2 << endl;
    }
}
