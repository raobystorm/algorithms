// hihoOJ_1041_dfs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
struct node{
	int val;
	bool visited;
	vector<int> near;
	node(int i = 0) :val(i), visited(false), near(vector<int>()){}
};
// is all the neighbours of this node have been visited
bool allVisit(unordered_map<int, node*>& nodes, int i){
	node* curr = (nodes[i]);
	for (auto j : curr->near){
		if (!nodes[j]->visited) return false;
	}
	return true;
}
// check if we cyclic these two lists, all the elems are in the same order
bool checkOrder(list<int>& l1, list<int>& l2){
	unordered_set<int> s;
	bool start = false;
	for (auto i : l2)
		s.insert(i);
	list<int>::iterator itr1 = l1.begin(), itr2 = l2.begin();
	while (itr2 != l2.end()){
		if (*itr1 == *itr2){
			start = true;
			itr2++;
			itr1++;
		}
		else if (start && s.find(*itr1) != s.end()){
			return false;
		}
		if (itr1 == l1.end()) itr1 = l1.begin();
		else itr1++;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--){
		int n, j, k, m; 
		unordered_map<int, node*> nodes;
		list<int> l1, l2;	// the list for record the access order
		stack<int> s;	// track where are we from
		cin >> n;
		for (int i = 0; i < n - 1; i++){
			scanf_s("%d%d", &j, &k);
			if (nodes.find(j) == nodes.end()) nodes[j] = new node(j);
			if (nodes.find(k) == nodes.end()) nodes[k] = new node(k);
			nodes[j]->near.push_back(k);
			nodes[k]->near.push_back(j);
		}
		cin >> m;
		for (int i = 0; i < m; i++){
			scanf_s("%d", &j);
			l2.push_back(j);
		}
		// traversal the trival tree graph, record our travel order, then compare to the requirement
		node* curr = nodes.begin()->second;
		l1.push_back(curr->val);
		s.push(curr->val);
		curr->visited = true;
		// dfs traversal, use a stack to track the trail
		while (!s.empty()){
			if (!curr->visited) {
				l1.push_back(curr->val);
				curr->visited = true;
			}
			if (!allVisit(nodes, curr->val)){
				int i = 0;
				for (; i < curr->near.size(); i++)
					if (!nodes[curr->near[i]]->visited) break;
				s.push(curr->val);
				curr = nodes[curr->near[i]];
			}
			else{
				curr = nodes[s.top()];
				s.pop();
			}
		}
		if (checkOrder(l1, l2)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

