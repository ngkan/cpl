#include <bits/stdc++.h>
using namespace std;
int n,cnt,ans=(1<<30),a[100005],b[100005];
map <int,int> p;
map <int,bool> visited;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]), b[i] = a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        cnt += (a[i] == b[i]);
        if (a[i] != b[i]) p[a[i]] = b[i];
    }
    cnt = n - cnt;
    for(int i=1;i<=n;i++)
        if (p[a[i]] && !visited[a[i]]){
            int x = p[a[i]];
            visited[a[i]] = 1;
            while(x != a[i]){
                visited[x] = 1;
                x = p[x];
            }
            cnt--;
        }
    ans= min(ans,cnt); cnt = 0;
    sort(b+1,b+n+1,greater<int>());
    p.clear();visited.clear();

    for(int i=1;i<=n;i++){
        cnt += (a[i] == b[i]);
        if (a[i] != b[i]) p[a[i]] = b[i];
    }
    cnt = n - cnt;
    for(int i=1;i<=n;i++)
        if (p[a[i]] && !visited[a[i]]){
            int x = p[a[i]];
            visited[a[i]] = 1;
            while(x != a[i]){
                visited[x] = 1;
                x = p[x];
            }
            cnt--;
        }
    ans =min(ans,cnt);cnt = 0;
    printf("%d",ans);
}
