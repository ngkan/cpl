#include <bits/stdc++.h>
using namespace std;
class SortingSubsets{
public:
    int getMinimalSize(vector <int> a){
        vector <int> b = a;
        sort(b.begin(),b.end());
        int ans = 0;
        for(int i=0;i<a.size();i++)
            ans += a[i] == b[i];
        return a.size() - ans;
    }
};
int main(){
    int n,x;
    vector <int> a;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> x,a.push_back(x);
    vector <int> b = a;
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
        n -= (a[i] == b[i]);
    cout << n;
}
