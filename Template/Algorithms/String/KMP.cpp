#include <bits/stdc++.h>
using namespace std;

/*
    Knuth-Moris-Pratt algorithm
    Status: Tested, Kattis, problem stringmatching
    pi[i] = longest prefix-suffix for first i+1 characters.
*/

vector<int> kmp(string &s,string &p){
	vector<int> pi(p.size(), 0), prefix;
	for (int i = 1, k = 0; i < p.size(); ++i) {
		while (k && p[k] != p[i]) k = pi[k - 1];
		if (p[k] == p[i]) ++k;
		pi[i] = k;
	}
	for (int i = 0, k = 0; i < s.size(); ++i) {
		while (k && p[k] != s[i]) k = pi[k - 1];
		if (p[k] == s[i]) ++k;
		prefix.push_back(k);
	} 
    return prefix;
}