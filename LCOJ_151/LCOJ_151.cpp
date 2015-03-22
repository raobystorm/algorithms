// LCOJ_151.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

inline void swap(char* s, int i, int j){

	char c = s[i];
	s[i] = s[j];
	s[j] = c;
}

inline void reverse(char* s, int start, int end){

	for (int i = 0; i < end; i++){
	

	}
}

void reverseWords(char *s) {

	if (strlen(s) <= 1) return;

	for (int i = 0; i < (strlen(s) - 1) / 2; i++)
		swap(s, i, strlen(s) - i - 1);

	int head = 0;
	for (int i = 0; i < strlen(s); i++){
	
		if (s[i] != ' ') continue;
		
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

