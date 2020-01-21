#include <bits/stdc++.h>
using namespace std;
int n,next[100005],res[100005];
bool visited[100005];
stack <int> st,st2;
void dfs(int u){
    st.push(u);
    visited[u] = 1;
    if (next[u] == u) res[u] = 1, st.pop();
    else if (!visited[next[u]]){
        dfs(next[u]);
        if (!res[u]) res[u] = res[next[u]] + 1, st.pop();
    }
    else{
        if (!res[next[u]]){
            int cnt = 0;
            while(st.top() != next[u]) cnt++, st2.push(st.top()), st.pop();
            cnt++, st2.push(st.top()), st.pop();
            while(st2.size()) res[st2.top()] = cnt, st2.pop();
        }
        else res[u] = res[next[u]] + 1, st.pop();
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&next[i]);
    for(int i=1;i<=n;i++)
        if (!res[i]) dfs(i);
    for(int i=1;i<=n;i++) printf("%d\n",res[i]);
}
