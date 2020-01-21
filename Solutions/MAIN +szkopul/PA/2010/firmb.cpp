#include <bits/stdc++.h>
using namespace std;
struct event{
    char type;
    int x,y;
};
event mk_event(char c,int a,int b){
    event tmp;
    tmp.type = c; tmp.x = a; tmp.y = b;
    return tmp;
}
vector <event> ls;
vector <int> G[200005];
vector <int> level[200005];
vector <int> fw_tree[200005];
int beg[200005],fin[200005],r4nk[200005],dtime,n;
void fw_upd(int pos,int lv){
    for(;pos<=level[lv].size();pos+=pos&-pos) fw_tree[lv][pos] ++;
}
int fw_get(int pos,int lv){
    int res = 0;
    for(;pos>0;pos-=pos&-pos) res += fw_tree[lv][pos];
    return res;
}
void dfs(int u){
    beg[u] = ++dtime;
    level[r4nk[u]].push_back(u);
    for(int i=0;i<G[u].size();i++){
        r4nk[G[u][i]] = r4nk[u] + 1;
        dfs(G[u][i]);
    }
    fin[u] = dtime;
}
int find1(int x,int lv){
    int l = 0,r = level[lv].size() -1;
    while(l <= r){
        if (r-l <= 1){
            if (beg[x] <= beg[level[lv][l]]) return l;
            if (beg[x] <= beg[level[lv][r]]) return r;
            return -1;
        }
        int mid = (l+r)/2;
        if (beg[x] <= beg[level[lv][mid]]) r = mid;
        else l = mid;
    }
}
int find2(int x,int lv){
    int l = 0,r = level[lv].size() -1;
    while(l <= r){
        if (r-l <= 1){
            if (fin[level[lv][r]] <= fin[x]) return r;
            if (fin[level[lv][l]] <= fin[x]) return l;
            return -1;
        }
        int mid = (l+r)/2;
        if (fin[level[lv][mid]] <= fin[x]) l = mid;
        else r = mid;
    }
}
int main(){
    scanf("%d",&n);
    ls.assign(n+5,mk_event(1,1,1));
    for(int i=0;i<n;i++)    scanf("\n%c %d %d",&ls[i].type,&ls[i].x,&ls[i].y);
    for(int i=0;i<n;i++)
        if (ls[i].type == 'Z') G[ls[i].y].push_back(ls[i].x);
    dfs(1);
    for(int i=0;i<=200000;i++) fw_tree[i].assign(level[i].size()+5,0);
    for(int i=0;i<n;i++){
        if (ls[i].type == 'Z'){
            int pos = find1(ls[i].x,r4nk[ls[i].x]);
            fw_upd(pos+1,r4nk[ls[i].x]);
        }
        else{
            int x = ls[i].x, degree=r4nk[ls[i].x] + ls[i].y + 1;
            if (!level[degree].size()) printf("0\n");
            else{
                int pos1 = find1(x,degree);
                int pos2 = find2(x,degree);
                if (pos1 == -1 || pos2 == -1) {printf("0\n");continue;}
                printf("%d\n",max(fw_get(pos2+1,degree) - fw_get(pos1,degree),0));
            }
        }
    }
}
