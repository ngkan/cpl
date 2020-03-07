/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

map <long long, long long> tree;
set <long long> mjk;
void cal(long long size){
	mjk.insert(size);
	if (size == 1)
		return;
		
	long long z = size/2;
	if (!mjk.count(z))
		cal(z);
	z = size - z;
	if (!mjk.count(z))
		cal(z);
	return;
}
void ngk(){
	long long n;
	cin >> n;
	tree.clear();
	mjk.clear();
	cal(n);
	
	int cnt = 0;
	vector <pair<long long, long long>> ans;
	for(long long v: mjk){
		tree[v] = cnt++;
		if (v == 1){
			ans.push_back({-1, -1});
		}
		else{
			long long a = v/2, b = v - v/2;
			ans.push_back({tree[b], tree[a]});
		}
	}
	cout << ans.size() << '\n';
	for(auto v: ans)	cout << v.first << ' ' << v.second << '\n';
	cout << ans.size() - 1 << '\n';
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    cin >> test;
    while(test--){
        ngk();
    }
    return 0;
}

