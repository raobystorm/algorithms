// POJ_1002.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <algorithm>
#include <iostream>

#define MAX				110000
#define MAX_LEN			1000	

using namespace std;

inline int map(const char* c){

	if (*c == '0') return 0;
	if (*c == '1') return 1;
	if (*c == 'A' || *c == 'B' || *c == 'C' || *c == '2') return 2;
	if (*c == 'D' || *c == 'E' || *c == 'F' || *c == '3') return 3;
	if (*c == 'G' || *c == 'H' || *c == 'I' || *c == '4') return 4;
	if (*c == 'J' || *c == 'K' || *c == 'L' || *c == '5') return 5;
	if (*c == 'M' || *c == 'N' || *c == 'O' || *c == '6') return 6;
	if (*c == 'P' || *c == 'R' || *c == 'S' || *c == '7') return 7;
	if (*c == 'T' || *c == 'U' || *c == 'V' || *c == '8') return 8;
	if (*c == 'W' || *c == 'X' || *c == 'Y' || *c == '9') return 9;

	return -1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0, count = 0, k = 0;
	scanf_s("%d", &n);
	char sin[MAX_LEN] = { '\0' };
	bool match = false;
	int number;
	int nums[MAX] = {0};

	getchar();

	for (int i = 0; i < n; i++){
	
		gets_s(sin);
		for (int j = 0; sin[j] && j < MAX_LEN; j++){
		
			if (map(&sin[j]) == -1) continue;
			nums[i] *= 10;
			nums[i] += map(&sin[j]);
		}
	}

	sort(nums, nums + n);

	for (int i = 1,j; i < n;){

		if (nums[i - 1] != nums[i]) { i++; continue; }
		if (!match) match = true;
		count = 2;
		for (j = i+1; j < n; j++){
			if (nums[j] == nums[j - 1]) count++;
			else break;
		}
		printf("%03d-%04d %d\n",nums[i-1]/10000, nums[i-1]%10000, count);
		i = j;
	}

	if (!match) printf_s("No duplicates.\n");

	return 0;
}

