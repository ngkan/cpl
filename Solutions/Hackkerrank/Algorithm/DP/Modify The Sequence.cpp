#include <bits/stdc++.h>
using namespace std;
int n,a[1000001],ans;
vector <int> eznen;
int fw_tree[1000001];
void fwupd(int pos,int val){
    for(;pos<=n;pos+=pos&-pos) fw_tree[pos] = max(fw_tree[pos],val);
}
int fwget(int pos){
    int res = 0;
    for(;pos>0;pos-=pos&-pos) res = max(res,fw_tree[pos]);
    return res;
}
int POS(int x){
    return lower_bound(eznen.begin(),eznen.end(),x) - eznen.begin() + 1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]); if (a[i] >=i) eznen.push_back(a[i]-i);}
    sort(eznen.begin(),eznen.end());
    unique(eznen.begin(),eznen.end());
    eznen.resize(distance(eznen.begin(),unique(eznen.begin(),eznen.end())));
    for(int i=1;i<=n;i++){
        if (a[i] < i) continue;
        ans = max(ans,fwget(POS(a[i]-i)) + 1);
        fwupd(POS(a[i]-i),fwget(POS(a[i]-i)) + 1);
    }
    cout << n - ans;
}
