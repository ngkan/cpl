#include <bits/stdc++.h>
#define int long long
using namespace std;
bool visited[1001];
string s;
int n,res;
int dfs(int x){
    for(int i=x;i<s.size();i++){
        visited[i]=true;
        if (s[i]=='0'){
            res++;
        }
        else break;
    }
}
 main(){
    cin >> n;
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++){
        char c;
        cin >> c;
        s.push_back(c);
    }
    while (s[0]=='0') s.erase(s.begin());
    while (s[s.size()-1]=='0') s.erase(s.begin()+s.size()-1);
    if (s.size()==0) {cout << 0;return 0;}
    vector <int> ans;
    for(int i=0;i<s.size();i++){
        if (s[i]=='0' && !visited[i]){
            res=0;
            dfs(i);
            if (res>=1) ans.push_back(res+1);
        }
    }
    int ans2=1;
    for(int i=0;i<ans.size();i++) ans2*=ans[i];
    cout << ans2;
}
