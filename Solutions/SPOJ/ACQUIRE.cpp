#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;
typedef pair<int,int> point;
bool cmp(point a,point b){
   if (a.y != b.y) return a.y > b.y;
   return a.x > b.x;
}
int n, nn;
point a[50005], b[50005];
void init(){
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      scanf("%d %d",&a[i].x,&a[i].y);
   sort(a+1,a+n+1,cmp);
   b[0].x = 0; b[0].y = (int) 1e9;
   for(int i=1;i<=n;i++)
      if (a[i].x > b[nn].x && a[i].y < b[nn].y)
         b[++nn] = a[i];
   n = nn;
   for(int i=0;i<=nn;i++) a[i] = b[i];
}
vector <ll> M;
vector <ll> B;
int ctrl;
bool check(int id){
   return (B[id] - B[id-2]) * (M[id-2] - M[id-1]) <= (B[id-1] - B[id-2]) * (M[id-2] - M[id]);
}
void add_line(ll slope,ll val){
   M.push_back(slope);
   B.push_back(val);
   while(M.size() >= 3)
      if (check(M.size()-1)) M.erase(M.end()-2), B.erase(B.end()-2);
      else break;
}
ll query(ll x){
   ctrl = min(ctrl, (int)M.size()-1);
   while(ctrl < (int)M.size()-1 && M[ctrl] * x + B[ctrl] >= M[ctrl+1] * x + B[ctrl+1]) ++ctrl;
   return M[ctrl] * x + B[ctrl];
}
int main(){
   init();
   //for(int i=1;i<=n;i++) cout << a[i].x << ' ' << a[i].y << endl;
   add_line(a[1].y, 0);
   ll ans = 0;
   for(int i=1;i<=n;i++){
      ans = query(a[i].x);
      add_line(a[i+1].y, ans);
      //cout << ans << endl;
   }
   printf("%lld",ans);
}
