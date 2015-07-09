// hihoOJ_1050.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

struct node{
	int val;
	bool visited;
	int first, second;
	vector<node*> near;
	node(int k = -1) : val(k), near(vector<node*>()), first(0), second(0), visited(false){}
	// for current node, count the maximum first values from all neighbours
	// put 2 largest into the input param
	void Max(int& f, int& s){
		for (int i = 0; i < near.size(); i++){
			if (near[i]->first + 1 > first){
				if(near.size() > 2)second = first;
				first = near[i]->first + 1;
			}
			else if (near[i]->first + 1 > second){
				second = near[i]->first + 1;
			}
		}
		if (first + second > f + s){
			f = first;
			s = second;
		}
	}
};

int main()
{
	int n, tmpf = 0, tmps = 0;
	node* curr;
	cin >> n;
	unordered_map<int, node*> vert;
	stack<node*> stk;
	// input the graph data
	for (int i = 0; i < n-1; i++){
		int k, j;
		scanf_s("%d%d", &k, &j);
		if (vert.find(k) == vert.end())	vert[k] = new node(k);
		if (vert.find(j) == vert.end())	vert[j] = new node(j);
		vert[k]->near.push_back(vert[j]);
		vert[j]->near.push_back(vert[k]);
	}

	stk.push(vert.begin()->second);
	vert.clear();
	// traversal the graph
	while (!stk.empty()){
		// use a stack to track current node
		curr = stk.top();
		// we count 2 longest paths through this node
		// if this node has been visited or it is a leaf node, pass
		if (curr->visited) { stk.pop(); continue; }
		if (curr->near.size() <= 1) { 
			stk.pop(); 
			curr->visited = true; 
			stk.push(curr->near[0]);
			continue; 
		}
		// for all the neighbours of current node
		// push all its unvisited neighbours into the stack, update two max values
		// we need to track which node is the parent, in case of dead lock
		bool all = true;
		for (int i = 0; i < curr->near.size(); i++){
			if (vert.find(curr->near[i]->val) == vert.end() && !curr->near[i]->visited) {
				all = false;
				stk.push(curr->near[i]);
			}
		}
		// if all child has been visited, then the longest paths are correct
		if(all){
			curr->visited = true;
			stk.pop();
			curr->Max(tmpf, tmps);
		}
		else{
			vert[curr->val] = curr;
		}
	}
	cout << tmpf + tmps << endl;
	
	return 0;
}