// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

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

inline void reverse(string& s, int i, int j){

	while (i < j){
		swap(s[i++], s[j--]);
	}
}

void combination(string& s, int len){

	sort(s.begin(), s.end());
	while (true){
	
		cout << s << endl;
		int i, j;
		for (i = s.size() - 2; i >= 0; i--){
		
			if (s[i] < s[i + 1]) break;
			else if (i == 0) return;
		}
		for (j = s.size() - 1; j > i; j--){
			if (s[j] > s[i]) break;
		}
		swap(s[i], s[j]);
		reverse(s, i+1 ,s.size() - 1);
	}
}

template<typename _elem>
void reverse(_elem* array, int i, int j){
	while (i < j){
		swap(array[i++], array[j--]);
	}
}

template<typename _itr>
void comb(_itr* _array, int len){

	sort(&(_array[0]), &(_array[len - 1]));
	while (true){
	
		{
			for (int i = 0; i < len; i++)
				cout << _array[i] << " ";
			cout << endl;
		}
		int i, j;
		for (i = len - 2; i >= 0; i--){
		
			if (_array[i] < _array[i + 1]) break;
			else if (i == 0) return;
		}
		for (j = len - 1; j > i; j--){
			if (_array[j] > _array[i]) break;
		}
		swap(_array[i], _array[j]);
		reverse(_array, i + 1, len - 1);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::string ss;
	int* vec;
	int n, tmp;

	while (1){
	
		_wsystem(L"cls");

		/*std::cout << "Please input the string to permute:\n";

		std::cin >> ss;

		if (ss == "exit") return 0;*/

		cin >> n;
		vec = (int*)malloc(sizeof(int)*n);
		
		for (int i = 0; i < n; i++)
			cin >> vec[i];

		comb(vec, n);

		_wsystem(L"pause");
	}

	return 0;
}

