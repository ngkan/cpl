#include <bits/stdc++.h>
using namespace std;
int N,n=100000,a[1000001],ans;
int fw_tree[1000001];
void fwupd(int pos,int val){
    for(;pos<=n;pos+=pos&-pos) fw_tree[pos] = max(fw_tree[pos],val);
}
int fwget(int pos){
    int res = 0;
    for(;pos>0;pos-=pos&-pos) res = max(res,fw_tree[pos]);
    return res;
}
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i];
        ans = max(ans,fwget(a[i]-1)+1);
        fwupd(a[i],fwget(a[i]-1)+1);
    }
    cout << ans;
}
