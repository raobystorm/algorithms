// hihoOJ_1098_Kruscal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <bitset>
#include <iostream>

using namespace std;
// use union find set to combine the nodes
int find(vector<int>& v, int n){
	if (v[n] == n) return v[n];
	v[n] = find(v, v[n]);
	return v[n];
}

void Union(vector<int>& v, int i, int j){
	if (v[i] == v[j]) return;
	v[find(v, i)] = find(v, j);
}
// check if all nodes are in the same group
bool allSet(vector<int>& v){
	int tmp = v[0];
	for (auto i : v){
		if (tmp != i) return false;
		tmp = i;
	}
	return true;
}

struct edge{
	int start, end;
	short weight;
	edge(int s = -1, int e = -1, int w = -1) :start(s), end(e), weight(w){}
	bool operator<(const edge& e2) const{ return weight > e2.weight; }
};

int main()
{
	int n, m, res = 0;
	cin >> n >> m;
	vector<int> nodes(n);
	// use a min heap to store shortest edges
	priority_queue<edge> q;
	edge* curr;
	// read the edges in
	for (int i = 0; i < m; i++){
		int s, e, w;
		scanf_s("%d%d%d", &s, &e, &w);
		s--; e--;
		q.push(edge(s, e, w));
		q.push(edge(e, s, w));
	}
	// initialize the vertex
	for (int i = 0; i < n; i++) nodes[i] = i;
	// main body of kruscal
	while (!q.empty() && !allSet(nodes)){
		
		curr = (edge*)&q.top();
		// get the shortest edge, check if its two vertex is in the same group or not
		// if not, union these two group into spanning tree
		int f1 = find(nodes, curr->start), f2 = find(nodes, curr->end);
		if (f1 != f2){
			res += curr->weight;
			Union(nodes, curr->start, curr->end);
		}
		q.pop();
	}
	cout << res << endl;

	return 0;
}