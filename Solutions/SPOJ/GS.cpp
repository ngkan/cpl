#include <bits/stdc++.h>
using namespace std;
int test,n,s,t;
double w[20][20],tot[20];
double mat[20][20];
double eps = 1e-7;
bool ok[20];
void init(){
    memset(w,0,sizeof(w));
    memset(tot,0,sizeof(tot));
    cin >> n >> s >> t;
    for(int i=1;i<n;i++){
        int x,y; double c;
        cin >> x >> y >> c;
        w[x][y] = w[y][x] = c;
        tot[x] += c;
        tot[y] += c;
    }
}
void solve(){
    memset(mat,0,sizeof(mat));
    memset(ok,0,sizeof(ok));
    #define last n+1
    for(int i=1;i<=n;i++){
        if (i == t) continue;
        for(int j=1;j<=n;j++){
            if (j == i) mat[i][j] = 1.0;
            else mat[i][j] = - w[j][i] / tot[i];
        }
        mat[i][t] = 0;
        mat[i][last] = 1.0;
    }
    mat[t][t] = 1;
    vector <int> choose;
    for(int i=1;i<=n;i++){
        int u;
        for(u=1;u<=n;u++)   if (!ok[u] && abs(mat[u][i]) > eps) break;
        ok[u] = 1;
        choose.push_back(u);
        for(int j=last;j>=i;j--)
            mat[u][j] /= mat[u][i];
        for(int v=1;v<=n;v++)
            if(!ok[v])
                for(int j=last;j>=i;j--)
                    mat[v][j] -= mat[u][j] * mat[v][i];
    }
    for(int i=n;i>=1;i--){
        #define u choose[i-1]
        for(int j=1;j<i;j++){
            #define v choose[j-1]
            mat[v][last] -= mat[u][last] * mat[v][i] / mat[u][i];
            mat[v][i] = 0.0;
            #undef v
        }
        mat[u][i] = 1.0;
        #undef u
    }
    cout << mat[choose[s-1]][last] << endl;
    #undef last
}
int main(){
    cout << fixed << setprecision(5);
    cin >> test;
    while(test--){
        init();
        solve();
    }
}
