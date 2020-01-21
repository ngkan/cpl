#include <bits/stdc++.h>
using namespace std;
int n,p[105];
int mark[300][3000];
string s[105];
vector <char> res,ans(30);
void gg(void){
    cout << "NE";
    exit(0);
}
void solve(int col,int l,int r){
    for(int i=l;i<r;i++){
        if (s[p[i]].size()   <= col) continue; // check
        if (s[p[i+1]].size() <= col) gg();
        if (mark[s[p[i]][col]-'a'][s[p[i+1]][col]-'a'] == 2){
            if (s[p[i]][col] == s[p[i+1]][col]) continue;
            mark[s[p[i]][col]-'a'][s[p[i+1]][col]-'a'] = 1;
            mark[s[p[i+1]][col]-'a'][s[p[i]][col]-'a'] = 0;
            solve(col+1,l,i);
            l = i+1;
        }
        else if (mark[s[p[i]][col]-'a'][s[p[i+1]][col]-'a'] == 0)
            gg();
    }
    for(int i=l;i<=r;i++){
        if (s[p[i]].size() >= col+1)
            solve(col+1,l,r);
        break;
    }
}
int cnt[30];
void build(){
    queue <int> q;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++)
            if (!mark[i][j]) cnt[i] ++;
    }
    for(int i=0;i<26;i++)
        if (!cnt[i]) q.push(i);
    while(q.size()){
        int u = q.front();
        q.pop();
        res.push_back(u + 'a');
        for(int i=0;i<26;i++){
            if (mark[u][i] == 1) cnt[i] --;
            if (mark[u][i] == 1 && !cnt[i]) q.push(i);
        }
    }
}
int main(){
    for(int i=0;i<=29;i++) for(int j=0;j<=29;j++) mark[i][j] = 2;
    iostream::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
        s[i] = "0" + s[i];
    }
    for(int i=1;i<=n;i++)
        cin >> p[i];
    solve(1,1,n);
//    for(int i=0;i<26;i++){
//        for(int j=0;j<26;j++)
//            cout << mark[i][j];cout << endl;
//    }
    build();
    cout << "DA" << endl;
    for(int i=0;i<26;i++)
        ans[res[i]-'a'] = i+'a';
    for(int i=0;i<26;i++)
        cout << ans[i];
}
