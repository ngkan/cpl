#include <bits/stdc++.h>
using namespace std;
int n,k,a[100005],ans = 1999999999;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n-k+1;i++) ans = min(ans,a[i+k-1] - a[i]);
    printf("%d",ans);
}
