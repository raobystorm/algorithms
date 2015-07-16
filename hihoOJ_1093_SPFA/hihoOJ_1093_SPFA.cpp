// hihoOJ_1093_SPFA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;
#define INT_MAX 2147483647

struct edge{
	int e, next; 
	short w; 
	edge(int ee = 0, int ww = 0, int nn = -1) :e(ee), w(ww), next(nn){}
};

void add(vector<edge>& edges, vector<int>& head, int u, int v, int w, int i){
	edges[i].e = v;
	edges[i].w = w;
	// set the next edge to the first elem of head[u]
	// connects all the edges going out from node u together
	edges[i].next = head[u];
	head[u] = i;
}
// main body of SPFA
void spfa(vector<edge>& edges, vector<int>& dis, vector<int>& head, int s){

	queue<int> q;
	// use a bool vector to specify whether the node is in the queue or not
	vector<bool> vis(head.size(), false);

	dis[s] = 0;
	q.push(s);
	vis[s] = true;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		// search all the edges going out from node u
		for (int i = head[u]; i != -1; i = edges[i].next){
			int v = edges[i].e;
			if (dis[u] + edges[i].w < dis[v]){
				dis[v] = dis[u] + edges[i].w;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main()
{
	int n, m, s, t, x, y, w;
	cin >> n >> m >> s >> t;
	vector<edge> edges(m*2);
	vector<int> dis(n + 1, INT_MAX);
	// vector"head" is used for saving the index of "edges"
	// head[u] is the index of the first edge going out from node u
	vector<int> head(n + 1, -1);

	for (int i = 0; i < 2*m; i++){
		scanf_s("%d%d%d", &x, &y, &w);
		add(edges, head, x, y, w, i++);
		add(edges, head, y, x, w, i);
	}

	spfa(edges, dis, head, s);

	cout << dis[t] << endl;
	return 0;
}
