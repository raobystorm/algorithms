// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

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

// a method for all combinations without duplicates
template<typename _iter>
void combination(_iter _array, int len){

	if (len < 2) return;

	bool end = false;
	while (true){

		for (int i = 0; i < len; i++)
			cout << _array[i] << " ";
		cout << endl;

		int i, j;
		for (i = len - 2; i >= 0; i--){
			if (_array[i] < _array[i + 1]) break;
			else if (i == 0) return;
		}

		for (j = len - 1; j > i; j--){
			if (_array[j] > _array[i])break;
		}
		swap(_array[i], _array[j]);
		for (int k = i + 1, l = len - 1; k < l; k++, l--)
			swap(_array[k], _array[l]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string ss;
	vector<int> vec;
	int n, tmp;

	while (1){
	
		_wsystem(L"cls");

		/*std::cout << "Please input the string to permute:\n";

		std::cin >> ss;

		if (ss == "exit") return 0;*/

		cin >> n;
		vec.clear();
		for (int i = 0; i < n; i++){
			
			cin >> tmp;
			vec.push_back(tmp);
		}

		sort(vec.begin(), vec.end());
		combination(vec, n);

		_wsystem(L"pause");
	}

	return 0;
}

