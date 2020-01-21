#include <bits/stdc++.h>
using namespace std;
const int M = 300005;
int n,q,a[M],res[M];
int mark[M];
struct fenwick{
    int bit[M];
    void upd(int pos,int val){
        for(;pos<=M;pos+=pos&-pos)
            bit[pos] += val;
    }
    int get(int pos){
        int res = 0;
        for(;pos;pos-=pos&-pos)
            res += bit[pos];
        return res;
    }
};
struct query{
    int l,r,k,pos;
};
query mk(int a,int b,int d){
    query t;
    t.l = a;
    t.r = b;
    t.pos = d;
    return t;
}
bool cmp(query x,query y){
    return x.r < y.r;
}
fenwick fw;
vector <query> ax;
vector <int> nen;
void pre(void){
    for(int i=1;i<=n;i++)
        nen.push_back(a[i]);
    sort(nen.begin(),nen.end());
    nen.resize(distance(nen.begin(),unique(nen.begin(),nen.end())));
    for(int i=1;i<=n;i++)
        a[i] = lower_bound(nen.begin(),nen.end(),a[i]) - nen.begin() + 1;

    sort(ax.begin(),ax.end(),cmp);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        ax.push_back(mk(x,y,i));
    }
    pre();
    int ctrl = 0;
    for(int i=0;i<q;i++){
        while(ctrl+1 <= ax[i].r){
            ctrl ++;
            if (mark[a[ctrl]] > 0) fw.upd(mark[a[ctrl]],-1);
            mark[a[ctrl]] = ctrl;
            fw.upd(ctrl,1);
        }
        res[ax[i].pos] = fw.get(ax[i].r) - fw.get(ax[i].l - 1);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",res[i]);
}
