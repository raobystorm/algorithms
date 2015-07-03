// hihoOJ_1150_MaxHeap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	char c;
	int tmp;
	priority_queue<int> q;
	for (int i = 0; i < n; i++){
		cin >> c;
		if (c == 'A') { 
			cin >> tmp;
			q.push(tmp); 
		}
		else {
			cout << q.top() << endl;
			q.pop();
		}
	}
	return 0;
}

