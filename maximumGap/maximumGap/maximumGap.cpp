#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;

class Solution{
public:
	int maximumGap(vector<int>& nums){
		int n = nums.size();
		if (n < 2)
			return 0;
		int maxE = *max_element(nums.begin(), nums.end());
		int minE = *min_element(nums.begin(), nums.end());
		if (maxE == minE)
			return 0;
		double step = (double)(maxE - minE) / (n - 1);
		vector<int> maxlst(n, INT_MIN);
		vector<int> minlst(n, INT_MAX);
		for (int i = 0; i < n; i++){
			int id = (nums[i] - minE) / step;
			maxlst[id] = max(maxlst[id], nums[i]);
			minlst[id] = min(minlst[id], nums[i]);
		}
		int maxgap = 0, prev = maxlst[0];
		for (int i = 1; i < n; i++){
			if (maxlst[i] == INT_MIN) continue;
			maxgap = max(maxgap, minlst[i] - prev);
			prev = maxlst[i];
		}
		return maxgap;
	}
};