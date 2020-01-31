/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = (int) 1e9+7;

struct Dsu{
    vector <int> p;
    Dsu(int n = 0){
        p.assign(n+1, 0);
        for(int i=1;i<=n;i++)
            p[i] = i;
    }
    int tree(int x){
        return x == p[x] ? x : p[x] = tree(p[x]);
    }
    void merge(int x,int y){
        x = tree(x);   
        y = tree(y);    
        p[y] = x;
    }
};

Dsu dsu;
int n, m;
string s[1000];
vector <int> G[1000000];
int f[1000000];
int dx[] = {0, 0,  1};
int dy[] = {1, -1, 0};
int get_id(int x,int y){
    return x * 1000 + y;
}
bool top_node[1000000];

void ngk(){
    dsu = Dsu(1000000);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> s[i];
    
    vector <int> lst;
    for(int i=n-2;i>=1;i--){
        for(int j=1;j<=m-2;j++){
            if (s[i][j] != '#' && s[i+1][j] != '#')
                G[get_id(i, j)].push_back(dsu.tree(get_id(i+1, j)));
        }

        for(int j=1;j<=m-2;j++){
            if (s[i][j] == '#')
                continue;
            for(int k=0;k<3;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 0 || n <= x || y < 0 || m <= y || s[x][y] == '#')
                    continue;
                dsu.merge(get_id(i, j), get_id(x, y));
            }
        }

        for(int j=1;j<=m-2;j++){
            if (dsu.tree(get_id(i, j)) != get_id(i, j)){
                for(auto v: G[get_id(i, j)])
                    G[dsu.tree(get_id(i, j))].push_back(v);
            }

            if (s[i][j] == '.') 
                lst.push_back(dsu.tree(get_id(i, j)));  
        }
    }

    sort(lst.begin(), lst.end());
    lst.resize(unique(lst.begin(), lst.end()) - lst.begin());
    for(auto node: lst)
        top_node[node] = 1;
    
    for(auto node: lst){
        sort(G[node].begin(), G[node].end());
        G[node].resize(unique(G[node].begin(), G[node].end()) - G[node].begin());
        for(auto v: G[node])
            top_node[v] = 0;
    }
    for(auto node: lst)
        if (top_node[node]) G[0].push_back(node);

    lst.insert(lst.begin(), 0);

    while(lst.size()){
        int u = lst.back();
        lst.pop_back();

        f[u] = 1;
        for(auto v: G[u])
            f[u]  = 1ll * f[u] * f[v] % mod;
        if (u)
            f[u] = (f[u] + 1) % mod;
        //cout << u << ' ' << f[u] << endl;
        //for(auto v: G[u])   cout << v << ' '; cout << endl;
    }
    cout << f[0];
}

int main(int argc, char *argv[]){
    freopen("cave.in","r",stdin);
    freopen("cave.out","w",stdout);
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}