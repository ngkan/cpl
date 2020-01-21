#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
class DAGConstruction{
public:
    vector <int> G[50];
    vector <int> construct(vector <int> x){
        vector <ii> a;
        vector <int> res;
        res.push_back(-1);
        for(int i=0;i<x.size();i++)
            a.push_back(ii(x[i]-1,i));
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            for(int j=0;j<i;j++){
                if (!a[i].fi) break;
                G[a[i].se].push_back(a[j].se);
                a[i].fi--;
            }
            if (a[i].fi) return res;
        }
        res.clear();
        for(int i=0;i<x.size();i++)
            for(int j=0;j<G[i].size();j++)
                res.push_back(i),
                res.push_back(G[i][j]);
        return res;
    }
};
int main(){

}
