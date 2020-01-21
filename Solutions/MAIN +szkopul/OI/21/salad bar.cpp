#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
const int N = (int) 1e6+5;
int n,val[N],cnt,mi[N],ans;
stack <int> st;
string s;
int main(){
    cin >> n >> s;
    for(int i=0;i<s.size();i++){
        if (s[i] == 'p') val[i+1] = ++cnt;
        else val[i+1] = --cnt;
        mi[i+1] = i+1;
    }
    val[N-1] = (1<30);    st.push(N-1);
    for(int i=0;i<=n;i++){
        while(st.top() != N-1 && val[st.top()] <= val[i]){
            int x2 = st.top(); st.pop();
            if (val[mi[st.top()]] > val[mi[x2]])    mi[st.top()] = mi[x2];
        }
        if (val[mi[st.top()]] > val[i])    mi[st.top()] = mi[i];
        if (i)
            ans = max(ans, i - mi[st.top()]);
        st.push(i);
    }
    cout << ans;
}
