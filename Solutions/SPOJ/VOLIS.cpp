#include <iostream>
#include <limits.h>
using namespace std;
int n,a[1005],d,res[1005],tmp[1005];
int main(){
    for(int i=1;i<=1000;i++) res[i] = INT_MAX;
    cin >> n >> d;
    for(int i=1;i<=n;i++)  cin >> a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            tmp[j+1] = INT_MAX;
            if (a[i] + d < res[j]) continue;
            tmp[j+1] = max(res[j],a[i] - d);
        }
        for(int j=0;j<=n;j++)
            res[j] = min(res[j],tmp[j]);
    }
    for(int i=n;i>=0;i--) if (res[i] != INT_MAX) return cout << i,0;
}
