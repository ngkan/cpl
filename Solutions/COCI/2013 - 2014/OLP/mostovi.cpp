#include <bits/stdc++.h>
using namespace std;
const int N = (int) 2e5+5;
const int HIGH = (int) 1e9;
const int LOW = (int) -1e9;
struct query{
   char type; int g1, g2;
};
int dsup[2*N];
int dsu_p(int x){
   return dsup[x] == x ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
   if (dsu_p(x) == dsu_p(y)) return;
   dsup[dsu_p(y)] = dsu_p(x);
}
vector <int> nen,ans;
query q[N];
int n,m,total,begin_line2;
bool ban[2*N];
int seg[8*N][3];
void upd(int id,int l,int r,int pos,int val1,int val2){
   if (r < pos || pos < l) return;
   if (l == r){
      seg[id][1] = val1;
      seg[id][2] = val2;
      return;
   }
   upd(2*id,l,(l+r)/2,pos,val1,val2);
   upd(2*id+1,(l+r)/2+1,r,pos,val1,val2);
   seg[id][1] = max(seg[2*id][1], seg[2*id+1][1]);
   seg[id][2] = min(seg[2*id][2], seg[2*id+1][2]);
}
int get(int line,int id,int l,int r,int u,int v){
   if (line == 1){
      if (r < u || v < l) return LOW;
      if (u <= l && r <= v) return seg[id][line];
      return max(get(line,2*id,l,(l+r)/2,u,v), get(line,2*id+1,(l+r)/2+1,r,u,v));
   }
   else{
      if (r < u || v < l) return HIGH;
      if (u <= l && r <= v) return seg[id][line];
      return min(get(line,2*id,l,(l+r)/2,u,v), get(line,2*id+1,(l+r)/2+1,r,u,v));
   }
}
int find(int line,int id,int l,int r,int u,int v,int val){
   if (line == 1){
      if (r < u || v < l) return LOW;
      else if (l == r){
         if (seg[id][line] < val) return LOW;
         return l;
      }
      else if (u <= l && r <= v){
         if (seg[id][line] < val) return LOW;
         if (seg[2*id][line] >= val)
            return find(line,2*id,l,(l+r)/2,u,v,val);
         else
            return find(line,2*id+1,(l+r)/2+1,r,u,v,val);
      }
      else{
         int x = find(line,2*id,l,(l+r)/2,u,v,val);
         if (x > LOW) return x;
         x = find(line,2*id+1,(l+r)/2+1,r,u,v,val);
         return x;
      }
   }
   else{
      if (r < u || v < l) return HIGH;
      else if (l == r){
         if (seg[id][line] > val) return HIGH;
         return l;
      }
      else if (u <= l && r <= v){
         if (seg[id][line] > val) return HIGH;
         if (seg[2*id+1][line] <= val)
            return find(line,2*id+1,(l+r)/2+1,r,u,v,val);
         else
            return find(line,2*id,l,(l+r)/2,u,v,val);
      }
      else{
         int x = find(line,2*id+1,(l+r)/2+1,r,u,v,val);
         if (x < HIGH) return x;
         x = find(line,2*id,l,(l+r)/2,u,v,val);
         return x;
      }
   }
}
void prep(void){
   cin >> n >> m;
   for(int i=1;i<=m;i++){
      cin >> q[i].type >> q[i].g1 >> q[i].g2;
      nen.push_back(q[i].g1),
      nen.push_back(q[i].g2);
      if (q[i].type != 'Q' && q[i].g1 > q[i].g2) swap(q[i].g1, q[i].g2);
   }
   nen.push_back(n+1);
   sort(nen.begin(),nen.end());
   nen.resize(distance(nen.begin(),unique(nen.begin(),nen.end())));
   for(int i=1;i<=m;i++)
      q[i].g1 = upper_bound(nen.begin(),nen.end(),q[i].g1) - nen.begin(),
      q[i].g2 = upper_bound(nen.begin(),nen.end(),q[i].g2) - nen.begin();
   begin_line2 = upper_bound(nen.begin(),nen.end(),n+1) - nen.begin();
   total = nen.size();
   //---------------------------------------------------------------------/
   for(int i=1;i<400005;i++) dsup[i] = i;
   //---------------------------------------------------------------------/
   for(int i=1;i<=m;i++)
      if (q[i].type == 'B')
            ban[q[i].g1] = 1;

   for(int i=1;i<begin_line2-1;i++)
      if (!ban[i]) dsu_union(i,i+1);
   for(int i=begin_line2;i<total;i++)
      if (!ban[i]) dsu_union(i,i+1);
   //---------------------------------------------------------------------/
   for(int i=1;i<8*N;i++) seg[i][1] = LOW, seg[i][2] = HIGH;
   for(int i=1;i<=m;i++)
      if (q[i].type == 'A'){
         upd(1,1,total,q[i].g1,q[i].g2,q[i].g2);
         upd(1,1,total,q[i].g2,q[i].g1,q[i].g1);
      }
}
void solve(void){
   for(int i=m;i>=1;i--){
      int g1 = q[i].g1, g2 = q[i].g2;
      assert(g1 != g2);
      if (q[i].type == 'A')
         upd(1,1,total,g1,LOW,HIGH),
         upd(1,1,total,g2,LOW,HIGH);
      else if (q[i].type == 'B')
         assert(abs(g1-g2) == 1),
         dsu_union(g1, g2);
      else{
         if (g1 < begin_line2 && begin_line2 <= g2){
            int pos = find(1,1,1,total,g1,begin_line2-1,g2);
//            int pos = LOW;
//            for(int j=g1;j<begin_line2;j++)
//               if (get(1,1,1,total,j,j) >= g2) {pos = j; break;}
            if (pos == LOW || dsu_p(g1) != dsu_p(pos) || dsu_p(get(1,1,1,total,pos,pos)) != dsu_p(g2))
               ans.push_back(0);
            else
               ans.push_back(1);
         }
         else if (g2 < begin_line2 && begin_line2 <= g1){
            swap(g1,g2);
            int pos = find(2,1,1,total,begin_line2,g2,g1);
//            int pos = HIGH;
//            for(int j=g2;j>=begin_line2;j--)
//               if (get(2,1,1,total,j,j) <= g1) {pos = j;break;}
            if (pos == HIGH || dsu_p(g2) != dsu_p(pos) || dsu_p(get(1,1,1,total,pos,pos)) != dsu_p(g1))
               ans.push_back(0);
            else
               ans.push_back(1);
         }
         else if (g1 < begin_line2 && g2 < begin_line2){
            if (g1 < g2)
               ans.push_back(dsu_p(g1) == dsu_p(g2));
            else{
               int pos1 = find(2,1,1,total,1,g2,HIGH-1);
//               int pos1 = HIGH;
//               for(int j=g2;j>=1;j--)
//                  if (get(2,1,1,total,j,j) < HIGH) {pos1 = j; break;}
               int pos2 = find(1,1,1,total,g1,begin_line2-1,LOW+1);
//               int pos2 = LOW;
//               for(int j=g1;j<begin_line2;j++)
//                  if (get(1,1,1,total,j,j) > LOW) {pos2 = j; break;}
               if (pos1 == HIGH || pos2 == LOW)
                  ans.push_back(0);
               else if (dsu_p(pos1) != dsu_p(g2) || dsu_p(pos2) != dsu_p(g1))
                  ans.push_back(0);
               else if (dsu_p(get(1,1,1,total,pos1,pos1)) != dsu_p(get(1,1,1,total,pos2,pos2)))
                  ans.push_back(0);
               else
                  ans.push_back(1);
            }
         }
         else if (begin_line2 <= g1 && begin_line2 <= g2){
            if (g1 > g2)
               ans.push_back(dsu_p(g1) == dsu_p(g2));
            else{
               int pos1 = find(2,1,1,total,begin_line2,g1,HIGH-1);
               int pos2 = find(1,1,1,total,g2,total,LOW+1);
//               int pos1 = HIGH;
//               for(int j=g1;j>=begin_line2;j--)
//                  if (get(2,1,1,total,j,j) < HIGH) {pos1 = j; break;}
//               int pos2 = LOW;
//               for(int j=g2;j<=total;j++)
//                  if (get(1,1,1,total,j,j) > LOW) {pos2 = j; break;}

               if (pos1 == HIGH || pos2 == LOW)
                  ans.push_back(0);
               else if (dsu_p(pos1) != dsu_p(g1) || dsu_p(pos2) != dsu_p(g2))
                  ans.push_back(0);
               else if (dsu_p(get(1,1,1,total,pos1,pos1)) != dsu_p(get(1,1,1,total,pos2,pos2)))
                  ans.push_back(0);
               else
                  ans.push_back(1);
            }
         }
         else assert(1 == 0);
      }
   }
}
int main(){
   iostream::sync_with_stdio(0);
   prep();
   solve();
   for(int i=ans.size()-1;i>=0;i--)
      if (ans[i]) cout << "DA\n";
      else cout << "NE\n";
}
