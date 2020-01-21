#include <bits/stdc++.h>
using namespace std;
int a[1000005];
vector <int> ans;
int n,k,res;
deque <int> dq1, dq2;
// dq1 la cai chinh
// dq2 la sp
int main(){
    scanf("%d %d\n",&n,&k);
    for(int i=1;i<=n;i++){
        char c;
        scanf("%c",&c);
        a[i] = (c == 'c');
    }
    for(int i=1;i<=n;i++){
        dq1.push_back(i);
        res += a[i];
        while(dq1.size() == k+1){
            if (res == 1){
                while(dq1.size()){
                    ans.push_back(dq1.back());
                    dq1.pop_back();
                }
                res = 0;
                int ax = dq2.size();
                for(int j=1;j<=min((int)ax,k+1);j++){
                    res += a[dq2.back()];
                    dq1.push_front(dq2.back());
                    dq2.pop_back();
                }
            }
            else{
                res -= a[dq1.front()];
                dq2.push_back(dq1.front());
                dq1.pop_front();
            }
        }

    }
    for(int i=ans.size()-1;i>=0;i--){
        printf("%d ",ans[i]);
        if (i%(k+1) == 0) printf("\n");
    }
}
