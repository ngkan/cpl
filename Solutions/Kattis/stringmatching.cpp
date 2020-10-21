/*  
    ┬┴┬┴┤(･_├┬┴┬┴ hiding from those WAs
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> pifunc(string s){
	vector<int> pi = vector<int>(s.size(), 0);
 
	for (int i = 1, k = 0; i < s.size(); ++i) {
		while (k && s[k] != s[i]) k = pi[k - 1];
		if (s[k] == s[i]) ++k;
		pi[i] = k;
	}
	
    return pi;
}

vector<int> kmp(string s, string p){
	vector <int> pi = pifunc(p), res;

	for (int i = 0, k = 0; i < s.size(); ++i) {
		while (k && (k == p.size() || p[k] != s[i])) k = pi[k - 1];
		if (p[k] == s[i]) ++k;
		if (k == p.size()) res.push_back(i - k + 1);
	} 
	
    return res;
}

string s, p;
void ngk(){
    for(auto v: kmp(s, p))
        cout << v << ' ';
    cout << '\n';
}

int main(int argc, char *argv[]){
    iostream::sync_with_stdio(0);
    int test = 1;
    while(getline(cin, p) && getline(cin, s)){
        ngk();
    }
    return 0;
}
