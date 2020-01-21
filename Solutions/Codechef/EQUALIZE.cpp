#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[1005][1005],tmp[1005][1005],sum[1005][1005];
bool can(int val,int k,int l){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tmp[i][j] = (a[i][j] >= val);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + tmp[i][j];
    for(int i=k;i<=n;i++)
        for(int j=l;j<=m;j++)
            if (sum[i][j] - sum[i-k][j] - sum[i][j-l] + sum[i-k][j-l] >= (k*l)/2+1) return 1;
    return 0;
}
int solve(int k,int l){
    int L = 0;
    int r = (int) 1e7;
    while(r - L > 1){
        int mid = ((L + r) >> 1);
        if (can(mid,k,l)) L = mid;
        else r = mid;
    }
    if (can(r,k,l)) return r;
    return L;
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    while(q--){
        int k,l;
        scanf("%d %d",&k,&l);
        printf("%d\n",solve(k,l));
    }
}
