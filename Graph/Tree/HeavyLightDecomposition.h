/**
 * Heavy-light decomposition
 * Author: adamant (?)
 * Description: Decompose tree into chains, such that the path from a vertex to
 * the root has at most log(n) chains.
 * Status: OK.
 */

namespace HLD{
	int sz[N], nxt[N], in[N], out[N], t;

	void dfs_sz(int u, int p) {
		sz[u] = 1;
		for(auto &v: g[u]) {
			if (v == p)	
				continue;
			dfs_sz(v, u);
			sz[u] += sz[v];
			if(sz[v] > sz[g[u][0]]) 
				swap(v, g[u][0]);
		}
	}

	void dfs_hld(int u, int p) {
		in[u] = t++;
		for(auto v: g[u]) {
			nxt[v] = (v == g[u][0] ? nxt[u] : v);
			dfs_hld(v, u);
		}
		out[u] = t;
	}

	void hld(){
		dfs_sz(1, 0);
		dfs_hld(1, 0);
	}
};
