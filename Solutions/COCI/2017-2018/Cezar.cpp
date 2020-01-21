#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[20];
int main(){
	for(int i=2;i<=11;i++) cnt[i] = 4;
	cnt[10] = 16;
	cin >> n;
	int sum = 0;
	while(n--){
		int x;
		cin >> x;
		cnt[x] --;
		sum += x;
	}
	int lim = 21 - sum;
	int cnt1=0, cnt2 = 0;
	for(int i=1;i<=lim;i++) cnt1 += cnt[i];
	for(int i=lim+1;i<=11;i++) cnt2 += cnt[i];
	if (cnt1 > cnt2) cout << "VUCI";
	else cout << "DOSTA";
}
