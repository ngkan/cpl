#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = (ll) 1e16;
vector <int> prime;
bool is_prime(int x){
	if (x == 2) return 1;
	if (x%2 == 0) return 0;
	for(int i=2;i<=(int)sqrt(x);i++)
		if (x%i==0) return 0;
	return 1;
}
ll dp[1548137];
int main(){
	int sum = 1548136;
	for(int i=2;i<5000;i++){
		if (is_prime(i))
			prime.push_back(i);
	}
	dp[0] = 1;
	for(int i=0;i<(int)prime.size();i++){
		for(int j=sum;j>=prime[i];j--)
			dp[j] = (dp[j] + dp[j-prime[i]]) % mod;
	}
	ll res = 0;
	for(int i=2;i<=sum;i++)
		if (is_prime(i)) res = (res + dp[i]) % mod;
	cout << res;
}
