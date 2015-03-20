// LCOJ_127.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

	int ladderLength(string start, string end, unordered_set<string> &dict) {

		string* curr,* next;
		int step = 1, idx, branch = 1, count = 0;
		char c, cc;
		// actually this hash is useless, just for recoginizing the end location efficiently
		unordered_set<string>::iterator itr, enditr;
		// damn edges
		if(dict.empty()) return 0;
		if (start.size() == 1 && end.size() == 1 && dict.find(start) != dict.end() && dict.find(end) != dict.end()) return 2;
		if (dict.find(end) == dict.end()) { dict.insert(end);}

		dict.erase(start);
		// this queue is the key
		queue<string*> Q;
		Q.push(&start);
		enditr = dict.find(end);
		// basically, Dijkstra
		while (Q.size()){
			curr = Q.front();
			Q.pop();
			// search the permutation for current word
			for (int i = 0; i < curr->size(); i++){
				c = (*curr)[i];
				for (int j = 0; j < 26; j++){
					cc = 'a' + j;
					if (cc == c) continue;
					(*curr)[i] = cc;
					itr = dict.find(*curr);
					if (itr == dict.end()) continue;
					if (itr != enditr){

						next = new string(*curr);
						Q.push(next);
						dict.erase(*curr);
						count++;
					}
					else{
						return step+1;
					}
				}
				(*curr)[i] = c;
			}
			// check if this is one step for all feet or just one foot
			branch--;
			if (!branch){
				branch = count;
				count = 0;
				step++;
			}
		}
		return 0;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	unordered_set<string> dict = { "hot", "cog", "dot", "dog", "hit", "lot", "log" };
	string st = "hit", end = "cog";

	int res = Solution().ladderLength(st, end, dict);

	return 0;
}

