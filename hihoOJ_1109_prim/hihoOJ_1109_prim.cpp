// hihoOJ_1109_prim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct edge{
	int des;
	short w;
	edge(int j, int k) : des(j), w(k){}
	bool operator<(const edge& e2) const{
		return w > e2.w;
	}
};

int main()
{
	int n, m, tmp, i, res, j, k, count;
	while (~scanf_s("%d%d", &n, &m)){
		res = 0;
		count = 1;
		vector<bool> visited(n, false);
		// the first elem of the pair is the destination of this edge, second is the weight
		unordered_map<int, vector<edge>> map;
		// use min heap to store the active edges we are searching
		priority_queue<edge> edges;

		for (k = 0; k < m; k++){
			scanf_s("%d%d%d", &i, &j, &tmp);
			i--; j--;
			if (map.find(i) == map.end()) map[i] = vector<edge>();
			if (map.find(j) == map.end()) map[j] = vector<edge>();
			map[i].push_back(edge(j, tmp));
			map[j].push_back(edge(i, tmp));
		}

		i = 0;
		visited[i] = true;
		while (count < n){
			// search the minimum edge that connects a visited vertice with an unvisited one
			for (auto j : map[i]){
				//if (!visted[j]) edges.push(edge(j, vedge[i][j]));
				if (!visited[j.des]) edges.push(j);
			}
			while (visited[edges.top().des]) {
				edges.pop();
			}

			res += edges.top().w;
			i = edges.top().des;
			visited[i] = true;
			edges.pop();
			count++;
		}
		cout << res << endl;
	}
	
	return 0;
}