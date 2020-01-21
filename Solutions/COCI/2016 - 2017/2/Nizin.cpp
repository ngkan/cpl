#include <stdio.h>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
ll res,n,a[1000005],sum[1000005];
bool type1, type2;
ll   pos1 , pos2 ,l,r,suml,sumr;
// type1 aka ....abc|cba.....
// type2 aka ....ab c ba ....
int main(){
    scanf("%lld",&n);
    res = n-1;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),
        sum[i] = sum[i-1] + a[i];
    // no zeros
    for(int i=1;i<=n;i++)
        if (sum[i] * 2 == sum[n]) type1 = 1, pos1 = i;
    for(int i=2;i<=n-1;i++)
        if (sum[n] - sum[i] == sum[i-1]) type2 = 1, pos2 = i;
    if (type1){
        ll cnt = 0;
        l = pos1, r = pos1+1;
        if (l)      suml += a[l];
        if (r <= n) sumr += a[r];
        while(1 <= l && r <= n){
            if (suml < sumr){
                cnt++;
                suml += a[--l];
            }
            else if (suml > sumr){
                cnt++;
                sumr += a[++r];
            }
            else{
                --l;++r;
                if (1 <= l) suml += a[l];
                if (r <= n) sumr += a[r];
            }
        }
        res = min(res,cnt);
    }
    if (type2){
        ll cnt = 0;
        l = pos2 - 1;
        r = pos2 + 1;
        if (l)      suml += a[l];
        if (r <= n) sumr += a[r];
        while(1 <= l && r <= n){
            if (suml < sumr){
                cnt++;
                suml += a[--l];
            }
            else if (suml > sumr){
                cnt++;
                sumr += a[++r];
            }
            else{
                --l;++r;
                if (1 <= l) suml += a[l];
                if (r <= n) sumr += a[r];
            }
        }
        res = min(res,cnt);
    }
    cout << type1 << ' '<< type2 << endl;
    printf("%lld",res);
}
