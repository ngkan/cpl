#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = (int) 2e6+5;
ll n,_cnt,val[N],depth[N], maxdepth, lv[N];
ll pow2[100];
string ans;
vector <ll> G[N];
void prep1(int u){
   for(int i=0;i<G[u].size();i++){
      prep1(G[u][i]);
      val[u] += val[G[u][i]];
   }
}
void prepdepth(int u){
   maxdepth = max(maxdepth, depth[u]);
   for(int i=0;i<G[u].size();i++){
      depth[G[u][i]] = depth[u] + 1;
      prepdepth(G[u][i]);
   }
}
void preplv(){
   pow2[0] = 1ll;
   for(int i=1;i<64;i++) pow2[i] = pow2[i-1] * 2ll;
   for(int i=1;i<=n;i++)
      lv[i] = maxdepth - depth[i];
}
int main(){
   scanf("%lld",&n);
   _cnt = n;
   for(int i=1;i<=n;i++){
      ll x;
      scanf("%lld",&x);
      if (x <= 0)
         val[++_cnt] = -x,
         G[i].push_back(_cnt);
      else
         G[i].push_back(x);
      scanf("%lld",&x);
      if (x <= 0)
         val[++_cnt] = -x,
         G[i].push_back(_cnt);
      else
         G[i].push_back(x);
   }
   n = _cnt;
   prep1(1);
   prepdepth(1);
   preplv();
   ll minleaf = 0;

   for(int i=1;i<=n;i++){
      if (lv[i] > 60)
         minleaf = max(minleaf, 1ll * (val[i] > 0));
      else
         minleaf = max(minleaf, 1ll * (val[i] + pow2[lv[i]] - 1l) / pow2[lv[i]]);
   }

   ans.assign(N, '0');
   for(int i=0;i<64;i++)
      if (((minleaf>>i) & 1) > 0) ans[lv[1] + i] = '1';

   while(ans.size() && ans[ans.size()-1] == '0') ans.erase(ans.end()-1);
   if (!ans.size()) ans.push_back('0');
   for(int i=ans.size()-1;i>=0;i--)
      printf("%c",ans[i]);
}
/*
32
2 3
-251300770 -542044245
4 -209191854
5 -480173865
6 -417014054
7 -441759101
8 9
-85489922 10
11 -116960588
12 13
-86774949 -9027494
14 -584434702
15 16
17 -578565888
18 19
-55248388 20
-35033633 21
-476792734 22
23 -385909248
24 25
-389912382 26
-329203683 -806192758
27 -243143812
28 29
30 31
-150878019 32
-300750793 -58642759
-506522380 -673673071
-93676392 -62297288
-228428891 -570469126
-835670307 -436445897
-132751783 -74095907
110001110011110101000100100100000 00000 00000
110001110011110101000100100011000 00000 00000
2
2 -7
-3 -3
*/
