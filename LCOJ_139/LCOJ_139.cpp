// LCOJ_139.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:

	// compare if the suffix is contained in the word
	bool stringSuffComp(const string& suff, const string& word){

		if (suff.length() > word.length()) return false;

		for (int i = suff.length() - 1, j = word.length() - 1; i >= 0 && j >= 0; i--, j--){

			if (suff[i] != word[j]) return false;
		}
		return true;
	}

	// check if any suffix of s is not contained in the dict
	// only check those suffix that is shorter than the minimum length of the words in dict
	bool checkSuffix(string* s, unordered_set<string> &dict){

		string suff;
		unordered_set<string>::iterator j = dict.begin();
		// Record the minimum length of the words, help check the suffix
		int suffLen = (*s).length();
		while (j != dict.end()){

			if ((*j).length() < suffLen) suffLen = (*j).length();
			j++;
		}

		j = dict.begin();
		// check if the suffix of string is contained as the suffix of each word
		for (int i = (*s).length() - 1; i >= (*s).length() - suffLen; i--){

			if (i < 0) break;
			suff = (*s).substr(i);
			bool found = false;
			while (j != dict.end()){

				if (stringSuffComp(suff, (*j))) {
					found = true;
					break;
				}
				j++;
			}
			if (!found) return false;
		}
		return true;
	}

	bool wordBreak(string s, unordered_set<string> &dict) {

		stack<int> nodes;						// when we have a guess, put idx of that word into this record
		stack<string> str_nodes;				// record the sentence that is matched so forth
		vector<string> res;
		string* ans = new string("");
		int i = 0, j = 1;						// start and end pos of current word search
		bool finish = false;

		if (!checkSuffix(&s, dict)) return false;	// branch-cutting? get rid of the cases that would fail but exetremely costy

		while (!finish){

			for (; j <= s.length(); j++){
				// search possible current word
				if (dict.find(s.substr(i, j - i)) == dict.end()) continue;
				else if (j == s.length()){
					// a match here, and we have a new sentence with space
					return true;
				}
				else{
					// a matched word, but not reach the end of original string	
					str_nodes.push(string(*ans));
					*ans += s.substr(i, j - i) + " ";
					nodes.push(j);
					nodes.push(i);

					i = j;
					continue;
				}
			}
			// the last guess is not a good one, pop out and retry
			if (nodes.size()){
				*ans = str_nodes.top(); str_nodes.pop();
				i = nodes.top(); nodes.pop();
				j = nodes.top(); nodes.pop();
				j++;
			}
			else break;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

