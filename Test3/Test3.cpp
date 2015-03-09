// Test3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>
#include <fstream>

using namespace std;

int size = 0;
int cnt = 0;
string funcName[20];
int map[20][20] = { 0 };

inline bool comp(const string& s1, const string& s2){

	if (s1.length() != s2.length()) return false;
	for (int i = 0; i < s1.length(); i++)
		if (s1[i] != s2[i]) return false;

	return true;
}

inline int find(const string& s){

	for (int i = 0; i < size; i++){
		if (comp(s, funcName[i])){
		
			return i;
		}
	}
	return -1;
}

void dfs(int start, int obj){

	if (cnt >= 1000) return;
	if (map[start][obj]) cnt += map[start][obj];

	for (int i = 0; i < 20; i++){
	
		if (map[start][i] != 0){
			for (int j = 0; j < map[start][i]; j++)
				dfs(i, obj);
		}
	}
}

int main()
{
	ifstream input("task-2-extra-sample-in.txt");
	ofstream output("output2-extra.txt");

	string entry, obj, tmpfunc, current;
	stack<int> funcs;

	int n, m, l, tmpidx, curridx, objidx;
	input >> n;
	for (int i = 0; i < n; i++){

		input >> entry >> obj;
		input >> m;
		size = 0;
		memset(map, 0, 20*20*sizeof(int));

		for (int j = 0; j < m; j++){
			input >> current;
			input >> l;
			if (!l) continue;
			curridx = find(current);
			if (curridx == -1){
			
				funcName[size] = current;
				curridx = size;
				size++;
			}
			for (int k = 0; k < l; k++){
				input >> tmpfunc;
				tmpidx = find(tmpfunc);
				if (tmpidx == -1){
					funcName[size] = tmpfunc;
					map[curridx][size]++;
					size++;
				}
				else{
					
					map[curridx][tmpidx]++;
				}
			}
		}

		curridx = find(entry);
		objidx = find(obj);
		cnt = 0;

		dfs(curridx, objidx);

		output << "Case #" << i+1 << ": " << cnt << endl;
	}

	return 0;
}

