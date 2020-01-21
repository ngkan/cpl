#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = (ll) 1e16;
ll dp[250251][250];
int zzpow(int x,int p){
	if (!p) return 1;
	int t = zzpow(x,p/2);
	if (p%2) return t*t%250*x%250;
	return t*t%250;
}
int main(){
	dp[0][0] = 1;
	for(int i=1;i<=250250;i++){
		int val = zzpow(i,i);
		for(int j=0;j<250;j++)
			dp[i][j] = (dp[i-1][j] + dp[i-1][(j-val+250)%250]) % mod;
	}
	cout << dp[250250][0] - 1;
}
