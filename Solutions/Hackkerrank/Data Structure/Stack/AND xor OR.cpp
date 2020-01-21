#include <bits/stdc++.h>
using namespace std;
int ans = 0;
stack <int> st;
int n,x;
int f(int a,int b){
    return (((a&b) ^ (a|b)) & (a^b));
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if (st.empty()){
            st.push(x);
            continue;
        }
        while(st.size() > 1 && st.top() > x)
            ans = max(ans, f(st.top(),x)),
            st.pop();
        ans = max(ans, f(st.top(),x));
        if (st.top() > x) st.pop();
        st.push(x);
    }
    printf("%d",ans);
}
