// POJ_1003.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

int main()
{
	double d;
	double nums[280];

	nums[0] = 0.0;

	for (int i = 1; i < 280; i++){
	
		nums[i] = nums[i - 1] + 1 / ((i+1) * 1.0);
	}

	while (cin >> d && d != 0.0){
	
		for (int i = 1; i < 280; i++){

			if (nums[i] > d) { 
				printf("%d card(s)\n", i); 
				break;
			}
		}
	}
	return 0;
}

