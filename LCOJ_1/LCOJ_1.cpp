// LCOJ_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){

	// For a number n, map (target-n) to the indice of n.
	unordered_map<int, int> hash(0);
	vector<int> res;

	for (int i = 0; i < numbers.size(); i++) {
		if (hash.find(numbers[i]) != hash.end()) {
			res.push_back(hash[numbers[i]]);
			res.push_back(i);
			return res;
		} else {
			hash[target - numbers[i]] = i;
		}
	}
	return res;
}

int main()
{
	ifstream input("in.txt");
	ofstream output("out.txt");

	int n, target;

	while (1){
	
		input >> n;
		if (n <= 0) break;
		vector<int> nums, res;

		for (int i = 0; i < n; i++){
		
			int tmp;
			input >> tmp;
			nums.push_back(tmp);
		}

		input >> target;

		res = twoSum(nums, target);

		output << res[0] << " " << res[1] << endl;
	}

	return 0;
}

