#include <bits/stdc++.h>
using namespace std;
bool notprime[200000005];
bool notres[200000005];
void prep(int N){
	notprime[1] = 1;
	for(int i=2;i<=N;i++){
		if (notprime[i]) continue;
		for(int j=i;j<=N/i;j++)
			notprime[i*j] = 1;
	}
}
long long solve(int N){
	long long ans = 0;
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j+=i)
			if (notprime[j/i + i]) notres[j] = 1;
		if (!notres[i]) ans += i;
	}
	return ans;
}
int main(){
	int n;
	cin >> n;
	prep(2*n);
	cout << solve(n);
}
