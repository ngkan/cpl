#include <bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef pair<int,int> ii;
typedef pair<char,ii> cii;
vector <cii> com;
int t,predsu_p[30001],pretail[30001],precnt,pos[30001],duoi[30001],dsu_p[30001];
bool checkhead[30001];
void init(){
    for(int i=1;i<=30000;i++) predsu_p[i] = i,pretail[i] = i,duoi[i] = i,dsu_p[i] = i;
    scanf("%d",&t);
    com.assign(t,mk('a',mk(0,0)));
    for(int i=0;i<com.size();i++)
        scanf("\n%c %d %d",&com[i].fi,&com[i].se.fi,&com[i].se.se);
}
int predsu_P(int x){return (predsu_p[x] == x) ? x: predsu_p[x] = predsu_P(predsu_p[x]);}
void predsu_union(int x,int y){
    checkhead[predsu_P(x)] = 1;
    duoi[pretail[predsu_P(y)]] = predsu_P(x);
    pretail[predsu_P(y)] = pretail[predsu_P(x)];
    predsu_p[predsu_P(x)] = predsu_P(y);
}
void prepos(int x){
    pos[x] = ++precnt;
    if (duoi[x] != x) prepos(duoi[x]);
}
int dsu_P(int x){return dsu_p[x] == x? x: dsu_p[x] = dsu_P(dsu_p[x]);}
bool dsu_same(int x,int y){return dsu_P(x) == dsu_P(y);}
void dsu_union(int x,int y){dsu_p[dsu_P(x)] = dsu_P(y);}
int main(){
    init();
    for(int i=0;i<com.size();i++){
        if (com[i].fi != 'M') continue;
        predsu_union(com[i].se.fi,com[i].se.se);
    }
    for(int i=1;i<=30000;i++) if (!checkhead[i]) prepos(i);
    for(int i=0;i<com.size();i++){
        if (com[i].fi == 'M') dsu_union(com[i].se.fi,com[i].se.se);
        else{
            if (!dsu_same(com[i].se.fi,com[i].se.se)) printf("-1\n");
            else printf("%d\n",abs(pos[com[i].se.fi] - pos[com[i].se.se]) - 1);
        }
    }
}
