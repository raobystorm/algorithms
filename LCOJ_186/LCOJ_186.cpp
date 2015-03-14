// LCOJ_186.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <memory>

#define MAX		1024

int lengthOfLongestSubstring(char *s) {

	int map[MAX] = { 0 };

	char c = s[0];
	int res = 0, i = 0, max = 0;

	while (c != '\0'){

		if (map[c - '\0'] == 0) {
			map[c - '\0'] = i + 1;
			res++;
			if (res > max)max = res;
			i++;
			c = s[i];
			continue;
		}

		if (res > max) max = res;
		res = 0;
		i = map[c - '\0'];
		memset(map, 0, MAX * sizeof(int));
		c = s[i];
	}

	return max;
}

int main()
{
	int res = lengthOfLongestSubstring("");
	return 0;
}

