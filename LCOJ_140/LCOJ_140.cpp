// LCOJ_140.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:

	vector<string> wordBreak(string s, unordered_set<string> &dict) {

		stack<int> nodes;						// when we have a guess, put that word into this record
		vector<string> res;
		string ans;
		int i = 0, j = 1;						// start and end pos of current word search
		bool finish = false;

		while (!finish){
		
			for (; j <= s.length(); j++){
				// search possible current word
				if (dict.find(s.substr(i, j - i)) == dict.end()) continue;

				else if(j == s.length()){
					// a match here, and we have a new sentence with space
					//ans += s.substr(i, j - i);
					//res.push_back(ans);
					//ans = string();
					if (!nodes.size()){
					
						finish;
					}
					else break; 
				}
				else{
					// a matched word, but not reach the end of original string				
					//ans += s.substr(i, j - i) + " ";
					nodes.push(j);
					nodes.push(i);
					i = j;
					j++;
					continue;
				}
			}
			// the last guess is not a good one, pop out and retry
			if (nodes.size()){
				i = nodes.top(); nodes.pop();
				j = nodes.top(); nodes.pop();
				j++;
			}
			else break;
		}
		return res;
	}
};

int main()
{
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	
	string ss;
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("aa");
	dict.insert("aaa");
	dict.insert("aaaa");
	dict.insert("aaaaa");
	dict.insert("aaaaaa");
	dict.insert("aaaaaaa");
	dict.insert("aaaaaaaa");
	dict.insert("aaaaaaaaa");

	dict.insert("aaaaaaaaaa");

	fin >> ss;

	Solution s;
	vector<string> sents = s.wordBreak(ss, dict);

	return 0;
}

