#include <bits/stdc++.h>
using namespace std;
int n,ans;
string s;
vector <int> arr;
char last;
int main(){
    //freopen("roz9c.in","r",stdin);
    iostream::sync_with_stdio(0);
    cin >> n >> s;
    for(int a='a';a<='z';a++){
        for(int b=a+1;b<='z';b++){
            if (a == b) continue;
            arr.clear();
            for (int i=0;i<s.size();i++){
                if (s[i] != a && s[i] != b) continue;
                if (arr.empty()) arr.push_back(1),last = s[i];
                else{
                    if (s[i] == last){
                        if (arr[arr.size()-1] > 0) arr[arr.size()-1] ++;
                        else arr[arr.size()-1] --;
                    }
                    else{
                        if (arr[arr.size()-1] > 0) arr.push_back(-1);
                        else arr.push_back(1);
                        last = s[i];
                    }
                }
            }
            if (arr.size() <= 1) continue;
            //for(int i=0;i<arr.size();i++) cout << arr[i] << ' '; cout << endl;
            ans = max(ans,abs(arr[0] + arr[1]));
            ans = max(ans,arr[0] - 1);
            ans = max(ans,abs(arr[1] + 1));
            if (arr.size() == 2) continue;
            int res0 = arr[0];
            int res1 = arr[1];
            int pq1 = 0;    //
            int pq0 = 0;
            for(int i=2;i<arr.size();i++){
                if (i%2){
                    res1 += arr[i-1] + arr[i];
                    ans = max(ans, abs(res1 - pq1));
                    pq1 = max(pq1, res1 - arr[i]);
                }
                else{
                    res0 += arr[i-1] + arr[i];
                    ans = max(ans,res0 - pq0);
                    pq0 = min(pq0,res0 - arr[i]);
                }
            }
        }
    }
    cout << ans;
}
