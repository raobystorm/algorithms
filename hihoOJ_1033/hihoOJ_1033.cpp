// hihoOJ_1033.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

#define MOD 1000000007

using namespace	std;

inline int crossAdd(unsigned long long& a){

	int count = 0;
	int pos = 0, neg = 0;
	unsigned long long aa = a;

	while (aa){

		if (count % 2) neg += aa % 10;
		else pos += aa % 10;

		count++;
		aa /= 10;
	}

	if (count % 2) return pos - neg;
	else return neg - pos;
}

inline int log(unsigned long long a){
	int i = 0;
	while (a){
		i++;
		a /= 10;
	}
	return i;
}

inline unsigned long long upperBound(unsigned long long& ll){

	unsigned long long rr = 1;
	int c = log(ll);
	while (c--) rr *= 10;
	return --rr;
}

int main()
{
	unsigned long long l, r, ll, rr, ans = 0, base, tmp;
	int k, res = 0, t;
	cin >> l >> r >> k;
	ofstream out("out.txt");

	ll = l;
	rr = r;
	t = log(rr) - log(ll) + 1;
	base = log(ll);
	tmp = ll;

	while (t--){

		while (crossAdd(ll) != k) ll++;
		rr = upperBound(ll) < r ? upperBound(ll): r;
		while (crossAdd(rr) != k) rr--;

		while (ll < rr){
			if (crossAdd(ll) == k){
				ans += ll%MOD;
				ans %= MOD;
				tmp = ll;
			}
			ll += 11;
		}
		ll = rr;
		rr += 11;
		while (ll < rr){
			if (ll > r) break;
			if (crossAdd(ll) == k){
				ans += ll%MOD;
				ans %= MOD;
			}
			ll ++;
		}
		ll = rr;
		if (ll > r) break;
	}

	/*ifstream in("out.txt");
	int tmp, prev;
	in >> prev;
	in >> tmp;
	while (in.eof()){
		if (tmp - prev != 11){
			cout << tmp << endl;
		}
		prev = tmp;
		in >> tmp;
	}*/
	cout << ans << endl;
	return 0;
}

