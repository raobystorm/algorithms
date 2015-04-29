// TestMS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX 100000

struct Node{
	int x, y;
	Node() :x(0), y(0){}
}Nodes[MAX];
// void* is the point
int cmpx(const void* a, const void* b){

	int *n1 = (int*)a;
	int *n2 = (int*)b;

	if (Nodes[*n1].x != Nodes[*n1].x) return Nodes[*n1].x - Nodes[*n1].x;
	else return (Nodes[*n1].y - Nodes[*n1].y);
}

int cmpy(const void* a, const void* b){

	int *n1 = (int*)a;
	int *n2 = (int*)b;

	if (Nodes[*n1].y != Nodes[*n1].y) return Nodes[*n1].y - Nodes[*n1].y;
	else return Nodes[*n1].x - Nodes[*n1].x;
}

int main(int argc, char *argv[])
{
	
	int n;
	int xArray[MAX], yArray[MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; i++){

		int x, y;
		scanf("%d%d", &x, &y);
		Nodes[i].x = x;
		Nodes[i].y = y;

		qsort(xArray, n, sizeof(int), )
	}
	return 0;
}
