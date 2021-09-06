class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int i = 0;
        int j = n;
        
        vector<int> out;
        
        for (i = 0; i < n; i++) {
            
            out.push_back(nums[i]);
            out.push_back(nums[j + i]);
            
        }
        
        return out;
        
    }
};
