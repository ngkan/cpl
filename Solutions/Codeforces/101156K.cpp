#include <bits/stdc++.h>
#define ll long long
#define LSB(x) (x & -x)
using namespace std;
ll n,mod,a[100005],lis[100005],ans[100005],high,res;
vector<ll> fw[100005];
vector<ll> arr[100005];
void fwupd(ll num,ll pos,ll val){
    if (!num){
        for(;pos<fw[num].size();pos+=LSB(pos)) fw[num][pos] = max(fw[num][pos], val);
    }
    else{
        for(;pos<fw[num].size();pos+=LSB(pos)) fw[num][pos] = (fw[num][pos] + val) % mod;
    }
}
ll fwget(ll num,ll pos){
    ll res=0;
    if (!num){
        for(;pos;pos-=LSB(pos)) res =max(res, fw[num][pos]);
    }
    else{
        for(;pos;pos-=LSB(pos)) res = (res + fw[num][pos]) % mod;
    }
    return res;
}
int main(){
    fw[0].assign(100005,0);
    scanf("%lld %lld",&n,&mod);
    for(int i=1;i<=n;i++){
        arr[i].push_back(0);
        fw[i].push_back(0);
        scanf("%lld",&a[i]);
        fwupd(0, a[i], lis[i] = fwget(0, a[i]-1) + 1);
        fw[lis[i]].push_back(0);
        arr[lis[i]].push_back(a[i]);
        high = max(high,lis[i]);
    }
    for(int i=1;i<=n;i++){
        sort(arr[i].begin(),arr[i].end());
        #define ok max(1ll,lis[i]-1)
        ll pos = lower_bound(arr[ok].begin(),arr[ok].end(),a[i]) - arr[ok].begin() - 1;
        ll pos2 = lower_bound(arr[lis[i]].begin(),arr[lis[i]].end(),a[i]) - arr[lis[i]].begin();
        #undef ok
        if (lis[i] == 1)
            fwupd(1,pos2,ans[i] = 1);
        else
            fwupd(lis[i], pos2, ans[i] = fwget(lis[i]-1,pos));
        if (lis[i] == high) res += ans[i];
    }
    printf("%lld",res%mod);
}
