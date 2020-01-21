#include <bits/stdc++.h>
using namespace std;
struct hihi{
    double val;
    int tu,mau;
};
hihi mk(double a,int b,int c){
    hihi tmp;
    tmp.val = a;
    tmp.tu = b;
    tmp.mau = c;
    return tmp;
}
bool cmp(hihi x,hihi y){
    return x.val > y.val;
}
vector <hihi> __;
int main(){
    for(int i=1000000;i>=10;i--){
        int zz = (3*i-1)/7;
        __.push_back(mk((double) zz / i, zz / __gcd(zz,i), i / __gcd(zz,i)));
    }
    sort(__.begin(),__.end(),cmp);
    cout << __[0].tu << ' ' << __[0].mau;
}
