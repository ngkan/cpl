/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;


void ngk(){
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	
	long long ans = 0;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			if (__gcd(i, j) > 1 || (i+j) >= 1000)
				continue;
			
			long long l = max((a+i-1)/i, (c+j-1)/j), r = min(b/i, d/j);
			l = max(l, 1ll);
			
			ans += max(0ll, r - l + 1);
		}
	}
	
	cout << ans;
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}

