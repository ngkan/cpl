#include <bits/stdc++.h>
using namespace std;
const int N = (int) 1e7+5;
bool isp[N];
int dsup[N];
void prep(int n = (int) 1e7){
    for(int i=2;i<=n;i++)
        isp[i] = 1;
    for(int i=2;i<=n;i++){
        if (!isp[i]) continue;
        for(int j = 2*i;j<=n;j+=i)
            isp[j] = 0;
    }
    for(int i=1;i<=n;i++) dsup[i] = i;
}

int dsu_p(int x){
    return x == dsup[x] ? x : dsup[x] = dsu_p(dsup[x]);
}
void dsu_union(int x,int y){
    dsup[dsu_p(y)] = dsu_p(x);
}
bool dsu_same(int x,int y){
    return dsu_p(x) == dsu_p(y);
}
int main(){
    prep();
    long long ans = 0;
    for(int i=2;i<=(int)1e7;i++){
        if (!isp[i]) continue;
        if (i >= 10){
            //if (isp[i/10]) dsu_union(i,i/10);// cout << i << ' ' << i/10 << endl;
            int val = i, cnt = 0;
            while(val>=10) cnt++,val/=10;
            for(int j=1;j<=cnt;j++) val *= 10; cnt++;
            int val2 = i - val, cnt2 = 0;
            while(val2>0) cnt2++, val2/=10;
            if (cnt == cnt2+1 && isp[i-val])
                dsu_union(i, i - val);// cout << "mjik " << i << ' ' << i-val << endl;
        }
        int tmp = 1;
        for(int digit=0;;digit++){
            if (tmp > i) break;
            int dig;
            int val = i;
            for(int j=0;j<digit;j++) val /= 10;
            dig = val%10;
            for(int di=1;di<dig;di++){
                if (isp[i-dig*tmp+di*tmp])
                    dsu_union(i,i-dig*tmp+di*tmp);
            }
            tmp *= 10;
            if (tmp <= i){
                if (isp[i-dig*tmp/10])
                    dsu_union(i,i-dig*tmp/10);
            }
        }
        if (!dsu_same(2,i)) ans += i;// cout << i << endl;;

    }
    cout << ans;
}
