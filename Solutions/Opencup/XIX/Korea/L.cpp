/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

int n, a[100005];
int f[100005];
int dir[100005];
int same[100005];
int res[100005], cnt[100005];

void prep(){
	f[n] = 1;

	
	for(int i=n-1;i>=1;i--){
		if (a[i] <= a[i+1] && a[i+1] <= a[i+2])
			f[i] = f[i+1] + 1;
		else if (a[i] > a[i+1] && a[i+1] > a[i+2])
			f[i] = f[i+1] + 1;
		else
			f[i] = 2;
	}
	
	for(int gap=1;gap<=n;gap++){
		for(int i=1;i<=n;i+=gap){
			cnt[gap]++;
			res[gap] += max(0, min(n-i+1, gap) - f[i]); 
			i = max(i, i+f[i]-gap);
		}
	}
}
void ngk(){
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	
	prep();
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		cout << cnt[x] << ' ' << res[x] << '\n';
	}
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(test--){
        ngk();
    }
    return 0;
}

