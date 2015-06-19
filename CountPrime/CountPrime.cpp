// CountPrime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAX 1500000

#include <fstream>
using namespace std;

void countPrime(){

	ofstream output("output.txt");

	char* bset = (char*)malloc(MAX);
	memset(bset, 0, MAX);
	int res = 0;
	for (int i = 2; i <= MAX - 1; i++){
		if (bset[i] == 1) { 
			output << res << ", ";
			continue; 
		}
		res++;
		output << res << ", ";
		for (int j = 2; j <= (MAX - 1) / i; j++)
			bset[i*j] = 1;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	countPrime();
	return 0;
}

