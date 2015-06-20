// ACOJ_024_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include <list>
#include <bitset>
#include <iostream>

#define MAX 1100005
#define MOD 1000000007

using namespace std;

char iniMask[9] = { 0, 1, 3, 7, 15, 31, 63, 127, 255 };

void task1(){
	int a, b, c, k, s, t;
	cin >> a >> b >> c >> k >> s >> t;

	cout << ((a - ((s + t) >= k ? c : 0))*s) + ((b - ((s + t) >= k ? c : 0))*t) << endl;
}

void task2(){

	int n, t, tmp, count = 0;
	cin >> n >> t;

	if (n < 1) {
		cout << 0; return;
	}
	if (t < 1) { cout << 0; return; }

	bool* timeLine = (bool*)malloc(sizeof(bool)*MAX);
	memset(timeLine, 0, sizeof(bool)*MAX);
	for (int i = 0; i < n; i++){
		scanf_s("%d", &tmp);
		memset(timeLine + tmp*sizeof(bool), 1, t);
	}

	for (int i = 0; i < MAX; i++){
		count += timeLine[i];
	}
	cout << count << endl;
}

void task3(){

	int n, d, k, tmp;
	int l[10000], r[10000];
	int s, t;

	cin >> n >> d >> k;

	for (int i = 0; i < d; i++){
		scanf_s("%d%d", &l[i], &r[i]);
	}

	for (int i = 0; i < k; i++){
		scanf_s("%d%d", &s, &t);
		if (s > t) {
			int reach = s;
			for (int j = 0; j < d; j++){
				reach = r[j] >= reach ? (l[j] < reach ? l[j] : reach) : reach;
				if (reach <= t){
					cout << j + 1 << endl;
					break;
				}
			}
		}
		else{

			int reach = s;
			for (int j = 0; j < d; j++){
				reach = l[j] <= reach ? (r[j] > reach ? r[j] : reach) : reach;
				if (reach >= t) {
					cout << j + 1 << endl;
					break;
				}
			}
		}

	}
	return;
}

void task4(){
	unsigned long long a, b, r, c, phi;
	double dphi;
	int A, B, C;

	cin >> A >> B >> C;
	a = (B%MOD*C%MOD - A%MOD*B%MOD) % MOD;
	b = (A%MOD*C%MOD - B%MOD*C%MOD + A%MOD*B%MOD) % MOD;
	dphi = pow(b, MOD - 2);
	phi = dphi;
	phi %= MOD;
	c = a*phi%MOD;

	a = (B%MOD*C%MOD - A%MOD*C%MOD);
	b = (A%MOD*B%MOD - B%MOD*C%MOD + A%MOD*C%MOD);
	r = a*((unsigned long long)pow(b, MOD - 2));

	cout << r << " " << c << endl;
	return ;
}

int main()
{
	
}

