#include <bits/stdc++.h>
using namespace std;
const int mod = 500500507;
bool notp[10000005];
#define ll long long
void sieve(){
	for(int i=2;i<=10000000;i++){
		if (notp[i])	continue;
		for(int j=2*i;j<=10000000;j+=i)
			notp[j] = 1;
	}
}
int main(){
	sieve();
	priority_queue <ll, vector<ll>, greater<ll> > pq;
	for(int i=2;i<=10000000;i++){
		if (!notp[i])
			cout << i << endl,
			pq.push(i);
	}
	ll res = 1;
	for(int i=0;i<500500;i++){
		res = pq.top() % mod * res % mod;
		if (pq.top() < (ll) 1e9)
			pq.push(pq.top() * pq.top());
		pq.pop();
	}
	cout<< res;
}
