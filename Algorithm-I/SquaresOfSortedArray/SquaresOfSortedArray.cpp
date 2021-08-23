#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> result(nums.size());
		
		int k = nums.size() - 1;
		
		int i = 0;
		int j = k;
		
		while (k > -1) {
			if (nums[i]*nums[i] < nums[j]*nums[j]) {
				result[k] = nums[j]*nums[j];
				j--;
			} else {
				result[k] = nums[i]*nums[i];
				i++;
			}
			
			k--;
		}
		
		return result;
        
    }
};
