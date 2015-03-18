// LCOJ_76.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_set>
#include <unordered_map>
#include <stdlib.h>

using namespace std;
/*
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
};*/


void setCheckList(bool check[], int list[], char* T){

	for (int i = 0; i < strlen(T); i++){

		list[T[i] - 'a']++;
		check[T[i] - 'a'] = true;
	}
}

bool checkLeftMove(int list[], bool check[]){

	for (int i = 0; i < 26; i++){
	
		if (!check[i]) continue;
		else if (list[i]>0) return false;
	}
	return true;
}

bool checkList(int list[], bool check[]){

	for (int i = 0; i < 26; i++){
	
		if (!check[i]) continue;
		if (list[i] > 0) return false;
	}
	return true;
}

char *minWindow(char *S, char *T) {

	int list[26] = { 0 };
	bool equal = true, moveLeft = false, check[26] = {false};

	int min, left = 0, right = 0, idx;

	if (!strlen(S)) return "";
	if (!strlen(T)) return "";
	if (strlen(T) > strlen(S)) return "";

	if (strlen(T) == strlen(S)){

		for (int i = 0; i < strlen(T); i++)
			if (T[i] != S[i]) {
				equal = false;
				break;
			}
		if (equal) return T;
		else return "";
	}

	char* res;

	min = 1 << 30;

	setCheckList( check, list, T);

	for (; left < strlen(S) && right < strlen(S); moveLeft?left++:right++){

		if (!moveLeft){
		
			if (!check[S[right] - 'a']) continue;
			list[S[right] - 'a']--;
			if (checkLeftMove(list, check)){
			
				if (min > right - left){

					min = right - left;
					idx = left;
				}
				
				moveLeft = true;
			}
		}
		else{
		
			if (check[S[left - 1] - 'a']) list[S[left - 1] - 'a']++;
			if (check[S[left] - 'a']) {
			
				if (list[S[left] - 'a'] < 0) continue;
				if (checkList(list, check) && min > right - left){

					min = right - left;
					idx = left;
				}

				moveLeft = false;
			}
		}
	}

	if (min > strlen(T)) return "";

	res = (char*)malloc((min + 1)*sizeof(char));

	memcpy(res, S + idx, (min + 1)*sizeof(char));

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s[] = "ab";
	char T[] = "";
	char* res = minWindow(s, T);

	//string s = Solution().minWindow("bbaa", "aba");
	return 0;
}

