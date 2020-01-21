#include <bits/stdc++.h>
using namespace std;
int dp[31][31][51];
void pre(){
    for(int i=1;i<=30;i++)  for(int j=1;j<=30;j++)  for(int k=0;k<=50;k++) dp[i][j][k] = (int)1e9;
    for(int i=1;i<=30;i++){
        for(int j=1;j<=30;j++){
            for(int k=0;k<=min(50,i*j);k++){
                if (k == 0 || k == i*j) dp[i][j][k] = 0;
                for(int line = 1; line <= i-1; line++){
                    for(int k1 = 0;k1 <= k;k1++){
                        int k2 = k - k1;
                        dp[i][j][k] = min(dp[i][j][k], dp[line][j][k1] + dp[i-line][j][k2] + j*j);
                    }
                }
                for(int line = 1; line <= j-1; line++){
                    for(int k1 = 0;k1 <= k;k1++){
                        int k2 = k - k1;
                        dp[i][j][k] = min(dp[i][j][k], dp[i][line][k1] + dp[i][j-line][k2] + i*i);
                    }
                }
            }
        }
    }
}
int test,n,m,p;
int main(){
    pre();
    scanf("%d",&test);
    while(test--){
        scanf("%d %d %d",&n,&m,&p);
        printf("%d\n",dp[n][m][p]);
    }
}
