/**
 * Prefix function
 * Author: ngkan
 * Description: For each prefix, find its longest prefix-suffix.
 * Complexity: O(n + m)
 * Status: Tested
 *	 > Kattis-stringmatching
 */

vector<int> pifunc(string s){
	vector<int> pi = vector<int>(s.size(), 0);
 
	for (int i = 1, k = 0; i < s.size(); ++i) {
		while (k && s[k] != s[i]) k = pi[k - 1];
		if (s[k] == s[i]) ++k;
		pi[i] = k;
	}

    return pi;
}