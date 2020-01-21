#include <bits/stdc++.h>
#define ll long long
using namespace std;
map <vector<int>, ll> f;

ll answer = 0;
vector <int> lst;
vector <int> tmp;
void cal_lst(int pos){
    if (pos == lst.size())  {
        vector <int> tmp2 = tmp;
        sort(tmp2.begin(), tmp2.end(), greater<int>());
        f[lst] += f[tmp2];
        return;
    }

    for(int i=lst[pos];i>=0;i--)
        tmp[pos] = i, cal_lst(pos+1);
}
void _back(int pos){
    cout << f[lst] << endl;
    for(int i=0;i<lst.size();i++)   cout << lst[i] << ' ' ; cout << endl;


    // check if ok
    ll num = f[lst];
    vector <int> mjk;
    // factorize num
    for(ll i=2;i<=(ll)sqrt(num);i++){
        if (num % i == 0){
            mjk.push_back(0);
            while(num%i == 0)   mjk[mjk.size()-1] ++, num /= i;
        }
    }
    if (num > 1) mjk.push_back(1);

    while(mjk.size() < 16)  mjk.push_back(0);
    if (lst == mjk){
        cout << "found " << f[lst] << endl;
        answer += f[lst];
    }

    if (lst[pos] && pos < 16 - 1){
        lst[pos+1] ++;
        cal_lst(0);
        if (f[lst] <= (ll) 1e16)
            _back(pos+1);
        lst[pos+1] --;
    }

    if (pos == 0 || lst[pos-1] > lst[pos]){
        ++lst[pos];
        cal_lst(0);
        if (f[lst] <= (ll) 1e16)
            _back(pos);
        --lst[pos];
    }
}
int main(){
    for(int i=0;i<16;i++)   lst.push_back(0);
    for(int i=0;i<16;i++)   tmp.push_back(0);
    f[lst] = 1;
    _back(0);
    cout << answer;
}
