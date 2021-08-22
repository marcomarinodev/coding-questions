class Solution {
public:
    int search(vector<int>& nums, int target) {
        int found = -1;
    	int left = 0;
    	int right = nums.size() - 1;
    	int mid = (left + right) / 2;

        if (right == -1) return -1;

        if (nums[mid] == target) return mid;
    
    	while (left < right && found == -1) {

    		if (target < nums[mid]) {
    			right = mid - 1;
    		} else {
    			left = mid + 1;
    		}

    		mid = (left + right) / 2;

    		if (nums[mid] == target) found = 1;

    	}

    	if (found == 1) return mid;

    	return found;
    }
};
