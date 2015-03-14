// LCOJ_189.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <utility>

using namespace std;

class Solution {
public:

	void swap(int* a, int* b){
	
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}

	void roundShift(int nums[], int n, int k){
		if (k > 0){

			int t0 = nums[0], t1 = nums[k%n], i = 0, m = n;
			while (m--){
				nums[(i + k) % n] = t0;
				t0 = t1;
				i = (i + k) % n;
				t1 = nums[(i + k) % n];
			}
		}
		else{

			int t0 = nums[0], t1 = nums[k%n], i = 0, m = n;
			while (m--){
				nums[(n + k) % n] = t0;
				t0 = t1;
				i = (n + k) % n;
				t1 = nums[(n + k) % n];
			}
		}
	}

	// judge if there is a common divisor of n and k
	bool haveGCD(int n, int k){
	
		if (n == k) return true;
		if (n < k) swap(&n, &k);
		if (!(n % k)) return true;
		for (int i = 2; i < k; i++)
			if ((!(n%i)) && (!(k%i))) return true;

		return false;
	}

	void rotate(int nums[], int n, int k) {
		
		if (!k) return;
		if (k < 0) k = n + k;
		if (!haveGCD(n, k)) {
			// If k is a divisor of n, we need to change strategy here
			roundShift(nums, n, k);
		}
		else while (k--) roundShift(nums, n, 1);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	int nums[6] = { 1, 2, 3, 4, 5, 6 };

	s.rotate(nums, 6, 4);
	return 0;
}

