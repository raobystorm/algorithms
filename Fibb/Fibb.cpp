// Fibb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

const int m = 19999997;

class matrix
{
public:
	matrix();
	__int64 data[2][2];
	matrix operator *(const matrix &rig);
	matrix & operator =(const matrix &rig);
};

matrix::matrix()
{
	data[0][0] = 1;
	data[0][1] = 1;
	data[1][0] = 1;
	data[1][1] = 0;
}

matrix matrix::operator *(const matrix &rig)
{
	matrix ans;
	ans.data[0][0] = (data[0][0] * rig.data[0][0] + data[0][1] * rig.data[1][0]);
	ans.data[0][1] = (data[0][0] * rig.data[0][1] + data[0][1] * rig.data[1][1]);
	ans.data[1][0] = (data[1][0] * rig.data[0][0] + data[1][1] * rig.data[1][0]);
	ans.data[1][1] = (data[1][0] * rig.data[0][1] + data[1][1] * rig.data[1][1]);
	return ans;
}

matrix &matrix::operator =(const matrix &rig)
{
	for (int i = 0; i <= 1; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			data[i][j] = rig.data[i][j];
		}
	}
	return *this;
}

int main()
{
	long n;
	cin >> n;
	matrix k, ans;
	while (n>0)
	{
		if (n % 2 == 1)
		{
			ans = ans*k;
		}
		k = k*k;
		n = n / 2;
	}
	cout << (ans.data[1][1] % 19999997) << endl;
	system("pause");
	return 0;
}
