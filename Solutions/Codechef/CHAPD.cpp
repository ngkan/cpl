#include <bits/stdc++.h>
using namespace std;
long long test,a,b;
bool process(long long a,long long b){
    if (__gcd(a,b)==1){
        return (a%b==0);
    }
    return process(a,b/__gcd(a,b));
}
int main(){
    scanf("%lld",&test);
    while(test--){
        scanf("%lld %lld",&a,&b);
        if (process(a,b)) printf("Yes\n");
        else printf("No\n");
    }
}
