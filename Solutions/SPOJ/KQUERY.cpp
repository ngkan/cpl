#include <bits/stdc++.h>
using namespace std;
const int M = 300005;
int n,q,a[M],res[M];
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
query mk(int a,int b,int c,int d){
    query t;
    t.l = a;
    t.r = b;
    t.k = c;
    t.pos = d;
    return t;
}
bool cmp_2(int x,int y){
    return a[x] > a[y];
}
bool cmp(query x,query y){
    return x.k > y.k;
}
fenwick fw;
vector <query> ax;
vector <int> nen;
vector <int> ax2;
void pre(void){
    for(int i=1;i<=n;i++)
        nen.push_back(a[i]),
        ax2.push_back(i);
    for(int i=0;i<q;i++)
        nen.push_back(ax[i].k);
    sort(nen.begin(),nen.end());
    nen.resize(distance(nen.begin(),unique(nen.begin(),nen.end())));
    for(int i=1;i<=n;i++)
        a[i] = lower_bound(nen.begin(),nen.end(),a[i]) - nen.begin() + 1;
    for(int i=0;i<q;i++)
        ax[i].k = lower_bound(nen.begin(),nen.end(),ax[i].k) - nen.begin() + 1;
    sort(ax.begin(),ax.end(),cmp);
    sort(ax2.begin(),ax2.end(),cmp_2);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        ax.push_back(mk(x,y,z,i));
    }
    pre();
    int ctrl = 0;
    for(int i=0;i<q;i++){
        while(ctrl < n && a[ax2[ctrl]] > ax[i].k)
            fw.upd(ax2[ctrl],1),
            ctrl++;
        res[ax[i].pos] = fw.get(ax[i].r) - fw.get(ax[i].l - 1);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",res[i]);
}
