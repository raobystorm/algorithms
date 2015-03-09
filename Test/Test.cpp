// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "iostream"

using namespace std;

void StringPermute(std::string& s, int i){

	int j = i;

	if (j == s.length() - 1)
		std::cout << s << "\n";

	for (; j <= s.length() - 1; j++){

		swap(s[i], s[j]);
		StringPermute(s, i + 1);
		swap(s[i], s[j]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string ss;

	while (1){
	
		_wsystem(L"cls");

		std::cout << "Please input the string to permute:\n";

		std::cin >> ss;

		if (ss == "exit") return 0;

		StringPermute(ss, 0);

		_wsystem(L"pause");
	}

	return 0;
}

