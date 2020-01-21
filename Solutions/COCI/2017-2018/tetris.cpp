#include <bits/stdc++.h>
using namespace std;
int n,m;
string s[20];
int ans[10];
int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> s[i], s[i] = '0' + s[i];
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m-1;j++){
			if (s[i][j] != '.' && s[i][j] == s[i][j+1] && s[i][j+1] == s[i+1][j+1] && s[i+1][j+1] == s[i+1][j]) ans[1]++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-3;j++){
			if (s[i][j] != '.' && s[i][j] == s[i][j+1] && s[i][j+1] == s[i][j+2] && s[i][j+2] == s[i][j+3]) ans[2]++;
		}
	for(int i=1;i<=n-3;i++)
		for(int j=1;j<=m;j++){
			if (s[i][j] != '.' && s[i][j] == s[i+1][j] && s[i+1][j] == s[i+2][j] && s[i+2][j] == s[i+3][j]) ans[2]++;
		}
	for(int i=1;i<=n-1;i++)
		for(int j=2;j<=m-1;j++){
			if (s[i][j] != '.' && s[i][j] == s[i][j+1] && s[i][j+1] == s[i+1][j] && s[i+1][j] == s[i+1][j-1]) ans[3]++;
		}
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=m-1;j++){
			if (s[i][j] != '.' && s[i][j] == s[i+1][j] && s[i+1][j] == s[i+1][j+1] && s[i+1][j+1] == s[i+2][j+1]) ans[3]++;
		}
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m-2;j++){
			if (s[i][j] != '.' && s[i][j] == s[i][j+1] && s[i][j+1] == s[i+1][j+1] && s[i+1][j+1] == s[i+1][j+2]) ans[4]++;
		}
	for(int i=1;i<=n-2;i++)
		for(int j=2;j<=m;j++){
			if (s[i][j] != '.' && s[i][j] == s[i+1][j] && s[i+1][j] == s[i+1][j-1] && s[i+1][j-1] == s[i+2][j-1]) ans[4]++;
		}
	for(int i=1;i<=n-1;i++)
		for(int j=2;j<=m-1;j++){
			if (s[i][j] != '.' && s[i][j] == s[i+1][j] && s[i+1][j] == s[i+1][j-1] && s[i+1][j-1] == s[i+1][j+1]) ans[5]++;
		}
	for(int i=1;i<=n-2;i++)
		for(int j=1;j<=m-1;j++){
			if (s[i][j] != '.' && s[i][j] == s[i+1][j] && s[i+1][j] == s[i+1][j+1] && s[i+1][j+1] == s[i+2][j]) ans[5]++;
		}
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m-2;j++){
			if (s[i][j] != '.' && s[i][j] == s[i][j+1] && s[i][j+1] == s[i][j+2] && s[i][j+2] == s[i+1][j+1]) ans[5]++;
		}
	for(int i=1;i<=n-2;i++)
		for(int j=2;j<=m;j++){
			if (s[i][j] != '.' && s[i][j] == s[i+1][j] && s[i+1][j] == s[i+1][j-1] && s[i+1][j-1] == s[i+2][j]) ans[5]++;
		}
	cout << ans[1] << endl << ans[2] << endl << ans[3] << endl << ans[4] << endl << ans[5];
}
