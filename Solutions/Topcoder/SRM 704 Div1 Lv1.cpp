#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
class TreeDistanceConstruction{
public:
    int root;
    vector <int> G[50];
    bool ok[50];
    int p[50];
    int check(int u,int p,int lv){
        int res = lv;
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if (v == p) continue;
            res = max(res,check(v,u,lv+1));
        }
        return res;
    }
    vector <int> construct(vector <int> d){
        memset(ok,0,sizeof(ok));
        vector <ii> a;
        for(int i=0;i<d.size();i++)
            a.push_back(ii(d[i],i));
        sort(a.begin(),a.end());

        int tmp = 0;
        ok[0] = 1;
        for(int i=1;i<a.size();i++)
            if (a[i].fi > a[tmp].fi)
                G[a[tmp].se].push_back(a[i].se),
                G[a[i].se].push_back(a[tmp].se),
                ok[i] = 1,
                tmp = i;
        //cout << ok[1] << endl;
        tmp = 0;
        root = 0;
        int last = 0;
        for(int i=1;i<a.size();i++){
            if (ok[i]) continue;
            if (a[i].fi == a[root].fi)
                G[a[root].se].push_back(a[i].se),
                G[a[i].se].push_back(a[root].se),
                root = i,
                last = root;
            else{
                if (a[i].fi == a[last].fi)
                    G[a[p[last]].se].push_back(a[i].se),
                    G[a[i].se].push_back(a[p[last]].se),
                    p[i] = p[last];
                else
                    G[a[last].se].push_back(a[i].se),
                    G[a[i].se].push_back(a[last].se),
                    p[i] = last,
                    last = i;
            }
            //cout << root << ' ' << last << endl;
        }
        vector <int> ans;
//        for(int i=0;i<d.size();i++)
//            for(int j=0;j<G[i].size();j++)
//                cout << i << ' ' << G[i][j] << endl;
        for(int i=0;i<d.size();i++){
            //cout << i << endl;
            //cout << check(i,i,0) << endl;
            if (check(i,i,0) != d[i]) return ans;
        }

        for(int i=0;i<d.size();i++)
            for(int j=0;j<G[i].size();j++)
                if (G[i][j] > i)
                    ans.push_back(i),
                    ans.push_back(G[i][j]);
        return ans;
        }
};
int main(){
    TreeDistanceConstruction a;
    vector <int> d;
    d.push_back(5);d.push_back(4);d.push_back(3);d.push_back(3);d.push_back(4);d.push_back(5);d.push_back(5);
    a.TreeDistanceConstruction::construct(d);
}
