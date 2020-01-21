#include <bits/stdc++.h>
using namespace std;
int n,m,day[100005],last[100005],a[100005],mark[100005];
bool pass[100005];
bool solve(int val){
    int cnt = 0;
    memset(mark,0,sizeof(mark));
    memset(last,0,sizeof(last));
    memset(pass,0,sizeof(pass));
    for(int i=1;i<=val;i++){
        if (day[i])
            mark[last[day[i]]] = 0,
            mark[i] = day[i],
            last[day[i]] = i;
    }
    for(int i=1;i<=val;i++){
        if (!mark[i])
            cnt++;
        else{
            if (a[mark[i]] <= cnt)
                cnt -= a[mark[i]], pass[mark[i]] = 1;
            else return 0;
        }
    }
    for(int i=1;i<=n;i++)
        if (!pass[i]) return 0;
    return 1;
}
int main(){
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf("%d",&day[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l = 1, r = m;
    while (l != r){
        int mid = (l+r)/2;
        if (solve(mid)) r = mid;
        else l = mid + 1;
    }
    if (solve(l)) printf("%d",l);
    else printf("-1");
}
