// BinaryIndexedTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryIndexedTree.h"
#include <iostream>

template<typename T>
T BIT<T>::lowbit(T x){
	return x & (-x);
}

template<typename T>
BIT<T>::BIT<T>(T n){
	nums = std::vector<T>(n);
}

template<typename T>
void BIT<T>::setVal(T x, T val){
	nums[x] = val;
}

template<typename T>
T BIT<T>::getVal(T x){ if(x < nums.size()) return nums[x];}

template<typename T>
void BIT<T>::add(T x, T y){
	while (x < nums.size()){
		nums[x] += y;
		x += lowbit(x);
	}
}

template<typename T>
T BIT<T>::sum(T x){
	T s = 0;
	while (x > 0){
		s += nums[x];
		x -= lowbit(x);
	}
	return s;
}

int main()
{
	int n, tmp, m, l, r;
	std::cin >> n;

	BIT<int> bitree(n);
	for (int i = 0; i < n; i++){
		scanf_s("%d", &tmp);
		bitree.setVal(i, tmp);
	}

	std::cin >> m;
	for (int i = 0; i < m; i++){
		scanf_s("%d%d", &l, &r);
		printf("%d\n", bitree.sum(r) - bitree.sum(l));
	}
		
	return 0;
}

