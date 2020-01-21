#include <bits/stdc++.h>
using namespace std;
int n, totalstrings = 0, f[10005];
vector <int> G[10005];
void predfs(int u,int p){
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        predfs(v,u);
    }
    if (u != 1) totalstrings += (G[u].size()-1) / 2;
    else    totalstrings += (G[u].size()+1) / 2;
}
bool dfs(int u,int p,int val){
    multiset <int> s,s2;
    multiset <int> :: iterator it, it2;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if (v == p) continue;
        if (!dfs(v,u,val)) return 0;
        s.insert(f[v]);
    }
    //cout << u; for(it = s.begin();it != s.end();++it) cout << ' ' << *it; cout << endl;
    while(s.size()){
        int x1,x2;
        it = s.end();   --it;   if (*it > val) return 0;
        it2 = s.upper_bound(val - *it);
        if (it2 == s.begin()){
            s2.insert(*it);
            s.erase(it);
            continue;
        }
        it2--;
        if (*it == *it2){
            if (s.size() % 2 == 1) s2.insert(*s.begin());
            break;
        }
        x1 = *it, x2 = *it2;
        s.erase(it);
        it2 = s.lower_bound(x2);
        s.erase(it2);
    }
    //cout << u << ' ' << s.size() << endl;
    if (s2.size() > 2) return 0;
    if (s2.size() == 2){
        if (u != 1) f[u] = *s2.begin() + 1;
        else{
            it = s2.begin(); ++it;
            if (*it + *s2.begin() > val) return 0;
        }
    }
    if (s2.size() == 1){
        f[u] = *s2.begin() + 1;
    }
    if (s2.size() == 0)
        f[u] = 1;
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    predfs(1,1);    // count nums of minimum strings
    int l = 0, r = n+5;
    while(l + 1 < r){
        //cout << l << ' ' << r << endl;
        int mid = (l+r)/2;
        if (dfs(1,1,mid)) r = mid;
        else l = mid;
    }
    //cout << dfs(1,1,2)<< endl;
    printf("%d %d",totalstrings,r);
}
/*
7
1 2
1 3
2 4
2 5
3 6
 3 7
*/
