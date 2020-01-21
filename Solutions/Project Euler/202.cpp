#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin >> n;
	ll newN = (n+1)/2 + 1;
	cout << newN << endl;
	
	vector <int> cool; // =   {5, 11, 17, 23, 29, 41, 47};
	n = newN;
	for(int i=2;n>1;i++){
		if (n % i) continue;
		cool.push_back(i);
		while(n % i == 0) n /= i;
	}
	for(auto v: cool) cout << v << ' '; cout << endl;
	ll ans = 0;
	for(int mask=0;mask<(1<<(int)cool.size());mask++){
		ll mau = 1;
		for(int i=0;i<(int)cool.size();i++){
			if ((mask>>i)&1)
				mau *= cool[i];
		}
		if (__builtin_popcount(mask) % 2 == 0){
			ans += ((newN / mau) + 1) / 3;
		}
		else{
			ans -= ((newN / mau) + 2) / 3;
		}
	}
	cout << ans;
	return 0;
	
	//~ cin >> n
	//~ ll newN = (n+1) / 2;
	//~ for(int i=1;i<=newN+1;i++){
		//~ if (__gcd(1ll*i,newN+1) == 1 && (newN+1 - 2*i  + 33333333) % 3 == 0) res++;
		
	//~ }
	//~ cout << res;
}
