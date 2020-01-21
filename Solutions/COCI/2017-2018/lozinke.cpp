#include <bits/stdc++.h>
using namespace std;
int n;
map <string, int> mp;
string s[20005];
int main(){
	srand(time(NULL));
	iostream::sync_with_stdio(0);
	
	cin >> n;
	int ans = 0;
	for(int id=1;id<=n;id++){
		cin >> s[id];
		map <string, bool> ownmp;
		for(int i=0;i<s[id].size();i++){
			string tmp;
			for(int j=i;j<s[id].size();j++){
				tmp.push_back(s[id][j]);
				if (ownmp.count(tmp)) continue;
				ownmp[tmp] = 1;
				if (mp.count(tmp) != 0) ans += mp[tmp];
			}
		}
		mp[s[id]] ++;
	}
	mp.clear();
	for(int id=n;id>=1;id--){
		map <string, bool> ownmp;
		for(int i=0;i<s[id].size();i++){
			string tmp;
			for(int j=i;j<s[id].size();j++){
				tmp.push_back(s[id][j]);
				if (ownmp.count(tmp)) continue;
				ownmp[tmp] = 1;
				if (mp.count(tmp) != 0) ans += mp[tmp];
			}
		}
		mp[s[id]] ++;
	}
	cout << ans;
}
