// LCOJ_49.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>

using namespace std;

class Solution {
public:

	string encode(string& s){

		int count[26] = { 0 };
		string res = "";
		for (int i = 0; i < s.size(); i++){

			count[s[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++){
			if (count[i]){

				res += char(i + 'a');
				res += char(count[i]);
			}
		}

		return res;
	}

	vector<string> anagrams(vector<string> &strs) {

		if (strs.size() <= 1) return vector<string>();

		unordered_map<string, string> dict;
		unordered_map<string, string>::iterator itr;
		vector<string> anagrams;

		for (int i = 0; i < strs.size(); i++){

			string coded = encode(strs[i]);
			itr = dict.find(coded);
			if (itr != dict.end()){
				// we found a anagram pair or more, if it is just a pair, insert both words into vector of anagrams.
				if ((dict[coded].compare("WHOSH*TTHISNONSENSEEMPTYSTRINGTESTCASE"))) {
					// label the first word to empty, indicates it has been inserted into the vector
					anagrams.push_back(dict[coded]);
					dict[coded] = "WHOSH*TTHISNONSENSEEMPTYSTRINGTESTCASE";
				}
				anagrams.push_back(strs[i]);
				continue;

			}
			else{

				dict[coded] = strs[i];
			}
		}

		return anagrams;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> words = {"", "", ""};//{ "cat", "rye", "aye", "dog", "god", "cud", "cat", "old", "fop", "bra" };
	vector<string> res = Solution().anagrams(words);
	return 0;
}

