// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;
int array[500000] = { 0 };

void swap(int* nums, int a, int b){
	if (a == b) return;
	int tmp = nums[a];
	nums[a] = nums[b];
	nums[b] = tmp;
}

int partition(int* nums, int left, int right){

	if (left == right - 1 && nums[left] > nums[right]) swap(nums, left, right);

	int pivot = left++;
	int i = left;
	for (; i < right; i++){
	
		if (nums[i] > nums[pivot]){
		
			while (right > left && nums[right] > nums[pivot]) right--;
			if(i < right) swap(nums, i, right);
			else break;
		}
	}
	swap(nums, pivot, i-1);
	return i-1;
}

void qsort(int* nums, int left, int right){

	if (left >= right) return;

	int pivot = partition(nums, left, right);
	qsort(nums, left, pivot);
	qsort(nums, pivot + 1, right);
}

int main()
{
	int n, tmp;

	ifstream fin("in.txt");
	ofstream fout("out.txt");

	while (1){
		
		fin >> n;
		if (!(n>0)) break;

		for (int i = 0; i < n; i++) fin >> array[i];

		qsort(array, 0, n-1);

		for (int i = 0; i < n; i++) fout << array[i]<<" ";

		fout << endl;
	}
	return 0;
}

