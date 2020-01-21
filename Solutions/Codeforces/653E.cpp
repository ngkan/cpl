#include <bits/stdc++.h>
using namespace std;
int n,m,k;
map <int,bool> notG[300005];
set <int> unvisit;
set <int> :: iterator it;
vector <int> q,tmp;
int cnt1;
void check(int x){
    q.clear();
    tmp.clear();
    unvisit.clear();
    for(int i=x;i<=n;i++) unvisit.insert(i);
    q.push_back(x);
    for(int i=0;i<q.size();i++){
        tmp.clear();
        for(it = unvisit.begin();it != unvisit.end(); it++)
            if (!notG[q[i]][*it])
                tmp.push_back(*it);
        for(int j=0;j<tmp.size();j++){
            unvisit.erase(tmp[j]);
            q.push_back(tmp[j]);
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        notG[x][y] = 1;
        notG[y][x] = 1;
        if (x == 1 || y == 1) cnt1++;
    }
    if (n-1 - cnt1 < k) return printf("impossible"), 0;
    check(1);
    if (unvisit.size()) return printf("impossible"), 0;
    int cnt = 0;
    for(int i=2;i<=n;i++) unvisit.insert(i);
    while(unvisit.size()){
        cnt ++;
        q.clear();
        tmp.clear();
        q.push_back(*unvisit.begin());
        for(int i=0;i<q.size();i++){
            tmp.clear();
            for(it = unvisit.begin();it != unvisit.end(); it++)
                if (!notG[q[i]][*it])
                    tmp.push_back(*it);
            for(int j=0;j<tmp.size();j++){
                unvisit.erase(tmp[j]);
                q.push_back(tmp[j]);
            }
        }
    }
    if (cnt > k) printf("impossible");
    else printf("possible");
}
