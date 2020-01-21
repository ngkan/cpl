#include <bits/stdc++.h>
using namespace std;
double f[260][10];
int n,ma;
int p[300][300];
bool visit[300][300];
const double eps = 1e-15;
bool cmp(int x,int y){
   if(abs(f[x][ma] - f[y][ma]) < eps) return x < y;
   return f[x][ma] > f[y][ma];
}
int main(){
   cout << fixed << setprecision(5);
   scanf("%d",&n);   ma = n;  n = (1<<n);
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
         scanf("%d",&p[i][j]);
   for(int i=1;i<=n;i++) f[i][0] = 1.0;
   for(int lv=1;lv<=ma;lv++){
      for(int i=1;i<=n;i++){
         int L = (i-1) / (1<<lv) * (1<<lv);
         for(int j=L+1;j<=L+(1<<lv);j++)
            if (!visit[i][j])
               visit[i][j] = 1,
               f[i][lv] += 1.0 * f[i][lv-1] * f[j][lv-1] * p[i][j] / 100;
      }
   }
   vector <int> ans;
   for(int i=1;i<=n;i++) ans.push_back(i);
   sort(ans.begin(),ans.end(),cmp);
   for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
}
