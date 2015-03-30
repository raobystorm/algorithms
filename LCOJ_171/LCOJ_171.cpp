// LCOJ_171.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

int titleToNumber(char *s) {

	int len = strlen(s);
	int res = 0, digit = 1;
	for (int i = len - 1; i >= 0; i--){
		
		res += ((s[i] - 'A') + 1) * digit;
		digit *= 26;
	}
	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = titleToNumber("AAA");
	return 0;
}

