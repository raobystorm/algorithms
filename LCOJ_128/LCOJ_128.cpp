
#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cstring>

using namespace std;

struct intv{
	int l, r;
	intv() : l(0), r(0){}
	intv(int ll, int rr) : l(ll), r(rr){}
};

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		intv* res, *curr, *currr, *tmpi;
		res = new intv();
		unordered_map<int, intv*> hash;
		unordered_set<int> searched;
		for (int i = 0; i < nums.size(); i++){
			if (searched.find(nums[i]) != searched.end()) continue;
			searched.insert(nums[i]);
			bool lfind = hash.find(nums[i] - 1) != hash.end(),
				rfind = hash.find(nums[i] + 1) != hash.end();

			if (!lfind && !rfind){
				tmpi = new intv(nums[i], nums[i]);
				hash[nums[i]] = tmpi;
				curr = tmpi;
			}
			else if (!lfind && rfind){
				curr = hash[nums[i] + 1];
				curr->l = nums[i];
				if (curr->r != nums[i] + 1) hash.erase(nums[i] + 1);
				hash[nums[i]] = curr;
			}
			else if (lfind && !rfind){
				curr = hash[nums[i] - 1];
				curr->r = nums[i];
				if (curr->l != nums[i] - 1) hash.erase(nums[i] - 1);
				hash[nums[i]] = curr;
			}
			else{
				curr = hash[nums[i] - 1];
				currr = hash[nums[i] + 1];
				curr->r = currr->r;
				hash.erase(nums[i] - 1);
				hash.erase(nums[i] + 1);
				hash[curr->r] = curr;
				hash[curr->l] = curr;
			}
			res = (curr->r - curr->l) > (res->r - res->l) ? curr : res;
		}

		return res->r - res->l + 1;
	}
};

int main(){

	vector<int> nums = { -3, 2, 8, 5, 1, 7, -8, 2, -8, -4, -1, 6, -6, 9, 6, 0, -7, 4, 5, -4, 8, 2, 0, -2, -6, 9, -4, -1 };
	int res = Solution().longestConsecutive(nums);

	return 0;
}