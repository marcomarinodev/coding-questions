#include <iostream>
#include <vector>

// 1131

using namespace std;

class Solution {
    
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        
        /**
         
         |x[i] - x[j]| + |y[i] - y[j]| we have four cases
         
         | a - b | = {
            
            a > b => a - b,
            b > a => -(a - b) = -a + b
         
         }
         
         |x[i] - x[j]| + |y[i] - y[j]| = (x[i] - x[j]|) + (y[i] - y[j]) = (x[i] + y[i]|) - (x[j] + y[j])
         |x[i] - x[j]| + |y[i] - y[j]| = (x[i] - x[j]|) - (y[i] - y[j]) = (x[i] - y[i]|) - (x[j] - y[j])
         |x[i] - x[j]| + |y[i] - y[j]| = -(x[i] - x[j]|) + (y[i] - y[j]) = (-x[i] + y[i]|) - (-x[j] + y[j])
         |x[i] - x[j]| + |y[i] - y[j]| = -(x[i] - x[j]|) - (y[i] - y[j]) = (-x[i] - y[i]|) - (-x[j] - y[j])
         
         these 4 formulas has a pattern: f(i)
         
         f(i) - f(j) where f(i): sign1 * x[i] + sign2 * y[i] where sign1, sign2 = { 1, -1 }
         
         
         
         */
        
        int maxFormula = 0;
        unsigned long n = arr1.size();
        int smallest, current;
        
        // signs combinations
        for (int p : {1, -1}) {
            for (int q: {1, -1}) {
                
                smallest = p * arr1[0] + q * arr2[0] + 0;
                
                for (int i = 1; i < n; ++i) {
                    
                    current = p * arr1[i] + q * arr2[i] + i;
                    
                    maxFormula = max(maxFormula, current - smallest);
                    
                    smallest = min(smallest, current);
                    
                }
                
            }
        }
        
        return maxFormula;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution *sol = new Solution();
    
    vector<int> test1A {1,2,3,4};
    vector<int> test1B {-1,4,5,6};
    
    assert(sol->maxAbsValExpr(test1A, test1B) == 13);
    
    vector<int> test2A {1,-2,-5,0,10};
    vector<int> test2B {0,-2,-1,-7,-4};
    
    assert(sol->maxAbsValExpr(test2A, test2B) == 20);
    
    cout << "Test passed!";
    
    return 0;
}

