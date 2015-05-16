// LCOJ_206.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

class rectangle{
public:
	long long xmin, ymin, xmax, ymax;
};

void swap(int& a, int& b){ int tmp = a; a = b; b = tmp; }

// Check if two rect is overlapped, return the overlap part or NULL
rectangle* interPart(rectangle& r1, rectangle& r2){

	if (r1.xmin == r1.xmax || r1.ymin == r1.ymax || r2.xmin == r2.xmax || r2.ymin == r2.ymax) return NULL;

	rectangle *left = r1.xmin < r2.xmin ? &r1 : &r2;
	rectangle *right = (&r1) == left ? &r2 : &r1;
	rectangle *top = r1.ymin > r2.ymin ? &r1 : &r2;
	rectangle *bottom = (&r1) == top ? &r2 : &r1;

	if (left->xmax < right->xmin) return NULL;
	if (top->ymin > bottom->ymax) return NULL;

	// Intersect here
	rectangle *interRect = new rectangle();
	interRect->xmin = right->xmin;
	interRect->xmax = left->xmax;
	interRect->ymax = bottom->ymax;
	interRect->ymin = top->ymin;

	return interRect;
}

int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {
	// write your code in C++11
	rectangle r1, r2;
	long long sum = 0;

	// if illegal input
	if (K > M) swap(K, M);
	r1.xmin = K; r1.xmax = M;
	if (L > N) swap(L, N);
	r1.ymin = L; r1.ymax = N;
	if (P > R) swap(P, R);
	r2.xmin = P; r2.xmax = R;
	if (Q > S) swap(Q, S);
	r2.ymin = Q; r2.ymax = S;

	rectangle* inters = interPart(r1, r2);

	if (inters == NULL) {
		sum += (r1.xmax - r1.xmin) * (r1.ymax - r1.ymin);
		sum += (r2.xmax - r2.xmin) * (r2.ymax - r2.ymin);
	}
	else{
		sum += (r1.xmax - r1.xmin) * (r1.ymax - r1.ymin);
		sum += (r2.xmax - r2.xmin) * (r2.ymax - r2.ymin);
		sum -= (inters->xmax - inters->xmin) * (inters->ymax - inters->ymin);
	}

	// TODO: if sum is over range of int...
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int res = solution(-4, 1, 2, 6, 0, -1, 4, 3);
	return 0;
}

