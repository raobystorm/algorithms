// LCOJ_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <fstream>

using namespace std;

#define MAX			100000

int A[MAX], B[MAX] = { 0 };

class Solution {
public:

	double findMedianOneArray(int A[], int n, int m, bool left){
	
		if (left){
		
			if ((m + n) % 2) return A[(m + n) / 2 - m] * 1.0;
			else return A[(m + n) / 2 - m] * 1.0 - A[(m + n) / 2 - m - 1] * 1.0 + A[(m + n) / 2 - m - 1] * 1.0;
		}
		else{
		
			if ((m + n) % 2) return A[(m + n) / 2]*1.0;
			else return (A[(m + n) / 2 + 1] * 1.0 - A[(m + n) / 2] * 1.0) / 2 + A[(m + n) / 2] * 1.0;
		}
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {

		int idxA = m, idxB = n, offset = (m > n)? (n>>1):(m>>1);
		if (m == 0) { return (n % 2) ? B[n / 2] : ((B[n / 2] - B[n / 2 - 1])*1.0 / 2 + B[n / 2 - 1]); }
		if (n == 0)	{ return (m % 2) ? A[m / 2] : ((A[m / 2] - A[m / 2 - 1])*1.0 / 2 + A[m / 2 - 1]); }

		if (A[idxA >>= 1] >= B[idxB >>= 1]){
			// the greater side is A for now
			while ((A[idxA - offset>>1] >= B[idxB + offset>>1])){

				if (offset <= 1) break;

				if (idxA - offset > 0) idxA -= offset;
				else if(m != n){

					// reach the edge of A
					return findMedianOneArray(B, m, n, false);
				}

				if (idxB + offset < n-1) idxB += offset;
				else{
					
					// reach the edge of B
					return findMedianOneArray(A, n, m, true);
				}
				offset >> 1;
			}
			if ((m + n) % 2){

				// TODO: this problem needs so much consideration...
			}
			else{
			
				int res[4];	//candicates
				res[0] = A[idxA];
				if (idxA - offset >= 0)res[1] = A[idxA - offset];
				else res[1] = A[idxA + offset];
				res[2] = B[idxB];
				if (idxB + offset < n)res[3] = B[idxB + offset];
				else res[3] = B[idxB - offset];
				sort(res, res + 4);
				return (res[2] * 1.0 - res[1] * 1.0) / 2 + res[1] * 1.0;
			}
			
		}
		else return findMedianSortedArrays(B, n, A, m);
	}
};

int main()
{
	ifstream input("in.txt");
	ofstream output("out.txt");

	int m, n;

	input >> m;

	for (int i = 0; i < m; i++)
		input >> A[i];

	input >> n;

	for (int i = 0; i < n; i++)
		input >> B[i];

	Solution s;
	double res = s.findMedianSortedArrays(A, m, B, n);

	output << res;

	return 0;
}

