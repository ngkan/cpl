#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll mod = (ll) 1e19;
int divi[60000005];
int n;
void prep(int N){
	for(int i=1;i<=N;++i)
		for(int j=i;j<=N;j+=i)
			++divi[j];
	cout << "prepdone\n";
}
ll fw[60000005];
void fw_upd(int pos,ll val){
	for(;pos<=n;pos+=pos&-pos) fw[pos] = (fw[pos] + val) % mod;
}
ll fw_get(int pos){
	return pos ? (fw[pos] + fw_get(pos-(pos&-pos))) % mod : 0;
}
ll val[60000006];
ll cal1[60000006];
int pos[60000006];
vector <ll> lst;
int main(){
	cin >> n;
	prep(n+1);
	for(int i=1;i<=n;i++){
		if (i%2 == 0) val[i] = 1ll * divi[i/2] * divi[i+1];
		else val[i] = 1ll * divi[i] * divi[i/2+1];
		lst.push_back(val[i]);
	}
	cout << "valdone\n";
	sort(lst.begin(), lst.end());
	for(int i=1;i<=n;i++){
		if (i % 100000 == 0)cout << i << endl;
		pos[i] = n - (lower_bound(lst.begin(),lst.end(),val[i]) - lst.begin() + 1) + 1;
	}
	cout << "posdone\n";
	// cal1
	for(int i=1;i<=n;i++){
		if (i % 100000 == 0)cout << i << endl;
		cal1[i] = fw_get(pos[i]-1);
		fw_upd(pos[i], 1);
	}
	// cal2
	memset(fw,0,sizeof(fw));
	ll sum = 0;
	for(int i=1;i<=n;i++){
		if (i % 100000 == 0)cout << i << endl;
		sum = (sum + fw_get(pos[i]-1)) % mod;
		fw_upd(pos[i], cal1[i]);
	}
	cout << sum;
}
