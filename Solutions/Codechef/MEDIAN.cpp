#include <bits/stdc++.h>
using namespace std;
int test,n,a[35],sum[35][35];
struct mask{
    int bit[31],time;
};
int cal(mask x){
    int res = 0;
    for(int i=1;i<=n;i++)
        if (x.bit[i]) res += (1<<(i-1));
    return res;
}
map <int,int> dis;
map <int,bool> check;
queue <mask> q;
int main(){
    scanf("%d",&test);
    while(test--){
        mask start;
        int ma = 0;
        check.clear();
        dis.clear();

        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&start.bit[i]),
            ma = max(ma, start.bit[i]);
        for(int i=1;i<=n;i++)
            start.bit[i] = (start.bit[i] == ma);

        q.push(start);
        check[cal(start)] = 1;

        while(q.size()){
            int tmp[35][35]; memset(tmp,0,sizeof(tmp));
            mask u = q.front();
            q.pop();
            if (u.time >= 6) continue;
            for(int i=1;i<=n;i++){
                for(int j=i;j<=n;j++){
                    tmp[i][j] = tmp[i][j-1] + u.bit[j];
                    if (j-i+1 > tmp[i][j] && tmp[i][j] >= (j-i+1+1)/2 && (j-i+1) > (1<<(u.time))){
                        mask v = u;
                        for(int k=i;k<=j;k++)
                            v.bit[k] = 1;
                        if (!check[cal(v)])
                            check[cal(v)] = 1,
                            dis[cal(v)] = v.time = u.time + 1,
                            q.push(v);
                    }
                }
            }
        }
        printf("%d\n",dis[(1<<n)-1]);
    }
}
