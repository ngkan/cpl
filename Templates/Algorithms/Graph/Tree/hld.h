/**
 * Heavy-light decomposition
 * Status: ???, need to upgrade
 */

namespace hld{
    /*  root = 1
        vector <int> G[N] also included here
    */
    vector <int> G[N];
    int p[N][17], depth[N], subtreeSize[N]; // check size <------------------------------------------
    int lca(int x,int y){
        if (depth[x] > depth[y])    swap(x, y);
        for(int k=16;k>=0;--k)  if (depth[p[y][k]] >= depth[x]) y = p[y][k];
        if (x == y) return x;
        for(int k=16;k>=0;--k)  if (p[x][k] != p[y][k]) x = p[x][k], y = p[y][k];
        return p[x][0];
    }
    int countChain = 1, segCnt = 0, chain[N], headChain[N], segPos[N], invSegPos[N];/*
        headChain[x] = the first member of chain x
        segPos[x] = position of x on segment tree
        invSegPos[x] = which node is in position x
    */
    void predfs(int u){
        depth[root] = 1;   // depth of root = 1 (remember to change this when necessary) <-------------------------------------------------
        for(int k=1;k<17;++k)
            p[u][k] = p[p[u][k-1]][k-1];
        for(int v: G[u]){
            if (v == p[u][0])   continue;
            p[v][0] = u;
            depth[v] = depth[u] + 1;
            predfs(v);
            subtreeSize[u] += subtreeSize[v];
        }
        ++ subtreeSize[u];
    }
    void build(int u){
        chain[u] = countChain;
        headChain[countChain] = (headChain[countChain] ? headChain[countChain] : u);
        segPos[u] = ++ segCnt;
        invSegPos[segCnt] = u;

        int heavyChild = 0;
        for(int v: G[u]){
            if (v == p[u][0])   continue;
            if (subtreeSize[v] > subtreeSize[heavyChild]) heavyChild = v;
        }

        if (heavyChild)
            build(heavyChild);

        for(int v: G[u]){
            if (v == p[u][0] || v == heavyChild)   continue;
            ++countChain;
            build(v);
        }
    }
    int fw[N];
    void fwReset(){
        for(int i=0;i<N;++i) fw[i] = 0;
    }
    void fwUpd(int pos,int val){
        for(;pos<=n;pos+=pos&-pos) fw[pos] += val;
    }
    int fwGet(int pos){
        int res = 0;
        for(;pos;pos-=pos&-pos) res += fw[pos];
        return res;
    }
    int pathQuery(int x,int y,int u){
        int res = - (fwGet(segPos[u]) - fwGet(segPos[u] - 1));
        while(1){
            if (chain[x] != chain[u]){
                res += fwGet(segPos[x]) - fwGet(segPos[headChain[chain[x]]] - 1);
                x = p[headChain[chain[x]]][0];
            }
            else{
                res += fwGet(segPos[x]) - fwGet(segPos[u] - 1);
                break;
            }
        }
        while(1){
            if (chain[y] != chain[u]){
                res += fwGet(segPos[y]) - fwGet(segPos[headChain[chain[y]]] - 1);
                y = p[headChain[chain[y]]][0];
            }
            else{
                res += fwGet(segPos[y]) - fwGet(segPos[u] - 1);
                break;
            }
        }
        return res;
    }
}
