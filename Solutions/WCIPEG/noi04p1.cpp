#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef
   pair<int,int> ii;
typedef
   tree<
   ii,
   null_type,
   greater<ii>,
   rb_tree_tag,
   tree_order_statistics_node_update>  order_set;

order_set s;
int n, mi, more, total;
int main(){
   iostream::sync_with_stdio(0);
   cin >> n >> mi;
   while(n--){
      char c; int x;
      cin >> c >> x;
      if (c == 'I'){
         total++;
         x += more;
         s.insert(ii(x,total));
         if (x < mi) total--;
      }
      else if (c == 'A'){
         mi -= x;
         more -= x;
      }
      else if (c == 'S'){
         mi += x;
         more += x;
      }
      else{
         if (x > s.size()) cout << -1 << '\n';
         else cout << (*s.find_by_order(x-1)).first - more << '\n';
      }
      while(s.size() && (*(--s.end())).first < mi) s.erase(--s.end());
   }
   cout << total - s.size();
}
