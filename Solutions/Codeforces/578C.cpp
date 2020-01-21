#include <bits/stdc++.h>
using namespace std;
int n;
double a[200005];
double l= -1e9,r = 1e9;
double solve(double x){
    double res = 0,tmp1 = 0, tmp2 = 0,sum = 0;
    for(int i=1;i<=n;i++){
        sum = sum + a[i] - x;
        res = max(res, abs(sum - tmp1));
        res = max(res, abs(sum - tmp2));
        tmp1 = min(tmp1, sum);
        tmp2 = max(tmp2, sum);
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    for(int i=0;i<=200;i++){
        double m1 = (2.0*l + r) / 3;
        double m2 = (l + 2.0*r) / 3;
        if (solve(m1) < solve(m2))  r = m2;
        else l = m1;
    }
    printf("%.12lf",solve(l));
}
