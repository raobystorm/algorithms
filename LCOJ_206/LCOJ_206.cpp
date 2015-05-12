// LCOJ_206.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <unordered_map>

using namespace std;

class Solution {
public:

	int lookup(char hash[], char c){
		int i = 0; 
		while (hash[i] != '\0'){
			if (hash[i] == c) return i + 1;
			i++;
		}
		return -1;
	}

	bool isIsomorphic(string s, string t) {

		char shash[256] = { '\0' };
		char thash[256] = { '\0' };

		int *smap = (int*)malloc(sizeof(int)*s.size());
		int *tmap = (int*)malloc(sizeof(int)*t.size());
		int i = 0;
		while(s[i] != '\0' && t[i] != '\0'){

			int sidx = lookup(shash, s[i]);
			int tidx = lookup(thash, t[i]);

			if (sidx != -1)	smap[i] = sidx;

			else{

				int j = 0; while (shash[j] != '\0') j++;
				shash[j] = s[i];
				smap[i] = j+1;
			}

			if (tidx != -1)	tmap[i] = tidx;
			else{

				int j = 0; while (thash[j] != '\0') j++;
				thash[j] = t[i];
				tmap[i] = j+1;
			}
		}

		for (int i = 0; i < s.size(); i++)
			if (smap[i] != tmap[i]) return false;
		
		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = "qwertyuiop[]asdfghjkl;'\\zxcvbnm,./";
	string t = "',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz";

	bool res = Solution().isIsomorphic(s, t);
	return 0;
}

