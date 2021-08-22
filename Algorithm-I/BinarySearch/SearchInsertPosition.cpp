class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        if (right == -1) return 0;
        
        while (left < right) {
            mid = (left + right) / 2;
            
            if (nums[mid] == target) return mid;
            
            if (target < nums[mid]) {
                right = mid - 1;
            } else { 
                left = mid + 1;
            }
        }
        
        if (target > nums[left]) {
            return left + 1;
        } else {
            return left;
        }
        
    }
};
