#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,w,a[100005];
int st[100005];
bool check(int x){
    int cnt = m,curr=0;
    memset(st,0,sizeof(st));
    for(int i=1;i<=n;i++){
        curr -= i-w>0ll? st[i-w]:0ll;
        cnt -= max(0ll,x - a[i] - curr);
        st[i] += max(0ll,x - a[i] - curr);
        curr += max(0ll,x - a[i] - curr);
    }
    return cnt >= 0;
}
int chatnp(int l,int r){
    int mid = (l+r)/2;
    if (r-l<=1){
        if (check(r)) return r;
        return l;
    }
    if (check(mid)) return chatnp(mid,r);
    return chatnp(l,mid);
}
main(){
    scanf("%I64d %I64d %I64d",&n,&m,&w);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    printf("%I64d",chatnp(1ll,1000100000ll));
}
