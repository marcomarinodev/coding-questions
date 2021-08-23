class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // the key is the number and its value is its index in nums
        unordered_map<int, int> ht;
        vector<int> result;
        int to_find;

        for (int i = 0; i < nums.size(); i++) {
            to_find = target - nums[i];

            // Found in hash map
            if (ht.find(to_find) != ht.end()) {
                result.push_back(ht[to_find]);
                result.push_back(i);
                
                return result;
            }

            // to_find is not in ht, add nums[i]
            ht[nums[i]] = i;
        }

        return result;
    }
};
