// LCOJ_60.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	void reverse(string& v, int i, int j){
		while (i < j){ swap(v[i++], v[j--]); }
	}
	string getPermutation(int n, int k) {

		string a;
		if (n <= 1) return "1";

		for (int i = 0; i < n; i++){
			a += i + '1';
		}
		int count = 1;
		while (true){

			if (count == k) return a;

			int i, j;
			for (i = a.size() - 2; i >= 0; i--){
				if (a[i] < a[i + 1]) break;
			}

			for (j = a.size() - 1; j > i; j--){
				if (a[j] > a[i]) break;
			}
			swap(a[i], a[j]);
			reverse(a, i + 1, a.size() - 1);
			count++;
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	string s = Solution().getPermutation(8, 8590);
	return 0;
}

