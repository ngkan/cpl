#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll zzpow(ll x,ll p){
	if (!p) return 1;
	ll t = zzpow(x,p/2);
	if (p%2) return t*t*x;
	return t*t;
}
string A[2] = {"1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679",
			   "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"};
ll fib[100];
ll find(ll id,int layer,ll pos){
	if (layer <= 2)	return A[layer-1][(id+99)%100] - '0';
	if (pos >= fib[layer-2]) return find(id,layer-1, pos-fib[layer-2]);
	return find(id, layer-2, pos);
}
int main(){
	fib[1] = fib[2] = 1;
	for(int i=3;i<=90;i++) fib[i] = fib[i-1] + fib[i-2];
	ll res = 0;
	for(int i=0;i<=17;i++){
		ll id = 1ll * (127ll + 19*i) * zzpow(7,i);
		ll sum = 0;
		for(int j=1;;j++){
			if ((id-1)/100 < fib[j]) {
				 res += zzpow(10,i) * find(id, j, (id-1)/100);
				 break;
			}
			sum += fib[j];
		}
	}
	cout << res;
}
