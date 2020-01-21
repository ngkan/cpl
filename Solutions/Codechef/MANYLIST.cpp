#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
const int N = (int) 1e5 * 2.5 + 5;
set <ii> zt[N];
int fw[N],n,q;
void upd(int pos,int val){
    for(;pos<=n;pos+=pos&-pos) fw[pos] += val;
}
int get(int pos){
    int res = 0;
    for(;pos;pos-=pos&-pos) res += fw[pos];
    return res;
}
void _insert(int x,int l,int r){
    int ml = l, mr = r;
    set<ii>::iterator it;
    while(1){
        it = zt[x].lower_bound(ii(l,-1));
        if (it == zt[x].end()) break;
        ii tmp = *it;
        if (r < tmp.fi) break;
        upd(tmp.fi,-1);
        upd(tmp.se+1,1);
        zt[x].erase(it);
        ml = min(ml, tmp.fi);
        mr = max(mr, tmp.se);
    }
    while(1){
        it = zt[x].lower_bound(ii(l,-1));
        if (it == zt[x].begin()) break;
        it--;
        ii tmp = *it;
        if (tmp.se < l) break;
        upd(tmp.fi,-1);
        upd(tmp.se+1,1);
        zt[x].erase(it);
        ml = min(ml, tmp.fi);
        mr = max(mr, tmp.se);
    }
    upd(ml,1);
    upd(mr+1,-1);
    zt[x].insert(ii(ml,mr));
}
int main(){
    scanf("%d %d",&n,&q);
    while(q--){
        int type,l,r,x;
        scanf("%d",&type);
        if (type == 1){
            scanf("%d",&x);
            printf("%d\n",get(x));
        }
        else{
            scanf("%d %d %d",&l,&r,&x);
            _insert(x,l,r);
        }
    }
}
