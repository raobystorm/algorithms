// TowerOfHanoi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <unordered_set>
using namespace std;

inline int moveRecur(int n){

	if (n == 1) return 1;
	return 2 * moveRecur(n - 1) + 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int hash1[26] = { 0 }, hash2[26] = { 0 };
	hash1[0]++; hash1[2]++;
	hash2[0]++; hash2[2]++;

	unordered_set<int *> s;
	s.insert(hash1);
	//s.insert(hash2);

	if (s.find(hash2) == s.find(hash1)){
	
		return 1;
	}
	else return 0;
}

