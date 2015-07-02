// Recruit_Screening.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, q;
	vector<int> s(n, 0);
	vector<int> k(q, 0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> k[i];
	}

	return 0;
}