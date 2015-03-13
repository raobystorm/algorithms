// LCOJ_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> TwoSum(vector<int>& numbers, int target){

	unordered_map<int, int> hash(0);
	vector<int> res;
	
	for (int i = 1; i <= numbers.size(); i++){

		if (hash[target - numbers[i - 1]] != 0){

			if (i < hash[target - numbers[i - 1]]){
				res.push_back(i);
				res.push_back(hash[target - numbers[i - 1]]);
			}
			else{
				res.push_back(hash[target - numbers[i - 1]]);
				res.push_back(i);
			}
			return res;
		}
		hash[numbers[i-1]] = i;
	}
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

		res = TwoSum(nums, target);

		output << res[0] << " " << res[1] << endl;
	}

	return 0;
}

