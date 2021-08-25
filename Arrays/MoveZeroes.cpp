#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int j = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    nums[j] = nums[i];
                    j++;
                }
            }

            while (j < nums.size()) {
                nums[j] = 0;
                j++;
            }
        }
};

int main() {

    Solution *sol = new Solution();

    vector<int> test1{0,1,0,3,12};
    vector<int> sol1{1,3,12,0,0};

    vector<int> test2{0};
    vector<int> sol2{0};

    vector<int> test3{0,0,1};
    vector<int> sol3{1,0,0};

    sol->moveZeroes(test1);
    sol->moveZeroes(test2);
    sol->moveZeroes(test3);

    assert(test1 == sol1);
    assert(test2 == sol2);
    assert(test3 == sol3);

    cout << "Test passed!";

    return 0;
}
