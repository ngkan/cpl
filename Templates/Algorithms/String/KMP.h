/**
 * Knuth–Morris–Pratt algorithm
 * Author: ngkan
 * Description: Find the appearances of p in s
 * Complexity: O(n)
 * Status: Tested, Kattis-stringmatching
 */

#include "PrefixFuntion.h"

vector<int> kmp(string s, string p){
	vector <int> pi = pifunc(p), res;

	for (int i = 0, k = 0; i < s.size(); ++i) {
		while (k && (k == p.size() || p[k] != s[i])) k = pi[k - 1];
		if (p[k] == s[i]) ++k;
		if (k == p.size()) res.push_back(i - k + 1);
	} 
	
    return res;
}