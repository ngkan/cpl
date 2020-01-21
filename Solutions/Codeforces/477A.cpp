#include <stdio.h>
#define ll long long
const ll mod = (ll)1e9+7;
ll a,b;
int main(){
    scanf("%lld %lld",&a,&b);
    printf("%lld",(b-1)*b/2ll%mod*(a*(a+1)/2%mod*b%mod + a)%mod);
}
