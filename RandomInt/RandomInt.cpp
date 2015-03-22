// RandomInt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <fstream>
#include "time.h"

inline int rnd(int& min, int& max){
	double d = rand()*1.0 / RAND_MAX;
	return (max-min)*d;
}

inline void swap(int ints[], int& a, int& b){

	int tmp = ints[a];
	ints[a] = ints[b];
	ints[b] = tmp;
}
// generate random int value from 1 to N
void RandomInt(int ints[], int n){

	srand(time(NULL));

	for (int i = 0; i < n; i++){
	
		ints[i] = i;
	}

	for (int i = 0; i < n - 1; i++){

		int t = rnd(i, n);
		swap(ints, i, t);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::ofstream fout("random.txt");
	int ints[100000];
	RandomInt(ints, 100000);
	for (int i = 0; i < 100000; i++)
		fout << ints[i] << " ";
	return 0;
}

