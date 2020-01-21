#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[100002];
vector <ll> dp[202];
int last[100002][202];
vector <ll> M,B;
vector <int> ID;
bool check(int id){
   return (B[id] - B[id-2]) * (M[id-2] - M[id-1]) <= (B[id-1] - B[id-2]) * (M[id-2] - M[id]);
}
void add_line(ll slope,ll val,ll id){
   M.push_back(slope);
   B.push_back(val);
   ID.push_back(id);
   while(M.size() >= 2 && M[M.size()-2] == M[M.size()-1]){
      if (B[M.size()-2] <= B[M.size()-1]){
         M.erase(M.end()-2);
         B.erase(B.end()-2);
         ID.erase(ID.end()-2);
      }
      else{
         M.erase(M.end()-1);
         B.erase(B.end()-1);
         ID.erase(ID.end()-1);
      }
   }
   while(M.size() >= 3 && check(M.size()-1)) ID.erase(ID.end()-2), M.erase(M.end()-2), B.erase(B.end()-2);
}
int ctrl;
ll get(ll x){
   ctrl = min(ctrl, (int)M.size()-1);
   while(ctrl < M.size()-1 && M[ctrl] * x + B[ctrl] <= M[ctrl+1] * x + B[ctrl+1])
      ++ctrl;
   return ctrl;
}
int main(){
   scanf("%d %d",&n,&k);
   k++;
   for(int i=1;i<=n;i++)
      scanf("%d",&a[i]),
      a[i] += a[i-1];
   dp[0].assign(n+2,-(ll) 1e18);
   dp[0][0] = 0;
   for(int t=1;t<=k;t++){
      M.clear(); B.clear(); ID.clear();
      add_line(0,0,0);
      if (t >= 2) dp[t-2].clear();
      dp[t].assign(n+2,0);
      for(int i=1;i<=n;i++){
         int id = get(a[i]);
         dp[t][i] = M[id] * a[i] + B[id];
         last[i][t] = ID[id];
         add_line(a[i], dp[t-1][i] - 1ll * a[i] * a[i], i);
      }
   }
   vector <int> res;
   int mjk = n;
   for(int t=k;t>1;t--){
      res.push_back(last[mjk][t]);
      mjk = last[mjk][t];
   }
   reverse(res.begin(),res.end());
   printf("%lld\n",dp[k][n]);
   for(int i=0;i<res.size();i++) printf("%d ",res[i]);
   //cout << endl; for(int i=0;i<res.size();i++) cout << dp[i+1][res[i]] << ' ';
}
/*
7 3
4 1 3 4 0 2 3
*/
