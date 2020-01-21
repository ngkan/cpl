#include <bits/stdc++.h>
using namespace std;

int grundy[100005];
map <int,int> cnt;
long long mjk(int n){
	// count number of (a,b,c) triplets that 0 <= a <= b <= c <= n
	return 1ll * (n+3)* (n+2) * (n+1) / 6;
}
int main(){
	int n;
	cin >> n;
	
	cnt[0]++;
	
	for(int i=1;i<=n;i++){
		set <int> s;
		for(int j=1;i-j*j>=0;j++){
			s.insert(grundy[i-j*j]);
		}
		for(int j=0;;j++){
			if (!s.count(j)){
				grundy[i] = j;
				cnt[j] ++;
				break;
			}
		}
	}
	
	long long ans = 0;
	//~ for(int i=0;i<=n;i++){
		//~ for(int j=i;j<=n;j++){
			//~ for(int k=j;k<=n;k++){
				//~ if ((grundy[i] ^ grundy[j] ^ grundy[k]) > 0)
					//~ ans ++;
			//~ }
		//~ }
	//~ }cout << ans;
	//~ return 0;
	
	// different
	for(auto a: cnt){
		for(auto b: cnt){
			if (a.first >= b.first)	continue;
				for(auto c: cnt){
					if (b.first >= c.first)	continue;
					if ((a.first ^ b.first ^ c.first) > 0){
						ans += 1ll*a.second * b.second * c.second;
					}						
				}
		}
	}

	for(auto a: cnt){
		// same
		if (a.first)
			ans += mjk(a.second-1);
		for(auto b: cnt){
			// two
			if (b.first == 0)	continue;
			if (a.first == b.first)	continue;
			ans += 1ll * a.second * (a.second+1) / 2 * b.second;
		}
	}
	cout << mjk(n) - ans;
}
