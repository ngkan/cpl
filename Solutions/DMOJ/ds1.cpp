#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,a[100005],fw[3][100005];
void upd(ll type,ll pos,ll val){
    if (type == 1) for(;pos<=n;pos+=pos&-pos) fw[type][pos] += val;
    else for(;pos<=100000;pos+=pos&-pos) fw[type][pos] += val;
}
ll get(ll type,ll pos){
    ll res = 0;
    for(;pos;pos-=pos&-pos) res += fw[type][pos];
    return res;
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        upd(1,i,a[i]);
        upd(2,a[i],1);
    }
    while(q--){
        char c; int l,r;
        cin >> c;
        if (c == 'S'){
            cin >> l >> r;
            cout << get(1,r) - get(1,l-1) << endl;
        }
        else if (c == 'Q'){
            cin >> l;
            cout << get(2,l) << endl;
        }
        else{
            cin >> l >> r;
            upd(1,l,-a[l]);
            upd(2,a[l],-1);
            a[l] = r;
            upd(1,l,a[l]);
            upd(2,a[l],1);
        }
    }
}
