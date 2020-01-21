#include <stdio.h>
int n,m,l[100005],r[100005],q[100005],ax[100005][30],sum[100005][30], l0g2[100005];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=2;i<=100000;i++) l0g2[i] = l0g2[i/2] + 1;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&l[i],&r[i],&q[i]);
        for(int k=0;k<30;k++)
            if (((1<<k) & q[i]))
                ax[l[i]][k]++,
                ax[r[i]+1][k]--;
    }
    for(int k=0;k<30;k++){
        int cnt = 0;
        for(int i=1;i<=n;i++){
            cnt += ax[i][k];
            if (cnt) sum[i][0] += (1<<k);
        }
    }
    for(int k=1;k<17;k++)
        for(int i=1;i<=n;i++)
            if (i + (1<<k) - 1<= n)
            sum[i][k] = (sum[i][k-1] & sum[i+(1<<(k-1))][k-1]);

    for(int i=1;i<=m;i++){
        int len = r[i] - l[i] + 1;
        if ((sum[l[i]][l0g2[len]] & sum[r[i] - (1<<l0g2[len]) + 1][l0g2[len]]) != q[i]) return printf("NO"),0;
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%d ",sum[i][0]);
}
