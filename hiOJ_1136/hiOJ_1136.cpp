// hiOJ_1136.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>

#define MAX 100000
#define MOD 142857

using namespace std;

struct node{
	int input;
	int count;
	vector<int> output;
	node(): input(0), count(0){}
}nodes[MAX];

int main()
{
	int t;
	cin >> t;
	int n, m;
	while (t--){

		queue<int> sig;
		unordered_map<int, vector<node*>> mods;
		scanf("%d%d", &n, &m);
		vector<node> nodes(n);
		int k;// setup the initial signals
		int tmpin;
		for (int i = 0; i < m; i++){
			scanf("%d", &tmpin);
			sig.push(tmpin);
		}

		// setup the modules
		for (int i = 0; i < n; i++){
			scanf("%d%d", &(nodes[i].input), &k);
			nodes[i].output = vector<int>(k, 0);
			for (int j = 0; j < k; j++)
				scanf("%d", &(nodes[i].output[j]));
			if (&(mods[nodes[i].input]) == nullptr) mods[nodes[i].input] = vector<node*>();
			mods[nodes[i].input].push_back(&(nodes[i]));
		}
		
		while (!sig.empty()){
		
			vector<node*> curr;
			tmpin = sig.front();
			sig.pop();
			if (mods.find(tmpin) == mods.end()) continue;
			else{

				curr = mods[tmpin];
				for (int i = 0; i < curr.size(); i++){
					curr[i]->count++;
					curr[i]->count %= MOD;
					for (int j = 0; j < curr[i]->output.size(); j++)
						if (mods.find(curr[i]->output[j]) != mods.end()) sig.push(curr[i]->output[j]);
				}
			}
		}

		for (int i = 0; i < n; i++){
			printf("%d ", nodes[i].count);
		}
		printf("\n");
	}
	return 0;
}

