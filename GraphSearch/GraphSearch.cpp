// GraphSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#define MAX_WIDTH		20
#define MAX_HEIGHT		10

#define MAX MAX_WIDTH*MAX_HEIGHT

#define			point		pair<int,int>

bool dfs(vector<vector<char>>& map, point& p){

	if (p.first < 0) return false;
	if (p.first > 19) return false;
	if (p.second < 0) return false;
	if (p.second > 9) return false;

	if (map[p.first][p.second] == 'G'){ return true; }
	if (map[p.first][p.second] == '#'){ return false; }
	if (map[p.first][p.second] == '@'){ return false; }

	if (map[p.first][p.second] != 'S') map[p.first][p.second] = '@';

	if ((p.first > 0 && dfs(map, point(p.first - 1, p.second))) ||
		(p.first < 19 && dfs(map, point(p.first + 1, p.second))) ||
		(p.second > 0 && dfs(map, point(p.first, p.second - 1))) ||
		(p.second < 9 && dfs(map, point(p.first, p.second + 1)))){

		return true;
	}
	else{

		map[p.first][p.second] = '+';
		return false;
	}
}

bool find(list<point>& l, point& p){

	for (auto i : l){
		if (i.first == p.first && i.second == p.second) return true;
	}

	return false;
}

// in our implementation of every edge has the same value, it is the same as Dijkstra
void bfs(vector<vector<char>>& map, point& start){

	// [open] is the edge part of the search area
	list<point> open;
	// [close] is the area has been searched
	vector<vector<bool>> close(map.size(), vector<bool>(map[0].size(), false));
	// [prev] records the paths that connected to [open]
	vector<vector<point>> prev(map.size(), vector<point>(map[0].size(), point(0, 0)));

	point end(0, 0);

	open.push_back(start);

	while (!open.empty()){

		point curr = open.front();
		open.pop_front();

		close[curr.first][curr.second] = true;

		printf("%d %d\n", curr.first, curr.second);

		if (map[curr.first][curr.second] == 'G'){

			end.first = curr.first;
			end.second = curr.second;
			break;
		}

		// dont consider blocked area, dont cross the border and dont search the place has been searched
		if (curr.first > 0 && map[curr.first - 1][curr.second] != '#' && !close[curr.first - 1][curr.second]){

			prev[curr.first - 1][curr.second] = curr;
			if (!find(open, point(curr.first - 1, curr.second))) open.push_back(point(curr.first - 1, curr.second));
		}
		if (curr.first < map.size()-1 && map[curr.first + 1][curr.second] != '#' && !close[curr.first + 1][curr.second]){

			prev[curr.first + 1][curr.second] = curr;
			if(!find(open, point(curr.first + 1, curr.second))) open.push_back(point(curr.first + 1, curr.second));
		}
		if (curr.second > 0 && map[curr.first][curr.second - 1] != '#' && !close[curr.first][curr.second - 1]){

			prev[curr.first][curr.second - 1] = curr;
			if (!find(open, point(curr.first, curr.second - 1))) open.push_back(point(curr.first, curr.second - 1));
		}
		if (curr.second < map[0].size()-1 && map[curr.first][curr.second + 1] != '#' && !close[curr.first][curr.second + 1]){

			prev[curr.first][curr.second + 1] = curr;
			if (!find(open, point(curr.first, curr.second + 1))) open.push_back(point(curr.first, curr.second + 1));
		}
	}

	while (end != start){

		if (map[end.first][end.second] == '+') map[end.first][end.second] = '@';
		end = prev[end.first][end.second];
	}
}

float Evaluate(point& start, point& curr){

	return (curr.first - start.first)*(curr.first - start.first) + 
		(curr.second - start.second)*(curr.second - start.second);
}

point& FindBestF(vector<vector<char>>& map, list<point>& open, point& start){

	auto i = open.begin(), j = i;
	float minF = 99999.9;
	while (i != open.end()){
	
		float score = Evaluate(start, *i);
		if (score < minF) {
			j = i;
			minF = score;
		}
	}
	return (point&)j;
}

//TODO finish bloody A*
//list<point> getAdjecent(map, )

bool Astar(vector<vector<char>>& map, point& start){

	vector<vector<bool>> close(map.size(), vector<bool>(map[0].size(), false));
	list<point> open;

	while (!open.empty()){

		point curr = FindBestF(map, open, start);
		close[curr.first][curr.second] = true;
		//list<point> adj = 
	}
	return false;
}

void MapSearch(vector<vector<char>>& map){

	int x = 0, y = 0;

	for (int i = 0; i < map.size(); i++)
		for (int j = 0; j < map[0].size(); j++)
			if (map[i][j] == 'S') {
				x = i; y = j;
			}

	//dfs(map, pair<int, int>(x, y));
	bfs(map, point(x, y));

	for (int i = 0; i < map.size(); i++){
		for (int j = 0; j < map[0].size(); j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char map[MAX_WIDTH][MAX_HEIGHT] = {
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '#', '#', '#', '#', '#', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '#', '+', '+', '+', '+' },
		{ '+', '#', '#', '#', '+', '#', '+', '+', '+', '+' },
		{ '+', '#', '+', '+', '+', '#', '+', '+', '+', '+' },
		{ '+', '#', '+', '+', '+', '#', '+', '+', '+', '+' },
		{ '+', '#', '#', '#', '+', '#', '+', '+', '+', '+' },
		{ '+', '#', 'G', '+', '+', '#', '+', '+', '+', '+' },
		{ '+', '#', '+', '#', '+', '#', '+', '+', '+', '+' },
		{ '+', '#', '#', '#', '#', '#', '+', 'S', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
		{ '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' }
	};

	vector<vector<char>> vmap(MAX_WIDTH, vector<char>(MAX_HEIGHT, 'c'));


	for (int i = 0; i < vmap.size(); i++)
		for (int j = 0; j < vmap[0].size(); j++)
			vmap[i][j] = map[i][j];

	MapSearch(vmap);
	return 0;
}

