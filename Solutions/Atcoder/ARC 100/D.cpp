#include <bits/stdc++.h>
using namespace std;
long long n, a[200005];
int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i],
        a[i] += a[i-1];

    int pivot[4] = {1,1,1,1};

    long long ans = (long long) 1e18;
    for(int i=2;i<=n-2;i++){
        while(pivot[1]+1 < i && abs(a[i] - 2ll * a[pivot[1]]) >= abs(a[i] - 2ll * a[pivot[1]+1]))    pivot[1]++;

        pivot[3] = max(pivot[3], i+1);
        while(pivot[3]+1 < n && abs(a[n] - 2ll * a[pivot[3]] + a[i]) >= abs(a[n] - 2ll * a[pivot[3]+1] + a[i]))    pivot[3]++;

        long long ma = max(max(a[pivot[1]], a[i]-a[pivot[1]]), max(a[pivot[3]] - a[i], a[n] - a[pivot[3]]));
        long long mi = min(min(a[pivot[1]], a[i]-a[pivot[1]]), min(a[pivot[3]] - a[i], a[n] - a[pivot[3]]));
        ans = min(ans, ma - mi);
    }
    cout << ans;
}
