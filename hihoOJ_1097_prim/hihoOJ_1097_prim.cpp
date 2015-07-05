// hihoOJ_1097_prim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct edge{
	short start, des;
	short w;
	edge(int i, int j, int k) : start(i), des(j), w(k){}
};

class comp{
public:
	bool operator()(const edge& e1, const edge& e2){
		return e1.w > e2.w;
	}
};

int main()
{
	int n, tmp, i, res = 0, j;
	cin >> n;
	unordered_set<int> visted;
	vector<vector<short>> vedge(n, vector<short>(n, 0));
	// use min heap to store the active edges we are searching
	priority_queue<edge, vector<edge>, comp> edges;
	
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf_s("%d", &tmp);
			vedge[i][j] = tmp;
		}
	}
	i = 0;
	visted.insert(i);
	while (visted.size() < n){
		// search the minimum edge that connects a visited vertice with an unvisited one
		for (j = 0; j < n; j++){
			if(visted.find(j) == visted.end()) edges.push(edge(i, j, vedge[i][j]));
		}
		while (visted.find(edges.top().des) != visted.end()) {
			edges.pop();
		}

		res += edges.top().w;
		i = edges.top().des;
		visted.insert(i);
		edges.pop();
	}
	cout << res << endl;
	return 0;
}

