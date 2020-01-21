#include <bits/stdc++.h>
using namespace std;
string ans = "1";
map <int,string> mp;
int main(){
	mp[1] = "1";
	mp[2] = "2";
	mp[3] = "3";
	mp[4] = "4";
	mp[5] = "5";
	mp[6] = "6";
	mp[7] = "7";
	mp[8] = "8";
	mp[9] = "9";
	mp[10] = "10";
	
	vector <int> a;
	for(int i=1;i<=10;i++) a.push_back(i);
	int b[][3] = {{0,1,2}, {1,3,4}, {3,5,6}, {5,7,8}, {7,0,9}};
	do{
		// 0 1 2
		// 1 3 4
		// 3 5 6
		// 5 7 8
		// 7 0 9
		int sum[5];
		for(int i=0;i<5;i++)
			sum[i] = a[b[i][0]] + a[b[i][1]] + a[b[i][2]];
		
		bool ok = 1;
		for(int i=0;i<=4;i++) for(int j=0;j<=4;j++) ok &= (sum[i] == sum[j]);
		if (!ok) continue;
		
			cout << sum[0] << endl;
		int id = 0;
		for(int i=1;i<=4;i++)
			if (a[b[i][2]] < a[b[id][2]]) id = i;
		string res;
		for(int i = id, cnt=0;cnt!=5;i=(i-1+5)%5, ++cnt){
			res += mp[a[b[i][2]]] + mp[a[b[i][1]]] + mp[a[b[i][0]]];
		}
		if (res.size() != 17) 
			ans = max(ans, res);
	}while(next_permutation(a.begin(), a.end()));
	cout << ans;
}

