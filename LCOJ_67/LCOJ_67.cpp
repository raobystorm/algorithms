// LCOJ_67.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

string addBinary(string a, string b)
{
	string s = "";

	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || c == 1)
	{
		c += i >= 0 ? a[i--] - '0' : 0;
		c += j >= 0 ? b[j--] - '0' : 0;
		s = char(c % 2 + '0') + s;
		c /= 2;
	}

	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string res = addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011");
	return 0;
}

