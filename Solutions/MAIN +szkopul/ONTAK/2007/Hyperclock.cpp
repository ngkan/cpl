#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> ii;
int n,a[1000005],last=1,type=1;
vector <ii> ans;
vector<ii> solve(int pos){
    if (pos == n+1) return vector<ii>();
    vector<ii> past = solve(pos+1);
    if (a[pos] == 1) return past;
    last = pos;
    vector<ii> now;
    if (a[pos]%2){
        if (past.size()%2==0){
            for(int i=a[pos];i>3;i-=2){
                for(int j=0;j<past.size();j++)
                    now.push_back(past[j]);
                now.push_back(ii(pos,1));
                for(int j=past.size()-1;j>=0;j--)
                    now.push_back(ii(past[j].fi,-past[j].se));
                now.push_back(ii(pos,1));
            }
            for(int j=0;j<past.size();j++)
                now.push_back(past[j]);
            now.push_back(ii(pos,1));
            for(int j=past.size()-1;j>=0;j--)
                if (j%2==1)
                    now.push_back(ii(pos,1)),
                    now.push_back(ii(past[j].fi,-past[j].se));
                else
                    now.push_back(ii(pos,-1)),
                    now.push_back(ii(past[j].fi,-past[j].se));
            now.push_back(ii(pos,1));
            type = 1;
        }
        else{
            now.push_back(past[0]);
            for(int i=a[pos];i>3;i-=2){
                for(int j=1;j<past.size();j++)
                    now.push_back(past[j]);
                now.push_back(ii(pos,1));
                for(int j=past.size()-1;j>=1;j--)
                    now.push_back(ii(past[j].fi,-past[j].se));
                now.push_back(ii(pos,1));
            }
            for(int j=1;j<past.size();j++)
                now.push_back(past[j]);
            now.push_back(ii(pos,1));

            for(int j=past.size()-1;j>=1;j--)
                if (j%2==0)
                    now.push_back(ii(pos,1)),
                    now.push_back(ii(past[j].fi,-past[j].se));
                else
                    now.push_back(ii(pos,-1)),
                    now.push_back(ii(past[j].fi,-past[j].se));
            now.push_back(ii(pos,1));
            now.push_back(ii(past[0].fi,-past[0].se));
            for(int i=1;i<a[pos]-1;i++)
                now.push_back(ii(pos,-1));
            type = -1;
        }
    }
    else{
        for(int i=a[pos];i;i-=2){
            for(int j=0;j<past.size();j++)
                now.push_back(past[j]);
            now.push_back(ii(pos,1));
            for(int j=past.size()-1;j>=0;j--)
                now.push_back(ii(past[j].fi,-past[j].se));
            if (i>2) now.push_back(ii(pos,1));
            type = 1;
        }
    }
    return now;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    ans = solve(1);
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].fi,ans[i].se);
    //cout << ans.size() << endl;
    printf("%d %d",last,type);
}
