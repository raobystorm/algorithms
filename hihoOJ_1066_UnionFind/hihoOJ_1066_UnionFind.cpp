// hihoOJ_1066_UnionFind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;
// the implementation of union find by integer array
string find(unordered_map<string, string>& v, string s){
	if (v[s] == s) return s;
	v[s] = find(v, v[s]);
	return v[s];
}

int main()
{
	int t, cnt = 1;
	cin >> t;
	char o;
	string s1, s2;
	unordered_map<string, string> hash;
	while (t--){
		cin >> o;
		cin >> s1 >> s2;
		if (o == '0'){
			if (hash.find(s1) == hash.end()) hash[s1] = s1;
			if (hash.find(s2) == hash.end()) hash[s2] = s2;
			// union the set
			hash[find(hash, s1)] = find(hash, s2);
		}
		else{
			if (hash.find(s1) == hash.end()) hash[s1] = s1;
			if (hash.find(s2) == hash.end()) hash[s2] = s2;
			if (find(hash, s1) == find(hash, s2)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}*/

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;
#define MAX 100001
// the implementation of union find by integer array
int find(int* v, int n){
	if (v[n] == n) return n;
	v[n] = find(v, v[n]);
	return v[n];
}

int main()
{
	int t, cnt = 1;
	cin >> t;
	char o;
	string s1, s2;
	unordered_map<string, int> hash;
	int u[MAX] = { 0 };
	while (t--){
		cin >> o;
		cin >> s1 >> s2;
		if (o == '0'){
			if (hash.find(s1) == hash.end()) { hash[s1] = cnt++; u[hash[s1]] = hash[s1]; }
			if (hash.find(s2) == hash.end()) { hash[s2] = cnt++; u[hash[s2]] = hash[s2]; }
			// change the represent of entry1 to the represent of entry2
			u[find(u, hash[s1])] = find(u, hash[s2]);
		}
		else{

			if (hash.find(s1) == hash.end()) { hash[s1] = cnt++; u[hash[s1]] = hash[s1]; }
			if (hash.find(s2) == hash.end()) { hash[s2] = cnt++; u[hash[s2]] = hash[s2]; }
			if (find(u, hash[s1]) == find(u, hash[s2])) printf("yes\n");
			else printf("no\n");
		}
	}
	return 0;
}
