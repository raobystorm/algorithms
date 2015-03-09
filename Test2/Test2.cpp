// Test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	int n = 0, num;
	fstream file("task-1-in.txt");
	ofstream output("output1.txt");

	file >> n;
	int xu, yu, x, y, idx = 1;
	double min = 3000;

	for (int i = 0; i < n; i++){
	
		min = 3000;
		file >> xu >> yu;
		file >> num;
		for (int j = 0; j < num; j++){
			file >> x >> y;
			double dis = sqrt((xu - x)*(xu - x) + (yu - y)*(yu - y));
			if (dis < min){
			
				min = dis;
				idx = j;
			}
		}

		output << "Case #" << i + 1 << " " << idx + 1 << " " << min << endl;
	}

	return 0;
}
