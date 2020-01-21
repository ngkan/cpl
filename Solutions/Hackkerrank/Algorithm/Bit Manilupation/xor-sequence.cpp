#include <bits/stdc++.h>
using namespace std;
int q;
long long l,r;
long long cal(long long x){
    long long res = 0, t;
    if (x%4 == 1 || x%4 == 2) res += 1;
    for(long long i=1;i<60;i++){
        long long pos = x % (1ll << (i+1));
        t = max(0ll, pos - (1ll<<(i)) + 1) % 2;
        res += (t << i);
    }
    return res;
}
long long cal1(long long x){
    long long res = 0, t;
    if (x%2 == 0) x--;
    if (x%4 == 1) res += 1;
    if (x%8 == 3 || x%8== 5) res += 2;
    for(long long i=2;i<60;i++){
        long long pos = x % (1ll << (i+1));
        t = max(0ll, (pos - (1ll<<(i)) - 1) / 2 + 1) % 2;
        res += (t << i);
    }
    return res;
}
int main(){
    scanf("%d",&q);
    while(q--){
        long long res = 0;
        scanf("%lld %lld",&l,&r);
        if ((l-1) % 2) res ^= (cal1(l-1));
        else res ^= (cal(l-1) ^ cal1(l-1));
        if (r % 2) res ^= (cal1(r));
        else res ^= (cal(r) ^ cal1(r));
        printf("%lld\n",res);
    }
}
