// LCOJ_76.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:

	unordered_map<char, int> count;
	unordered_set<char> chash;
	int min;
	int idx;

	bool checkAppear(){

		unordered_set<char>::iterator itrH = chash.begin();

		while (itrH != chash.end()){

			if (count[*itrH] == -1) return false;
			itrH++;
		}

		return true;
	}

	void updateMin(int idxTmp){

		int tmpMax = -1;
		int tmpMin = 65536;

		unordered_map<char, int>::iterator itr = count.begin();

		while (itr != count.end()){

			if (tmpMax < itr->second) 	tmpMax = itr->second;
			itr++;
		}
		itr = count.begin();
		while (itr != count.end()){

			if (tmpMin > itr->second) 	tmpMin = itr->second;
			itr++;
		}

		if ((tmpMax - tmpMin) < min) { 
			min = tmpMax - tmpMin; 
			idx = idxTmp;
		}
	}

	void updateCount(){

		unordered_map<char, int>::iterator itr = count.begin();
		while (itr != count.end()){

			if (itr->second != -1) (itr->second)++;
			itr++;
		}
	}

	string minWindow(string s, string T) {

		int n = s.length();
		if (n <= 0) return string("");
		if (T.length() <= 1) return T;
		if (T.length() > s.length()) return "";
		string res;

		min = n;
		for (int i = 0; i < T.length(); i++){

			if (chash.find(T[i]) == chash.end()){
				chash.insert(T[i]);
				count[T[i]] = -1;
			}
		}

		for (int i = 0; i < s.length(); i++){

			updateCount();

			if (chash.find(s[i]) == chash.end()) continue;

			count[s[i]] = 0;

			if (checkAppear()) updateMin(i);

		}


		if (checkAppear()) res = s.substr(idx - min, min + 1);
		else res = "";
		return res;
	}
};

void reset(int hash[]){

	for (int i = 0; i < 128; i++){

		hash[i] = -1;
	}
}

void setCheckList(int* check, char* T){
	
	for (int i = 0; i < 128; i++) check[i] = -1;

	for (int i = 0; i < strlen(T); i++){
	
		if (check[T[i]] == -1) check[T[i]] = 1;
		else check[T[i]]++;
	}
}

void updateCount(int hash[]){

	for (int i = 0; i < 128; i++){

		if (hash[i] != -1) hash[i]++;
	}
}

void updateMin(int* hash, int* idx, int* idxTmp, int* min, int len){

	int tmpMax = -1;
	int tmpMin = 65536;

	for (int i = 0; i < 128; i++){

		if (hash[i] > tmpMax) tmpMax = hash[i];
	}

	for (int i = 0; i < 128; i++){

		if (hash[i] != -1 && hash[i] < tmpMin) tmpMin = hash[i];
	}

	if ((tmpMax - tmpMin) < *min) {
		*min = tmpMax - tmpMin;
		*idx = *idxTmp;
	}
}

bool checkAppear(int* hash, int* list){

	for (int i = 0; i < 128; i++){

		if (list[i] == -1) continue;
		if (list[i]) return false;
		if (hash[i] == -1) return false;
	}

	return true;
}

char *minWindow(char *S, char *T) {

	int hash[128];
	int checkList[128] = { 0 }, equal = true;

	reset(hash);

	int min;

	if (S[0] == '\0') return "";
	if (T[0] == '\0') return "";
	if (strlen(T) > strlen(S)) return "";

	if (strlen(T) == strlen(S)){

		for (int i = 0; i < strlen(T); i++)
			if (T[i] != S[i]) {
				equal = false;
				break;
			}
		if (equal) return T;
	}

	char* res;

	min = (1 << 31) - 1;

	int idx = 0, idxMin = 0;

	setCheckList(checkList, T);

	for (; S[idx] != '\0'; idx++){

		updateCount(hash);

		if (checkList[S[idx] - '\0'] == -1) continue;

		if (checkList[S[idx] - '\0']>0)checkList[S[idx] - '\0']--;

		if (!checkList[S[idx] - '\0']) hash[S[idx] - '\0'] = 0;
		     
		if (checkAppear(hash, checkList)) 
			updateMin(hash, &idxMin, &idx, &min, strlen(T));
	}

	if (!checkAppear(hash, checkList)) return "";

	res = (char*)malloc((min + 1)*sizeof(char));

	memcpy(res, S + idxMin - min, (min + 1)*sizeof(char));

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s[] = "acbbaca";
	char T[] = "aba";
	char* res = minWindow(s, T);

	//string s = Solution().minWindow("bbaa", "aba");
	return 0;
}

