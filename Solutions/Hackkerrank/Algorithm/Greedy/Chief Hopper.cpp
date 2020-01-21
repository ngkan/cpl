#include <bits/stdc++.h>
using namespace std;
long long n,h[100005];
bool check(long long x){
    long long tmp = x;
    for(int i=1;i<=n;i++){
        tmp = 2 * tmp - h[i];
        if (tmp >= 100000) return 1;
        if (tmp < 0) return 0;
    }
    return 1;
}
long long chatnp(long long l,long long r){
    if (r-l<=1){
        if (check(l)) return l;
        return r;
    }
    int mid = (l+r)/2;
    if (check(mid)) return chatnp(l,mid);
    return chatnp(mid,r);
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&h[i]);
    printf("%lld",chatnp(1,100000));
}
