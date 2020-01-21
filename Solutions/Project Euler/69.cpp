#include <bits/stdc++.h>
using namespace std;
int phi[1000005];
int main(){
	for(int i=2;i<=1000000;i++) phi[i] = i;
	double ratio = 0;
	int res = 1;
	for(int i=2;i<=1000000;i++){
		if (phi[i] == i){
			for(int j=i;j<=1000000;j+=i)
				phi[j] = phi[j] / i * (i-1);
		}
		if (1.0 * i / phi[i] > ratio)
			ratio = 1.0 * i / phi[i],
			res = i;
	}
	cout << res;
}
