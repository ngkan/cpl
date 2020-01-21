#include <bits/stdc++.h>
using namespace std;
int n, a[100005], cnt[100005];
vector <int> type[100005];
string ans[100005];

int main(){
    iostream::sync_with_stdio(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        type[a[i]].push_back(i);
        cnt[a[i]]++;
    }

    for(int i=100000;i>=0;i--)
        cnt[i] += cnt[i+1]/10,
        cnt[i+1]%=10;


    if (cnt[0]){
        if (cnt[0] >= 2){
            cout << "NO";
            return 0;
        }
        for(int i=1;i<=100000;i++){
            if (cnt[i]){
                cout << "NO";
                return 0;
            }
        }
    }

    int maxi = 0;
    for(int i=1;i<=100000;i++){
        if (type[i].size()) maxi = i;
        cnt[i] = type[i].size();
    }
    if (cnt[maxi] == 1){
        cout << "NO";
        return 0;
    }
    int specialid = type[maxi].back();
    for(int i=1;i<=n;i++)   ans[i] = "1";
    for(int i=1;i<=maxi;i++)    ans[specialid] += '0';
    cnt[maxi] --;

    if (cnt[maxi] % 10 == 0){
        cnt[maxi] ++;
        ans[type[maxi][0]] = "2";
    }
    reverse(ans[specialid].begin(), ans[specialid].end());
    for(int i=maxi;i>=1;i--){
        while(cnt[i]--){
            for(int _=maxi-i;;_++){
                if (ans[specialid][_] == '0')
                    ans[specialid][_] = '9';
                else{
                    ans[specialid][_] --;
                    break;
                }
            }
        }
    }
    reverse(ans[specialid].begin(), ans[specialid].end());

    cout << "YES\n";
    for(int i=1;i<=n;i++){
        cout << "0.";
        reverse(ans[i].begin(), ans[i].end());
        while(ans[i].back() == '0') ans[i].pop_back();
        reverse(ans[i].begin(), ans[i].end());
        assert(ans[i].size());
        assert(ans[i].back() != '0');

        for(int _=1;_<=a[i]-(int)ans[i].size();_++)  cout << "0";
        cout << ans[i] << '\n';
    }
}
/*
21
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2

13
2 2 3 3 3 3 3 3 3 3 3 3 3
12
2 2 3 3 3 3 3 3 3 3 3 3
*/
