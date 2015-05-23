// LCOJ_207.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> 
#include <unordered_set>
#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:

	bool marked[2001];
	int num;

	bool dfs(int n, vector<list<int>>& graph){

		if (marked[n]) return false;

		marked[n] = true;
		for (auto i = graph[n].begin(); i != graph[n].end(); i++)
			if (!dfs(*i, graph)) return false;

		marked[n] = false;

		return true;
	}

	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

		num = numCourses; 
		vector<list<int>> graph = vector<list<int>>(numCourses, list<int>());
		memset(marked, 0, sizeof(bool) * num);

		if (numCourses <= 1) return true;

		for (int i = 0; i < prerequisites.size(); i++){

			graph[prerequisites[i].first].push_back(prerequisites[i].second);
		}

		// Topological sort with DFS to detect if there is a cycle in the graph
		for (int i = 0; i < num; i++){
			if(!dfs(i, graph)) return false;
		}

		return true;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	pair<int, int> p1, p2, p3;
	p1.first = 0; p1.second = 1;
	p2.first = 0; p2.second = 2;
	p3.first = 1; p3.second = 2;
	vector<pair<int, int>> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);

	bool res = Solution().canFinish(3, vec);
	return 0;
}

