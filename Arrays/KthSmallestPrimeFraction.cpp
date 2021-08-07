#include <iostream>
#include <queue>
#include <vector>

// 786
// time: O(K * log N)
// space: O(N)

using namespace std;

class Solution {
    
    typedef pair<double, pair<int, int>> fraction;
    
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<fraction, vector<fraction>, greater<fraction>> q;
        fraction top;
        
        for (int i = 0; i < (arr.size() - 1); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                
                q.push({ (double) arr[i] / arr[j], {arr[i], arr[j]} });
                
            }
        }
        
        for (int it = 0; it < k; it++) {
            top = q.top();
            q.pop();
        }
        
        return { top.second.first, top.second.second };
        
    }
};

int main(int argc, const char * argv[]) {
    
    Solution *sol = new Solution();
    
    vector<int> test1 { 1, 2, 3, 5 };
    
    assert( sol->kthSmallestPrimeFraction(test1, 3)[0] == 2 );
    assert( sol->kthSmallestPrimeFraction(test1, 3)[1] == 5 );
    
    vector<int> test2 { 1, 7 };
    
    assert( sol->kthSmallestPrimeFraction(test2, 1)[0] == 1 );
    assert( sol->kthSmallestPrimeFraction(test2, 1)[1] == 7 );
    
    cout << "Test passed!";
    
    return 0;
}

