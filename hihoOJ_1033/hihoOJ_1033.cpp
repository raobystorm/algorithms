// hihoOJ_1033.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

#define ll long long int

const int mod = 1000000007;

struct node{
	ll s, n;
};
// dp is 
node dp[21][20][400];

int bits[21];
ll base[21];

//len��λ����, dig���׸�����, begin_zero��ʾ֮ǰ�Ƿ��Ѿ���ʼ��ţ� end_flag��ʾ��һλö��ʱ�Ƿ�ö�ٵ�bit[len-2]�������ö�ٵ�9�� sum��Ҫ������ֺ�   
node dfs(int len, int dig, bool begin_zero, bool end_flag, int sum){
	node t;
	t.s = 0, t.n = 0;
	//�����߽�ֵ   
	if (len <= 0 || len >= 20 || dig < 0 || dig > 9 || sum < -200 || sum >= 200)
		return t;
	//�������е�DP����������仯����   
	if (!end_flag && dp[len][dig + (begin_zero ? 0 : 10)][sum + 200].n != -1)
		return dp[len][dig + (begin_zero ? 0 : 10)][sum + 200];
	//����ֻ��һλ���Ͳ���Ҫö����һλ�ˣ�ֱ�����۷��ؼ���   
	if (len == 1){
		if (dig != sum)
			return t;
		t.n = 1, t.s = sum;
		return t;
	}
	//��ʼö����һλ������   
	int end = end_flag ? bits[len - 2] : 9;
	int newsum = dig - sum;
	node tmp;
	for (int j = 0; j <= end; j++){
		if (!begin_zero){
			tmp = dfs(len - 1, j, j != 0, end_flag && (j == end), sum);
		}
		else{
			tmp = dfs(len - 1, j, true, end_flag && (j == end), newsum);
		}
		//��tmp��ֵ�ۼӵ�t��  
		t.n += tmp.n;
		t.s = ((t.s + tmp.s) % mod + ((tmp.n * dig) % mod * base[len - 1]) % mod) % mod;
	}
	if (!end_flag) dp[len][dig + (begin_zero ? 0 : 10)][sum + 200] = t;
	return t;
}

int solve(ll n, int s){
	if (n <= 0)
		return 0;
	int l = 0;
	for (int i = 0; i < 21; i++)
		bits[i] = 0;
	while (n){
		bits[l++] = n % 10;
		n /= 10;
	}
	return dfs(l + 1, 0, false, true, s).s;
}

int main(){
	ll l, r, s;
	node t;
	t.n = -1;
	t.s = 0;
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < 20; j++)
			for (int k = 0; k < 400; k++) 
				dp[i][j][k] = t;

	base[0] = 1;
	for (int i = 1; i < 21; i++)
		base[i] = (base[i - 1] * 10) % mod;
	cin >> l >> r >> s;
	cout << (solve(r, s) - solve(l - 1, s) + mod) % mod << endl;
	return 0;
}