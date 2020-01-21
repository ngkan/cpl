#include <bits/stdc++.h>
using namespace std;
int phi[10000005];
int a[10], b[10];
bool check(int x,int y){
	int tx = x, ty = y;
	while(tx) ++a[tx%10], tx/=10;
	while(ty) ++b[ty%10], ty/=10;
	bool ok = 1;
	for(int i=0;i<10;i++) ok &= (a[i] == b[i]);
	while(x) --a[x%10], x/=10;
	while(y) --b[y%10], y/=10;
	return ok;
}
int main(){
	for(int i=2;i<=10000000;i++) phi[i] = i;
	double ratio = 100000;
	int res = 1;
	for(int i=2;i<=10000000;i++){
		if (phi[i] == i){
			for(int j=i;j<=10000000;j+=i)
				phi[j] = phi[j] / i * (i-1);
		}
		if (check(i,phi[i]) && 1.0 * i / phi[i] < ratio)
			ratio = 1.0 * i / phi[i],
			res = i;
	}
	cout << res;
}
