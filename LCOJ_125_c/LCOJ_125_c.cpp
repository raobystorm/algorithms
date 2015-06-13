// LCOJ_125_c.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"

bool checkLegal(char* c){
	return (*c >= 'a' && *c <= 'z') || (*c >= 'A'&&*c <= 'Z') || (*c >= '0' && *c <= '9');
}
bool checkEqual(char* c1, char* c2){
	if (*c1 == *c2) return true;
	if (*c1 + 'a' - 'A' == *c2) return true;
	if (*c1 - ('a' - 'A') == *c2) return true;
	return false;
}
bool isPalindrome(char* s) {

	if (strlen(s) == 0) return true;
	int len = strlen(s);
	int j = strlen(s) - 1;
	for (int i = 0; i <= j; i++, j--){

		while (!checkLegal(&s[i]) && i<len) i++;
		while (!checkLegal(&s[j]) && j >= 0) j--;
		if (!checkEqual(&s[i], &s[j])) return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

