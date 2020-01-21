#include <bits/stdc++.h>
using namespace std;
int test,n,p[100005][20],lv[100005];
int lca(int x,int y){
    for(int k=17;k>=0;k--) if(lv[p[x][k]] >= lv[y]) x = p[x][k];
    for(int k=17;k>=0;k--) if(lv[p[y][k]] >= lv[x]) y = p[y][k];
    if (x == y) return x;
    for(int k=17;k>=0;k--)
        if (p[x][k] != p[y][k]) x = p[x][k], y = p[y][k];
    return p[x][0];
}
int main(){
    scanf("%d",&test);
    while(test--){
        memset(p,0,sizeof(p));
        memset(lv,0,sizeof(lv));
        scanf("%d",&n);
        int res,x,y;
        res = 0, x = y = 1;
        for(int i=2;i<=n;i++){
            scanf("%d",&p[i][0]);
            lv[i] = lv[p[i][0]] + 1;
            for(int k=1;k<=17;k++)
                p[i][k] = p[p[i][k-1]][k-1];
            if (lv[x] + lv[i] - 2 * lv[lca(x,i)] > res)
                res++, y = i;
            else if (lv[y] + lv[i] - 2 * lv[lca(y,i)] > res)
                res++, x = i;
            printf("%d\n",res);
        }
    }
}
