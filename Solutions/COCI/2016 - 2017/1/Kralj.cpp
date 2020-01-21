#include <bits/stdc++.h>
using namespace std;
int n,startpos,ans;
int p[500005],v[500005],a[500005];
vector <int> lst[500005];
set <int> st;
int main(){
    freopen("kralj.in.8","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]),a[i]--;
    for(int i=0;i<n;i++)
        scanf("%d",&p[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    for(int i=0;i<n;i++)
        lst[a[i]].push_back(v[i]);
    int tmp = 0;
    for(int i=0;i<2*n;i++){
        if (tmp<0) startpos = i%n, tmp = 0;
        tmp += lst[i%n].size();
        tmp --;
    }
    for(int i=startpos;i<startpos+n;i++){
        for(int j=0;j<lst[i%n].size();j++)
            st.insert(lst[i%n][j]);
        set<int> :: iterator it = st.lower_bound(p[i%n]);
        if (it == st.end())
            st.erase(st.begin());
        else
            ans++,
            st.erase(it);
    }
    printf("%d",ans);
}
