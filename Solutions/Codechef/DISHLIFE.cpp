#include <bits/stdc++.h>
using namespace std;
int t,n,k;
vector <int> mjk[100005];
int cnt[100005];
int main(){
   scanf("%d",&t);
   while(t--){
      scanf("%d %d",&n,&k);
      memset(cnt,0,sizeof(cnt));
      for(int i=1;i<=n;i++){
         int x,y;
         mjk[i].clear();
         scanf("%d",&x);
         while(x--){
            scanf("%d",&y);
            mjk[i].push_back(y);
            cnt[y]++;
         }
      }
      bool uh=1;
      for(int i=1;i<=k;i++)
         if (!cnt[i]) uh = 0;
      if (!uh) {printf("sad\n");continue;}
      uh = 0;
      for(int i=1;i<=n;i++){
         bool z=0;
         for(int j=0;j<mjk[i].size();j++)
            if (cnt[mjk[i][j]] == 1) z = 1;
         if (!z) uh = 1;
      }
      if (uh) printf("some\n");
      else printf("all\n");
   }
}
