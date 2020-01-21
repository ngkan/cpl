#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], b[100005];
int main(){
    iostream::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=2;i<=n;i++){
        if (a[i] == 0 && a[i-1] != 0){
            cout << -1;
            return 0;
        }
        b[i] = max(b[i-1]-30, 0ll);

        while(b[i] <= b[i-1] && a[i] < a[i-1] * (1ll << (b[i-1] - b[i])))
            b[i] ++;
        while(b[i] >= b[i-1] && a[i] * (1ll << (b[i] - b[i-1])) < a[i-1])
            b[i] ++;
    }
    long long ans = 0;
    for(int i=1;i<=n;i++)   ans += b[i];
    cout << ans;
}
