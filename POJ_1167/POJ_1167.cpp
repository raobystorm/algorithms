// POJ_1167.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <algorithm>

#define MAX		1000

int arrive[60] = { 0 };
int minrouts = 17,		
busCount = 0,			// how many bus arrivals left in this trial
maxRout = 0;			// the real size of routs[]

class rout{
public:
	int first; int inter; int times;

	rout():first(0), inter(0), times(0){}
	rout(int f, int i, int t) :first(f), inter(i), times(t){}
}routs[MAX];

inline bool check(int* map, rout& r){
	int decrease = 0;
	for (int i = r.first; i < 60; i += r.inter, decrease++){
		if (!map[i]) return false;
	}
	r.times = decrease;
	return true;
}

inline void push(int* map, const rout& r){
	for (int i = r.first; i < 60; i += r.inter){
		map[i] -= 1;
		busCount--;
	}
}
inline void pop(int* map, const rout& r){
	for (int i = r.first; i < 60; i += r.inter){
		map[i] += 1;
		busCount++;
	}
}

inline int cmp(const void* r1, const void* r2){

	return ((rout*)r2)->times - ((rout*)r1)->times;
}

void dfs(int idx, int routSum){

	int i, j;
	if (busCount == 0){
		if (routSum < minrouts)
			minrouts = routSum;
		return;
	}

	for (i = idx; i < maxRout && routs[i].times > busCount; i++);
	for (int k = i; k < maxRout; k++){
		if (routSum + busCount / routs[k].times >= minrouts) return;
		if (check(arrive, routs[k])){
		
			push(arrive, routs[k]);
			dfs(k, routSum+1);
			pop(arrive, routs[k]);
		}
	}
}

int main()
{
	int idx = 0; 
	scanf_s("%d", &busCount);
	
	for (int i = 0,t; i < busCount; i++){

		scanf_s("%d", &t);
		arrive[t] += 1;
	}
	
	rout tempRout;

	for (int i = 0; i < 30; i++){
	
		if (!arrive[i]) continue;
		for (int inter = i + 1; inter < 60 - i; inter++){
		
			tempRout.first = i; tempRout.inter = inter;
			if (check(arrive, tempRout)){
			
				routs[idx].first = tempRout.first;
				routs[idx].inter = tempRout.inter;
				routs[idx].times = tempRout.times;
				idx++;
			}
		}
	}

	maxRout = idx;
	
	qsort(routs, maxRout, sizeof(rout), cmp);

	dfs(0, 0);

	if(minrouts < 18){
	
		printf("%d\n", minrouts);
	}

	return 0;
}

