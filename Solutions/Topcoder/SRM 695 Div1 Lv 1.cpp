#include <bits/stdc++.h>
using namespace std;
class BearPasswordLexic{
public:
    string findPassword(vector <int> x){
        int n = x.size();
        x.insert(x.begin(),123);
        if (x[1] != n) return "";
        vector <int> tmp = x;
        int cnt[55]; memset(cnt,0,sizeof(cnt));
        for(int i=n;i>=1;i--){
            while(x[i]){
                cnt[i] ++;
                for(int j=i;j>=1;j--){
                    if (x[j] < i - j + 1) return "";
                    x[j]-= i - j + 1;
                }
            }
        }
        int ctrll = 1,ctrlr = n;
        bool now = 1;   // 1 - a, 0 - b
        string res;
        while(res.size() < n && ctrll <= ctrlr){
            while(!cnt[ctrll]) ++ctrll;
            while(!cnt[ctrlr]) --ctrlr;
            if (ctrll > ctrlr) break;
            if (now){
                for(int i=1;i<=ctrlr;i++)
                    res.push_back('a');
                cnt[ctrlr]--;
                now = 0;
            }
            else{
                for(int i=1;i<=ctrll;i++)
                    res.push_back('b');
                cnt[ctrll]--;
                now = 1;
            }
        }
        return res;
    }
}hay;
vector <int> s = {4,2,1,0};
int main(){
    cout << hay.findPassword(s);
}
