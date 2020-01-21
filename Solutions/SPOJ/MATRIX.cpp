#include <bits/stdc++.h>
using namespace std;
int test,n,m,a[205][205],par_sum[205][205];
int ans, cnt;
int main(){
    scanf("%d",&test);
    while(test--){
        ans = -(1<<30), cnt = 0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]),
                a[i][j] = (a[i][j] == 1) ? 1 : -1;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                par_sum[i][j] = par_sum[i][j-1] + a[i][j];

        for(int col1=1;col1<=m;col1++){
            for(int col2=col1;col2<=m;col2++){
                if (n >= 1){
                    int sum = par_sum[1][col2] - par_sum[1][col1-1];
                    if (sum > ans)
                        ans = sum, cnt = 1;
                    else if (sum == ans)
                        cnt++;
                }
                if (n >= 2){
                    int sum = par_sum[2][col2] - par_sum[2][col1-1];
                    if (sum > ans)
                        ans = sum, cnt = 1;
                    else if (sum == ans)
                        cnt++;
                    sum += par_sum[1][col2] - par_sum[1][col1-1];
                    if (sum > ans)
                        ans = sum, cnt = 1;
                    else if (sum == ans)
                        cnt++;
                }

                int last = par_sum[1][col2] - par_sum[1][col1 - 1], cntlast = 1;

                for(int row=3;row<=n;row++){
                    int presum = par_sum[row-1][col2] - par_sum[row-1][col1 - 1];
                    int sum = par_sum[row][col2] - par_sum[row][col1 - 1];

                    if (col1 == col2)
                        last += a[row-1][col1];
                    else
                        last += a[row-1][col1] + a[row-1][col2];

                    if (presum > last)
                        last = presum, cntlast = 1;
                    else if (presum == last)
                        cntlast++;

                    if (sum + last > ans)
                        ans = sum + last, cnt = cntlast;
                    else if (sum + last == ans)
                        cnt += cntlast;

                    if (sum > ans)
                        ans = sum, cnt = 1;
                    else if (sum == ans)
                        cnt ++;
                }
            }
        }
        printf("%d %d\n",ans,cnt);
    }
}
