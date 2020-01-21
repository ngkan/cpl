#include <iostream>
using namespace std;
#define int long long
const int mod = 1000000;
int arr[4000005];
int a[2000][2000];
signed main() {
	// your code goes here
	//return 0;
	for(int i=1;i<=55;i++) arr[i-1] = (100003 - 200003*i + 300007*i*i*i)%mod - mod/2;
	for(int i=55;i<4000000;i++) arr[i] = (arr[i-24] + arr[i-55] + 1000000)%mod - mod/2;
	cout << arr[9] << ' ' << arr[99] << endl;
	for(int i=0;i<2000;i++)	for(int j=0;j<2000;j++)	a[i][j] = arr[i*2000+j];
	// row
	int ans = (int)-1e18;
	for(int i=0;i<2000;i++){
		int mi = 0, sum = 0;
		for(int j=0;j<2000;j++)
			sum += a[i][j],
			ans = max(ans, sum - mi),
			mi = min(mi, sum);
		
	}
	// col
	for(int j=0;j<2000;j++){
		int mi = 0, sum = 0;
		for(int i=0;i<2000;i++)
			sum += a[i][j],
			ans = max(ans, sum - mi),
			mi = min(mi, sum);
		
	}
	// diagonal - row
	for(int j=0;j<2000;j++){
		int mi = 0, sum = 0;
		for(int cnt=0;j+cnt<2000;cnt++)
			sum += a[cnt][j+cnt],
			ans = max(ans, sum - mi),
			mi = min(mi, sum);
	}
	// diagonal - col
	for(int i=0;i<2000;i++){
		int mi = 0, sum = 0;
		for(int cnt=0;i+cnt<2000;cnt++)
			sum += a[i+cnt][cnt],
			ans = max(ans, sum - mi),
			mi = min(mi, sum);
	}
	// antidiagonal - row
	for(int j=0;j<2000;j++){
		int mi = 0, sum = 0;
		for(int cnt=0;cnt<=j;cnt++)
			sum += a[cnt][j-cnt],
			ans = max(ans, sum - mi),
			mi = min(mi, sum);
	}
	// antidiagonal - col
	for(int i=0;i<2000;i++){
		int mi = 0, sum = 0;
		for(int cnt=0;cnt<=i;cnt++)
			sum += a[i-cnt][cnt],
			ans = max(ans, sum - mi),
			mi = min(mi, sum);
	}
	cout << ans;
}
