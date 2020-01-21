#include <bits/stdc++.h>
using namespace std;
int test,n,r,o,y,g,b,v;
string res;
void out(int t,string res = "IMPOSSIBLE"){
   cout << "Case #" << t << ": " << res << endl;
}
int main(){
   //freopen("B-large.in","r",stdin);
   //freopen("Bout.txt","w",stdout);
   cin >> test;
   for(int t=1;t<=test;t++){
      cin >> n >> r >> o >> y >> g >> b >> v;
      string res;
      if (r + g == n){
         if (n%2 == 0 && r == g){
            for(int i=0;i<n;i++)
               if (i%2) res.push_back('R');
               else res.push_back('G');
            out(t,res);
            continue;
         }
         else{
            out(t); continue;
         }
      }
      if (y + v == n){
         if (n%2 == 0 && y == v){
            for(int i=0;i<n;i++)
               if (i%2) res.push_back('Y');
               else res.push_back('V');
            out(t,res);
            continue;
         }
         else{
            out(t); continue;
         }
      }
      if (b + o == n){
         if (n%2 == 0 && b == o){
            for(int i=0;i<n;i++)
               if (i%2) res.push_back('O');
               else res.push_back('B');
            out(t,res);
            continue;
         }
         else{
            out(t); continue;
         }
      }
      string replaceR, replaceB, replaceY;
      if (g){
         if (r <= g) {out(t);continue;}
         replaceR.push_back('R');
         r--; n--;
         while(g){
            n-=2; r--;  g--;
            replaceR.push_back('G');
            replaceR.push_back('R');
         }
         n++; r++;
      }
      if (v){
         if (y<=v) {out(t);continue;}
         n--;
         y--;
         replaceY.push_back('Y');
         while(v){
            n-=2; v--; y--;
            replaceY.push_back('V');
            replaceY.push_back('Y');
         }
         y++; n++;
      }
      if (o){
         if (b <= o) {out(t);continue;}
         n--; b--;
         replaceB.push_back('B');
         while(o){
            n-=2; b--; o--;
            replaceB.push_back('O');
            replaceB.push_back('B');
         }
         n++; b++;
      }
      if (r > n/2 || b > n/2 || y > n/2){out(t);continue;}
      string tmp(n,'1');
      int ctrl = 0;
      if (r >= b && r >= y){
         while(r)
            r--,
            tmp[ctrl] = 'R',
            ctrl+=2;
      }
      else if (b >= r && b >= y){
         while(b)
            b--,
            tmp[ctrl] = 'B',
            ctrl+=2;
      }
      else{
         while(y)
            y--,
            tmp[ctrl] = 'Y',
            ctrl+=2;
      }
      while(r){
         r--;
         if (ctrl >= n) ctrl = 1;
         tmp[ctrl] = 'R'; ctrl+=2;
      }
      while(b){
         b--;
         if (ctrl >= n) ctrl = 1;
         tmp[ctrl] = 'B'; ctrl +=2;
      }
      while(y){
         y--;
         if (ctrl >= n) ctrl = 1;
         tmp[ctrl] = 'Y'; ctrl += 2;
      }
      for(int i=0;i<n;i++) assert(tmp[i] != '1');
      //cout << n << ' ' << r << ' ' << b << ' ' << y << endl;
      for(int i=0;i<tmp.size();i++){
         if (tmp[i] == 'R'){
            if (replaceR.size()) {
               for(int j=0;j<replaceR.size();j++) res.push_back(replaceR[j]);
               replaceR.clear();
            }
            else
               res.push_back('R');
         }
         else if (tmp[i] == 'Y'){
            if (replaceY.size()) {
               for(int j=0;j<replaceY.size();j++) res.push_back(replaceY[j]);
               replaceY.clear();
            }
            else
               res.push_back('Y');
         }
         else if (tmp[i] == 'B'){
            if (replaceB.size()) {
               for(int j=0;j<replaceB.size();j++) res.push_back(replaceB[j]);
               replaceB.clear();
            }
            else
               res.push_back('B');
         }
         else res.push_back('1');
      }
      out(t,res);
   }
}
