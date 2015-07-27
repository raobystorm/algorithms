// hihoOJ_1138.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct node{
	int x, y;
	node(int xx = 0, int yy = 0) :x(xx), y(yy){}
};

int main()
{
	int n, x, y;
	cin >> n;
	vector<node> nodes(n);
	
	for (int i = 0; i < n; i++){
		scanf_s("%d%d", &nodes[i].x, &nodes[i].y);
	}

	return 0;
}