#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iiI;
int test,n,m,a[505];
bool used[505];
set <iiI> ax;
int main(){
    scanf("%d",&test);
    while(test--){
        ax = set<iiI>();
        memset(used,0,sizeof(used));

        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());

        int ans = 0, cnt;

        while(1){
            cnt = 0;
            ax.clear();
            ax.insert(iiI(ii(1,m),m));
            for(int i=1;i<=n;i++)
                if (!used[i]) cnt++;

            if (!cnt) break;

            ans ++;
            for(int i=1;i<=n;i++){
                if (used[i]) continue;
                set <iiI> :: iterator it,it2;
                for(it = ax.begin(); it != ax.end(); it ++){
                    iiI u = *it;
                    int beg = u.fi.fi;
                    int fin = u.fi.se;
                    int h = u.se;
                    if (fin - beg + 1 >= (1<<a[i]) && h >= (1<<a[i])){
                        used[i] = 1;
                        int beg1 = beg;
                        int fin1 = fin - (1<<a[i]);
                        int h1 = h;
                        int beg2 = fin - (1<<a[i]) + 1;
                        int fin2 = fin;
                        int h2 = h - (1<<a[i]);
                        ax.erase(it);
                        if (beg1 <= fin1)
                            ax.insert(iiI(ii(beg1,fin1),h1));
                        ax.insert(iiI(ii(beg2,fin2),h2));
                        break;
                    }
                }
                bool ahihi = 0;
                for(it = ax.begin(); it != ax.end(); it++){
                    iiI x1 = *it;
                    it++;
                    if (it == ax.end()) break;
                    iiI x2 = *it;
                    it--;
                    if (x1.se == x2.se){
                        ax.erase(x1);
                        ax.erase(x2);
                        ax.insert(iiI(ii(x1.fi.fi,x2.fi.se),x1.se));
                        it = ax.lower_bound(iiI(ii(x1.fi.fi,x2.fi.se),x1.se));
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
