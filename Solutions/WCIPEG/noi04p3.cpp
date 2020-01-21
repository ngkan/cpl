#include <bits/stdc++.h>
#define fi first
#define se second
#define x1 asdas
#define y1 pojk
#define x2 asdoij
#define y2 oiuy
using namespace std;
typedef pair<int,int> ii;
int n,m,k;
int cdirn[15],cdirm[105], wn[15], wm[105];
int ans=(int)1e9, res, adirn[15], adirm[105];
int x1[105],y1[105],x2[105],y2[105];
bool fixedm[105];
int dirm[105];
int cnt;
int l[105], r[105], type[105];
int dp[105][2][105];
bool cant[105][2][105], have[105][2];
ii trace[105][2][105];
void solve(){
   int cost = 0;
   memset(fixedm,0,sizeof(fixedm));
   memset(cant,0,sizeof(cant));
   memset(have,0,sizeof(have));
   cnt = 0;
   for(int i=1;i<=m;i++)   dirm[i] = cdirm[i];

   for(int i=1;i<=k;i++){
      if (x1[i] == x2[i]){
         if (y1[i] < y2[i] && !cdirn[x1[i]]) return;
         if (y1[i] > y2[i] && cdirn[x1[i]]) return;
         continue;
      }
      if (y1[i] == y2[i]){
         if (x1[i] < x2[i]){
            if (!fixedm[y1[i]]){
               fixedm[y1[i]] = 1;
               if (!dirm[y1[i]]) cost += wm[y1[i]];
               dirm[y1[i]] = 1;
            }
            else{
               if (!dirm[y1[i]]) return;
            }
         }
         else{
            if (!fixedm[y1[i]]){
               fixedm[y1[i]] = 1;
               if (dirm[y1[i]]) cost += wm[y1[i]];
               dirm[y1[i]] = 0;
            }
            else{
               if (dirm[y1[i]]) return;
            }
         }
         continue;
      }
      if (y1[i] < y2[i]){
         if (!cdirn[x1[i]] && !cdirn[x2[i]]){
            if (!fixedm[y1[i]]){
               fixedm[y1[i]] = 1;
               if (dirm[y1[i]] != (x1[i] < x2[i])) cost += wm[y1[i]];
               dirm[y1[i]]= (x1[i] < x2[i]);
            }
            else{
               if (dirm[y1[i]] != (x1[i] < x2[i])) return;
            }
            if (!fixedm[y2[i]]){
               fixedm[y2[i]] = 1;
               if (dirm[y2[i]] != (x1[i] < x2[i])) cost += wm[y2[i]];
               dirm[y2[i]]= (x1[i] < x2[i]);
            }
            else{
               if (dirm[y2[i]] != (x1[i] < x2[i])) return;
            }
            bool z = 0;
            for(int row=min(x1[i],x2[i]); row <= max(x1[i], x2[i]); row++)
               if (cdirn[row]) z = 1;
            if (!z) return;
         }
         if (!cdirn[x1[i]] && cdirn[x2[i]]){
            if (!fixedm[y1[i]]){
               fixedm[y1[i]] = 1;
               if (dirm[y1[i]] != (x1[i] < x2[i])) cost += wm[y1[i]];
               dirm[y1[i]] = (x1[i] < x2[i]);
            }
            else{
               if (dirm[y1[i]] != (x1[i] < x2[i])) return;
            }
         }
         if (cdirn[x1[i]] && !cdirn[x2[i]]){
            if (!fixedm[y2[i]]){
               fixedm[y2[i]] = 1;
               if (dirm[y2[i]] != (x1[i] < x2[i])) cost += wm[y2[i]];
               dirm[y2[i]] = (x1[i] < x2[i]);
            }
            else{
               if (dirm[y2[i]] != (x1[i] < x2[i])) return;
            }
         }
         if (cdirn[x1[i]] && cdirn[x2[i]]){
            cnt ++;
            l[cnt] = y1[i];
            r[cnt] = y2[i];
            type[cnt] = (x1[i] < x2[i]);
         }
         continue;
      }
      if (y1[i] > y2[i]){
         if (cdirn[x1[i]] && cdirn[x2[i]]){
            if (!fixedm[y1[i]]){
               fixedm[y1[i]] = 1;
               if (dirm[y1[i]] != (x1[i] < x2[i])) cost += wm[y1[i]];
               dirm[y1[i]]= (x1[i] < x2[i]);
            }
            else{
               if (dirm[y1[i]] != (x1[i] < x2[i])) return;
            }
            if (!fixedm[y2[i]]){
               fixedm[y2[i]] = 1;
               if (dirm[y2[i]] != (x1[i] < x2[i])) cost += wm[y2[i]];
               dirm[y2[i]] = (x1[i] < x2[i]);
            }
            else{
               if (dirm[y2[i]] != (x1[i] < x2[i])) return;
            }
            bool z = 0;
            for(int row=min(x1[i],x2[i]); row <= max(x1[i], x2[i]); row++)
               if (!cdirn[row]) z = 1;
            if (!z) return;
         }
         if (cdirn[x1[i]] && !cdirn[x2[i]]){
            if (!fixedm[y1[i]]){
               fixedm[y1[i]] = 1;
               if (dirm[y1[i]] != (x1[i] < x2[i])) cost += wm[y1[i]];
               dirm[y1[i]]= (x1[i] < x2[i]);
            }
            else{
               if (dirm[y1[i]] != (x1[i] < x2[i])) return;
            }
         }
         if (!cdirn[x1[i]] && cdirn[x2[i]]){
            if (!fixedm[y2[i]]){
               fixedm[y2[i]] = 1;
               if (dirm[y2[i]] != (x1[i] < x2[i])) cost += wm[y2[i]];
               dirm[y2[i]]= (x1[i] < x2[i]);
            }
            else{
               if (dirm[y2[i]] != (x1[i] < x2[i])) return;
            }
         }
         if (!cdirn[x1[i]] && !cdirn[x2[i]]){
            cnt++;
            l[cnt] = y2[i];
            r[cnt] = y1[i];
            type[cnt] = (x1[i] < x2[i]);
         }
         continue;
      }
   }

   for(int i=0;i<=m;i++)
      for(int j=0;j<=m;j++)
         dp[i][0][j] = dp[i][1][j] = (int) 1e9,
         trace[i][0][j] = trace[i][1][j] = ii(-1,-1);
   dp[0][0][0] = dp[0][1][0] = 0;

   for(int i=1;i<=cnt;i++){
      for(int j=(r[i]-l[i]+1);j<=r[i];j++)
         cant[r[i]][1^type[i]][j] = 1;
      have[l[i]][type[i]] = 1;
   }
   for(int i=0;i<=m;i++){
      for(int t=0;t<=1;t++){
         for(int j=0;j<=i;j++){
            if (i && j) cant[i][t][j] |= cant[i-1][t][j-1];
            if (cant[i][t][j]){
               dp[i][t][j] = (int) 1e9;
               continue;
            }
            if (fixedm[i] && t != dirm[i]){
               dp[i][t][j] = (int) 1e9;
               continue;
            }
            if (dp[i+1][t][j+1] > dp[i][t][j] + wm[i+1] * (dirm[i+1] != t)){
               dp[i+1][t][j+1] = min(dp[i+1][t][j+1], dp[i][t][j] + wm[i+1] * (dirm[i+1] != t));
               trace[i+1][t][j+1] = ii(t,j);
            }
            if (dp[i+1][1^t][have[i+1][t]] > dp[i][t][j] + wm[i+1] * (dirm[i+1] == t)){
               dp[i+1][1^t][have[i+1][t]] = min(dp[i+1][1^t][have[i+1][t]], dp[i][t][j] + wm[i+1] * (dirm[i+1] == t));
               trace[i+1][1^t][have[i+1][t]] = ii(t,j);
            }
         }
      }
   }
   int ezc = (int) 1e9;
   int lastm;
   ii mjk;
   for(int i=0;i<=m;i++){
      if (ezc > dp[m][0][i]){
         ezc = dp[m][0][i];
         lastm = 0;
         mjk = trace[m][0][i];
      }
      if (ezc > dp[m][1][i]){
         ezc = dp[m][1][i];
         lastm = 1;
         mjk = trace[m][1][i];
      }
   }
   if (res + cost + ezc >= ans) return;
   ans = res + cost + ezc;
   for(int i=1;i<=n;i++)   adirn[i] = cdirn[i];
   for(int i=m;i>=1;i--){
      adirm[i] = lastm;
      lastm = mjk.fi;
      mjk = trace[i][mjk.fi][mjk.se];
   }
}
void _back(int pos){
   if (pos == n+1){
      solve();
      return;
   }
   res += wn[pos];
   cdirn[pos] ^= 1;
   _back(pos+1);
   res -= wn[pos];
   cdirn[pos] ^= 1;
   _back(pos+1);
}
string s;
void init(){
   cin >> n >> m;
   cin >> s;
   for(int i=1;i<=n;i++)
      cdirn[i] = (s[i-1] == 'E');
   cin >> s;
   for(int i=1;i<=m;i++)
      cdirm[i] = (s[i-1] == 'S');
   for(int i=1;i<=n;i++)
      cin >> wn[i];
   for(int i=1;i<=m;i++)
      cin >> wm[i];
   cin >> k;
   for(int i=1;i<=k;i++)
      cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
}
int main(){
   init();
   _back(1);
   if (ans == (int) 1e9) cout << "impossible";
   else{
      cout << "possible\n" << ans << '\n';
      for(int i=1;i<=n;i++)
         if (adirn[i]) cout << 'E'; else cout <<'W'; cout << '\n';
      for(int i=1;i<=m;i++)
         if (adirm[i]) cout << 'S'; else cout <<'N';
   }
}
