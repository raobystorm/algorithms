// TestData.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	srand(time(NULL));

	ofstream fout("out.txt");

	int n = 500000;

	fout << n << " ";

	for (int i = 0; i < n; i++){
	
		fout << (int)rand() << " ";
	}

	fout << endl << 0;
}

