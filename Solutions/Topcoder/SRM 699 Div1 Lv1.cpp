#include <bits/stdc++.h>
#define ll long long
using namespace std;
class OthersXor{
public:
     long long minSum(vector <int> x){
        vector <int> a;
        int cnt = 0;
        for(int i=0;i<x.size();i++){
            if (x[i] == -1) cnt++;
            else a.push_back(x[i]);
        }
        if (!a.size()) return 0;
        ll res = 0;
        cnt = min(1,cnt);
        int n = a.size();
        a.insert(a.begin(),-1);

        for(int bit=0;bit<30;bit++){
            //cout << bit << endl;
            int b[50];
            int xorcd[50];
            int fin = 100;
            for(int val=0;val<2;val++){
                b[1] = val;
                xorcd[0] = 0;
                xorcd[1] = val;
                int one = (val == 1);
                for(int i=2;i<=n;i++)
                    b[i] = (((a[1] ^ a[i]) >> bit) & 1) ? (1^val) : val,
                    xorcd[i] = xorcd[i-1] ^ b[i],
                    one += (b[i] == 1);
                int fail = 0;
                for(int i=1;i<=n;i++){
                    int x = (xorcd[i-1] ^ xorcd[n] ^ xorcd[i]);
                    fail += (x != ((a[i]>>bit) & 1));
                }
                //cout << val << ' ' << one << ' ' << fail << endl;
                if (fail == 0) fin = min(fin, one);
                else if (fail == n && cnt) fin = min(fin, one+1);
            }

            if (fin == 100) return -1;
            res += 1ll * (1ll<<bit) * fin;
            //cout << res << endl;
        }
        return res;
     }
};
int main(){
    vector <int> x;
    x.push_back(1); x.push_back(-1); x.push_back(3);
    OthersXor a;
    a.OthersXor::minSum(x);
}
