#include <bits/stdc++.h>
using namespace std;
int n,a[105][105];
int main(){
    scanf("%d",&n);
    if (n == 1) printf("1");
    else if (n == 2) printf("-1");
    else if (n%2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                printf("%d ",(i-1)*n + j);
            printf("\n");
        }
    }
    else{
        for(int i=1;i<n;i++)    a[1][i] = i;
        a[1][n] = (n-1) * n - (n-1)*n/2;
        for(int i=2;i<n;i++){
            for(int j=1;j<=n;j++)
                a[i][j] = a[i-1][j] + a[1][n];
        }
        int sum = 0;
        for(int i=1;i<n;i++) sum += a[i][1];
        a[n][1] = n * a[n-1][1] - sum;
        for(int i=2;i<=n;i++)
            a[n][i] = a[n-1][i] + a[n][1] - a[n-1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
}
