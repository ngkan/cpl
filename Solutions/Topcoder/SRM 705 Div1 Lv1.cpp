#include <bits/stdc++.h>
using namespace std;
class AlphabetOrderDiv1{
public:
    vector <int> G[200];
    int degin[200];
    queue <int> q;
    string isOrdered(vector <string> words){
        for(int i=0;i<(int)words.size();i++){
            for(int j=0;j<(int)words[i].size()-1;j++){
                if (words[i][j+1] == words[i][j]) continue;
                G[(int)words[i][j+1]].push_back((int)words[i][j]),
                degin[(int)words[i][j]]++;
            }
        }
        for(int i = 'a';i <= 'z';i++)
            if (!degin[i]) q.push(i);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int i=0;i<(int)G[u].size();i++){
                int v = G[u][i];
                degin[v]--;
                if (!degin[v]) q.push(v);
            }
        }
        for(int i='a';i<='z';i++)
            if (degin[i]) return "Impossible";
        return "Possible";
    }
};
AlphabetOrderDiv1 a;
vector <string> s;
int main(){
    s.push_back("abcd");
    s.push_back("cb");
    cout << a.AlphabetOrderDiv1::isOrdered(s);
}
