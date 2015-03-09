// POJ_1067.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0, b = 0;
	double r = (1 + sqrt(5.0)) / 2;

	while (scanf_s("%d %d", &a, &b)!=EOF){

		if (a > b) swap(a, b);
		int idx = b - a;

		if (a == int(idx * r)) printf("0\n");
		else printf("1\n");
	}

	return 0;
}

