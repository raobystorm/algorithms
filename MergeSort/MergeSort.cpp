// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <fstream>
#include <iostream>

using namespace std;

typedef list<int>::iterator			idx;

list<int>* merge(list<int>* left, int& leftLength, list<int>* right, int& rightLength){

	list<int> newList;
	idx leftElem = (*left).begin(), rightElem = (*right).begin();
	for (int i = 0; i < leftLength + rightLength; i++){
	
		if (leftElem == (*left).end()){
		
			while (rightElem != (*right).end()){
			
				newList.push_back(*rightElem);
				rightElem++;
			}
		}

		if (rightElem == (*right).end()){
		
			while (leftElem != (*left).end()){

				newList.push_back(*leftElem);
				leftElem++;
			}
		}

		if (*leftElem > *rightElem) { 
			newList.push_back(*rightElem); 
			rightElem++;
		}
		else{
			newList.push_back(*leftElem);
			leftElem++;
		}
	}

	return &newList;
}

list<int>* mergeSort(idx* start, int length){

	if (length <= 1) {
	
		list<int> newList;
		newList.push_back(**start);
		return &newList;
	}

	idx leftStart, rightStart;
	int leftLength, rightLength;
	leftStart = *start;
	leftLength = length / 2;
	rightStart = leftStart;
	for (int i = 0; i < leftLength; i++) rightStart++;
	rightLength = length - leftLength;

	list<int>* left = mergeSort(&leftStart, leftLength);
	list<int>* right = mergeSort(&rightStart, rightLength);

	return merge(left, leftLength, right, rightLength);
}

int main()
{

	int n;

	ifstream fin("in.txt");
	ofstream fout("out.txt");

	list<int> sortList, *sorted;

	while (1){
	
		fin >> n;
		if (!(n > 0)) break;

		for (int i = 0; i < n; i++){
			int tmp;
			fin >> tmp;
			sortList.push_back(tmp);
		}

		idx start = sortList.begin();
		sorted = mergeSort(&start, n);

		idx sortedElem = (*sorted).begin();
		for (int i = 0; i < n; i++){
		
			fout << *sortedElem << " ";
			sortedElem++;
		}

		fout << endl;
	}

	return 0;
}

