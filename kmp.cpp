#include <bits/stdc++.h>
using namespace std;

vector<int> lps(string s){ //longest common prefix & suffix, O(n) where n=len(s)
	vector<int> pi(s.length()); //pi[0] = 0
	for(int i = 1; i < s.length(); i++){
		int j = pi[i-1];
		while(j > 0 && s[j] != s[i]) j = pi[j-1];
		if(s[j] == s[i]) pi[i] = j+1; //else pi[i] = 0
	}
	return pi;
}

vector<int> kmp(string s, string t){ //indices of the ends of where t occurs in s, O(n+m) where n=len(s), m=len(t)
	vector<int> sol; if(s.length() < 1) return sol;
	vector<int> pi_t = lps(t);
	vector<int> pi_s(s.length());
	pi_s[0] = (s[0] == t[0]) ? 1 : 0; if(pi_s[0] && t.length() == 1) sol.push_back(0);
	for(int i = 1; i < s.length(); i++){
		int j = pi_s[i-1];
		while(j > 0 && t[j] != s[i]) j = pi_t[j-1];
		if(t[j] == s[i]) pi_s[i] = j+1;
		if(pi_s[i] == t.length()) sol.push_back(i);
	}
	return sol; //for number of occurrences, use sol.size()
}
