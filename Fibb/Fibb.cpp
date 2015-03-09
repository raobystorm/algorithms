// Fibb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "windows.h"

using namespace std;

inline __int64 Fibb(int n){

	if (n == 0) return 0;
	if (n == 1) return 1;

	__int64 a, b, res;
	a = 1;
	b = 0;
	res = 0;

	for (int i = 2; i <= n; i++){
	
		res = a + b;
		b = a;
		a = res;
	}

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	__int64 res = 0;
	int n = 0;
	DWORD start, stop;

	while (1){

		_wsystem(L"CLS");

		cout << "Please input the number to calculate for Fibonacci: \n";
		cin >> n;
		if (n < 0) break;
		
		start = GetTickCount();
		res = Fibb(n);
		stop = GetTickCount();

		cout << "The result is " << res << ", calculated in " << (stop - start) * 1.0 / 1000 << " secs.\n";

		_wsystem(L"pause");

	}

	_wsystem(L"pause");

	return 0;
}

