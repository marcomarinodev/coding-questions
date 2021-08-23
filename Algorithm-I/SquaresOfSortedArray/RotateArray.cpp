#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		void rotate(vector<int>& nums, int k) {	

			int n = nums.size();

			if ((n == 0) || (k <= 0))
            {
                return;
            }
            
            int cntRotated = 0;
            int start = 0;
            int curr = 0;
            int numToBeRotated = nums[0];
            int tmp = 0;

            while (cntRotated < n)
            {
                do
                {
                    tmp = nums[(curr + k)%n];
                    nums[(curr+k)%n] = numToBeRotated;
                    numToBeRotated = tmp;
                    curr = (curr + k)%n;
                    cntRotated++;
                } while (curr != start);

                start++;
                curr = start;
                numToBeRotated = nums[curr];
            }
		
		}
};

int main(int argc, char **argv) {

	Solution *sol = new Solution();

	vector<int> test0{ 1,2,3,4,5,6,7 };
	vector<int> test1{ -1, -100, 3, 99 };
	vector<int> test2{1};
	vector<int> test3{1, 2};
	vector<int> test4{1, 2, 3};
	vector<int> test5{1, 2, 3};
	vector<int> test6{-1};
	vector<int> test7{1, 2};
	vector<int> test8{1,2,3};

	sol->rotate(test0, 3); // OK
	sol->rotate(test1, 2); // OK
	sol->rotate(test2, 0); // OK
	sol->rotate(test3, 1); // OK
	sol->rotate(test4, 0); // OK
	sol->rotate(test5, 2); // OK
	sol->rotate(test6, 2); // OK
	sol->rotate(test7, 3); // OK
	sol->rotate(test8, 4); // OK

	vector<int> sol0{ 5,6,7,1,2,3,4 };
	vector<int> sol1{ 3, 99, -1, -100 };
	vector<int> sol2{1};
	vector<int> sol3{2, 1};
	vector<int> sol4{1, 2, 3};
	vector<int> sol5{2, 3, 1};
	vector<int> sol6{-1};
	vector<int> sol7{2, 1};
	vector<int> sol8{3,1,2};

	assert(test0 == sol0);
	assert(test1 == sol1);
	assert(test2 == sol2);
	assert(test3 == sol3);
	assert(test4 == sol4);
	assert(test5 == sol5);
	assert(test6 == sol6);
	assert(test7 == sol7);
	assert(test8 == sol8);

	cout << "Tests passed";

	return 0;

}
