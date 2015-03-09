

#include "stdafx.h"
#include "BigNum.h"

int _tmain(int argc, _TCHAR* argv[])
{

	BigNum n1, n2, n3, n4, n5;
	n1 = BigNum(double(13245.4654));
	n2 = BigNum(double(0.000143564));

	n3 = BigNum(double(-00.13601435000));

	n4 = BigNum("-000.00123132000");
	n5 = BigNum("-00561610.001656000");

	return 0;
}

