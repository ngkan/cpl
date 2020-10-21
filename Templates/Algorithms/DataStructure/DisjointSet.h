/**
 * Disjoint-set data structure.
 * Status: Untested
 */

struct DSU{
    vector <int> p, sz;
    DSU(int n = 0): p(n), sz(n, 1)  { for(int i=0;i<n;i++) p[i] = i;}
    int find(int x)     { return x == p[x] ? x : p[x] = find(p[x]); }
    int get_size(int x) { return sz[find(x)]; }
    void merge(int x,int y){   
        if ((x = find(x)) == (y = find(y))) return;
        if (sz[x] < sz[y])  swap(x, y);
        sz[x] += sz[y];
        p[y] = x;
    }
};