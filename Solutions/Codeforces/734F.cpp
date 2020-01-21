#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = (int) 2e5 + 5;
ll n, a[N], b[N], c[N], d[N], sum;
ll cnt[65];
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)   scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)   scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)   d[i] = b[i] + c[i], sum += d[i];
    if (sum % (2*n)) return printf("-1"),0;
    sum /= (2*n);
    for(int i=1;i<=n;i++){
        a[i] = d[i] - sum;
        if (a[i] % n) return printf("-1"),0;
        a[i] /= n;
        if (a[i] < 0) return printf("-1"),0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=30;j++)
            cnt[j] += (((1<<j) & a[i]) > 0);
    }
    for(int i=1;i<=n;i++){
        // cal c[i]
        int ahi = 0;
        for(int j=0;j<=30;j++){
            if (((1<<j) & a[i])) ahi += (1<<j) * cnt[j];
        }
        if (ahi != b[i] && d[i] - ahi != c[i]) return printf("-1"),0;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
}
