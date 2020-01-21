#include <bits/stdc++.h>
#define mod 1000000007ll
using namespace std;
struct point{
    long long x,y;
};
point mk_p(long long xx,long long yy){
    point tmp;
    tmp.x = xx; tmp.y = yy;
    return tmp;
}
long long _pow(long long x,long long p){
    if (!p) return 1ll;
    long long tmp = _pow(x,p/2);
    if (p%2) return tmp*tmp%mod*x%mod;
    return tmp*tmp%mod;
}
long long facto[200005],inv[200005];
void pre(){
    facto[0] = 1ll;
    inv[0] = 1ll;
    for(long long i=1;i<=200000;i++) facto[i] = (facto[i-1] * i)%mod;
    for(long long i=1;i<=200000;i++) inv[i] = _pow(facto[i],mod-2);
}
long long Ckn(long long K,long long N){
    return facto[N] * inv[K] % mod * inv[N-K] % mod;
}
long long res = 0;
long long _(long long x){
    while(x < mod) x+=mod;
    x%=mod;
    return x;
}
//bool cmp(point x,)
long long h,w,n;
int main(){
    pre();

    scanf("%I64d %I64d %I64d",&h,&w,&n);
    //res = Ckn(h-1,h+w-2);
    //cout << res << endl;
    for(int i=1;i<=n;i++){
        long long x,y;
        scanf("%I64d %I64d",&x,&y);
        res = _(res - Ckn(x-1,x+y-2) * Ckn(h-x,h+w-x-y) % mod);
        //cout << res << ' ' << Ckn(x-1,x+y-2) << ' ' << Ckn(h-x,h+w-x-y) << endl;
    }
    cout << res;
}
