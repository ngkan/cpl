#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int seg[20*N + 5], L[20*N + 5], R[20*N + 5], root[N+5], _index;
int n, a[N+5], q;
vector <int> ax;
int build0(int id,int l,int r){
    if (l == r) return -1;
    L[id] = ++_index;
    R[id] = ++_index;
    build0(L[id],l,(l+r)/2);
    build0(L[id],(l+r)/2+1,r);
}
int pst_upd(int id,int l,int r,int pos){
    int ID = ++_index, mid = (l+r)/2;
    if (l == r){
        seg[ID] ++;
        return ID;
    }
    L[ID] = L[id];
    R[ID] = R[id];
    if (pos <= mid) L[ID] = pst_upd(L[ID],l,mid,pos);
    else            R[ID] = pst_upd(R[ID],mid+1,r,pos);
    seg[ID] = seg[L[ID]] + seg[R[ID]];
    return ID;
}
int pst_get(int id,int l,int r,int u,int v){
    int mid = (l+r)/2;
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    return pst_get(L[id],l,mid,u,v) + pst_get(R[id],mid+1,r,u,v);
}
bool cmp(int x,int y){
    return a[x] < a[y];
}
int main(){
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),
        ax.push_back(i);
    sort(ax.begin(),ax.end(),cmp);
    ax.insert(ax.begin(),0);
    root[0] = ++_index;
    build0(root[0],1,n);
    for(int i=1;i<ax.size();i++)
        root[i] = pst_upd(root[i-1],1,n,ax[i]);
    while(q--){
        int i,j,k;
        scanf("%d %d %d",&i,&j,&k);
        int le = 1, ri = n;
        while(le != ri){
            if (ri - le <= 1){
                if (pst_get(root[le],1,n,i,j) >= k) ri = le;
                else le = ri;
            }
            int mid = (le + ri)/2;
            if (pst_get(root[mid],1,n,i,j) >= k) ri = mid;
            else le = mid;
        }
        printf("%d\n",a[ax[le]]);
    }
}
