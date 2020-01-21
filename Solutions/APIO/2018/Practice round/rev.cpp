#include <bits/stdc++.h>
using namespace std;
int main(){
    iostream::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <long long> lst;
    while(n--){
        long long x;
        cin >> x;
        lst.push_back(x);
    }
    reverse(lst.begin(), lst.end());
    for(auto v: lst)    cout << v << ' ';
}
