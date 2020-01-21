#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),
        a[i] -= i;
    sort(a+1,a+n+1);
    long long ans = 0;
    for(int i=1;i<=n;i++){
        ans += abs(a[i] - a[(n+1)/2]);
    }
    cout << ans;
}
