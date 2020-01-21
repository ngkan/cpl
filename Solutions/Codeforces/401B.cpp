#include <bits/stdc++.h>
using namespace std;
int arr[4005];
bool done[4005];
int n,m,mi,ma;
int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,a,b;
        cin >> x;
        if (x == 1) cin >> a >> b,arr[a] = 2,arr[b]=1,done[a]=1,done[b]=1;
        else cin >> a,arr[a]=2,done[a]=1;
    }
    done[n] = 1; done[n+1] = 1;
    for(int i=1;i<n;i++){
        if (done[i]) continue;
        mi++;ma++;
        if (!done[i] && !done[i+1]) ma++,i++;
    }
    cout << mi << ' ' << ma;
}
