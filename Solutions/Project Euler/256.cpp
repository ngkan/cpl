#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int N = (int) 1e8;
int cnt[N+5];
bool check(int x,int y){
	if (x%2 == 1){
		if (y%2 == 1) return 0;
		// x-1 or x+1
		int val = y % (x-1);
		assert(val % 2 == 0);
		val /= 2;
		return (val == 0 || y/val >= (x+1));
	}
	else{
		bool res = 0;
		int val = y % (x-1);
		// x-1 even
		val = ((x-1) * (val%2==1) + val) / 2;
		res |= (val == 0 || y/val >= (x+1));
		
		val = (y-1) % (x-1);	
		val = ((x-1) * (val%2==1) + val) / 2;
		res |= (val == 0 || (y-1)/val >= (x+1));
		
		val = (y+1) % (x-1);	
		val = ((x-1) * (val%2==1) + val) / 2;
		res |= (val == 0 || (y+1)/val >= (x+1));
		
		return res;
	}
}
int main(){
	long long cntt = 0;
	for(int i=3;i<=N;i++){
		for(int j=i;j<=N/i;j++){
			// i <= j
			// check if can title when is i
			if (!check(i,j)) ++cnt[i*j];
			cntt++;
			if (cntt % 10000000 == 0) cout << cntt << ' ' << i << ' ' << j << '\n';
		}
	}
	int ma = 0;
	for(int i=1;;i++){
		if (i % 1000000 == 0) cout << i << ' ' << ma << '\n';
		ma = max(ma, cnt[i]);
		if (cnt[i] == 200) {cout << "res " << i; break;}
	}
}
