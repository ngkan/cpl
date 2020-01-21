#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_prime(ll x){
	if (x < 2) return 0;
	if (x == 2) return 1;
	if (x%2 == 0) return 0;
	for(ll i=2;i<=(ll)sqrt(x);i++)
		if (x%i==0) return 0;
	return 1;
}
bool only(ll val,ll val2){
	while(__gcd(val,val2) != 1){
		val /= __gcd(val, val2);
	}
	return (val == 1);
}
vector <ll> lst;
ll fact13 = 6227020800ll;
void backtrack(ll num,ll present0,ll present1,ll bound){
	// check current
	ll canbe = fact13 / present0 * present1;
	if (only(canbe, present1))
		lst.push_back(canbe);
	if (only(canbe*2, present1*2))
		lst.push_back(canbe*2);
		
	// continue backtrack
	for(ll i=1;i<=(ll)sqrt(num);i++){
		if (num % i) continue;
		
		if (present1 % (i+1) 	 && i+1   	< bound && is_prime(i+1)	 && i+1 != 2){
			backtrack(num / i, present0 * i, present1 * (i+1), i+1);
		}
		
		if (i*i == num) continue;
		
		if (present1 % (num/i+1) && num/i+1 < bound && is_prime(num/i+1) && num/i+1 != 2){
			backtrack(i, present0 * (num/i), present1 * (num/i+1), num/i+1);
		}
	}
}
int main(){
	backtrack(fact13, 1ll, 1ll, fact13 * 2);
	sort(lst.begin(), lst.end());
	lst.resize(unique(lst.begin(),lst.end()) - lst.begin());
	cout << lst.size() << endl;
	cout << lst[149999];
}
