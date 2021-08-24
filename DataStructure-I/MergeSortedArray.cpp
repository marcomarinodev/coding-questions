#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int findex = 0;
        int sindex = 0;
        
        vector<int> result;
        
        while (findex < m && sindex < n) {
            
            if (nums1[findex] <= nums2[sindex]) {
                result.push_back(nums1[findex]);
                findex++;
            } else {
                result.push_back(nums2[sindex]);
                sindex++;
            }
            
        }
        
        if (findex == m) {
            while (sindex < n) {
                result.push_back(nums2[sindex]);
                sindex++;
            }
            
            nums1 = result;

            return;
        }
        
        if (sindex == n) {
            while (findex < m) {
                result.push_back(nums1[findex]);
                findex++;
            }

            nums1 = result;

            return;
        }
    }
};

void printVector(vector<int>& vect) {
    for (int i : vect) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    Solution *sol = new Solution();

    vector<int> test11{1,2,3,0,0,0};
    vector<int> test12{2,5,6};
    
    vector<int> test21{1};
    vector<int> test22{};

    vector<int> test31{0};
    vector<int> test32{1};

    sol->merge(test11, 3, test12, 3);
    sol->merge(test21, 1, test22, 0);
    sol->merge(test31, 0, test32, 1);

    printVector(test31);

    return 0;

}
