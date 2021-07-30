#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string common = "";

        for (int i = 0; i < strs.size(); i++)
        {
            if (i == 0)
            {
                common = strs[i];
                continue;
            }

            string newCommon = "";

            for (int j = 0; j < common.length(); j++)
            {
                if (common[j] == strs[i][j])
                {
                    newCommon.push_back(common[j]);
                }
                else
                {
                    break;
                }
            }

            common = newCommon;
        }

        return common;
    }
};

int main(int argc, const char *argv[])
{

    Solution *sol = new Solution();

    vector<string> test1;

    test1.push_back("flower");
    test1.push_back("flow");
    test1.push_back("flight");

    vector<string> test2;

    test2.push_back("dog");
    test2.push_back("racecar");
    test2.push_back("car");

    vector<string> test3;

    test3.push_back("weee");

    vector<string> test4;

    vector<string> test5;

    test5.push_back("far");
    test5.push_back("farenheit");
    test5.push_back("f");
    test5.push_back("faren");

    assert(sol->longestCommonPrefix(test1) == "fl");

    assert(sol->longestCommonPrefix(test2) == "");

    assert(sol->longestCommonPrefix(test3) == "weee");

    assert(sol->longestCommonPrefix(test4) == "");

    assert(sol->longestCommonPrefix(test5) == "f");

    cout << "Test passed!" << endl;

    return 0;
}
