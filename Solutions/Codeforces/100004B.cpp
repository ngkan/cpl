#include <bits/stdc++.h>
using namespace std;
int test;
string s,tmp;
int look(int len){
    for(int i=0;i<=(int)s.size()-len;i++){
        bool ok = 1;
        for(int j=0;j<len-2;j+=2)
            if (s[i+j] != s[i+j+2]) ok = 0;
        for(int j=1;j<len-2;j+=2)
            if (s[i+j] != s[i+j+2]) ok = 0;
        if (ok) return i;
    }
    return -1;
}
int main(){
    iostream::sync_with_stdio(0);
    cin >> test;
    while(test--){
        cin >> s;
        while(1 && s.size()){
            bool ax = 0;
            int pos;
            tmp.clear();
            for(int i=0;i<s.size();i++){
                if (tmp.size() && tmp[tmp.size()-1] == s[i])
                    tmp.erase(tmp.end()-1), ax = 1;
                else
                    tmp.push_back(s[i]);
            }
            s = tmp;
            for(int len=8;len>=5;len--){
                int pos = look(len);
                if (pos == -1) continue;
                ax = 1;
                tmp.clear();
                for(int i=0;i<pos;i++)
                    tmp.push_back(s[i]);
                for(int i=7;i>=len;i--)
                    tmp.push_back((i%2==1) ? s[pos+1] : s[pos]);
                for(int i=pos+len;i<s.size();i++)
                    tmp.push_back(s[i]);
                s = tmp;
                break;
            }
            tmp.clear();
            for(int i=0;i<s.size();i++){
                if (tmp.size() && tmp[tmp.size()-1] == s[i])
                    tmp.erase(tmp.end()-1), ax = 1;
                else
                    tmp.push_back(s[i]);
            }
            s = tmp;
            if (!ax) break;
        }
        if (!s.size()) cout << "closed\n";
        else cout << "open\n";
    }
}/*
1
abcbcac babcabcaba
abcbcac
*/
