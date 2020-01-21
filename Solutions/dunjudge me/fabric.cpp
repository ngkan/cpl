#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll way[2005][2005], tcd[2005][2005], up[2005][2005], ans;
int n,m,k;
int a[2005][2005];
void init(){
   scanf("%d %d %d",&n,&m,&k);
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         scanf("%d",&a[i][j]);
}
void prep(){
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         way[i][j] = way[i-1][j] + way[i][j-1] - way[i-1][j-1] + (i*j >= k);
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         tcd[i][j] = tcd[i][j-1] + way[i][j];
   for(int i=1;i<=n;i++)
      for(int j=1;j<=m;j++)
         if (a[i][j]) up[i][j] = 0;
         else up[i][j] = up[i-1][j] + 1;
}
void solve(){
   stack <int> st;
   for(int i=1;i<=n;i++){
      st.push(0);
      //cout << "row " << i << endl;
      for(int j=1;j<=m;j++){
         int last = -1;
         while(st.size() && up[i][st.top()] > up[i][j]){
            int x = last = st.top();
            ans += tcd[up[i][st.top()]][j - st.top()];
            st.pop();
            ans -= tcd[max(up[i][st.top()], up[i][j])][j - x];
         }
         while(st.size() && up[i][st.top()] == up[i][j]) last = st.top(), st.pop();
         if (last != -1) st.push(last), up[i][last] = up[i][j];
         else st.push(j);
         //cout << ans << endl;
      }
      while(st.size()){
         int x = st.top();
         ans += tcd[up[i][st.top()]][m+1 - st.top()];
         //cout << st.top() << ' ' << up[i][st.top()] << ' ' << tcd[up[i][st.top()]][m+1-st.top()] << endl;
         st.pop();
         if (st.size()) ans -= tcd[up[i][st.top()]][m+1 - x];
      }
      //cout << ans << endl;
   }
   printf("%lld",ans);
}
int main(){
   init();
   prep();
   solve();
}
/*
2 2 1
0 1
0 0
*/
