#include <vector>
#include <iostream>
#include <iterator>   // std::distance()
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i+1; j < size; ++j) {
                if (nums[i] + nums[j] != target) {
                    continue;
                }

                return vector<int>{i, j};
            }
        }

        return vector<int>{0, 0};
    }

    vector<int> twoSum1(vector<int>& nums, int target) {

        vector<int>::const_iterator it_end = nums.end();
        vector<int>::const_iterator it_begin = nums.begin();
        vector<int>::iterator it1, it2;

        for (it1 = nums.begin(); it1 != it_end; ++it1) {
            for (it2 = it1 + 1; it2 != it_end; ++it2) {
                if (*it1 + *it2 != target) {
                    continue;
                }

                return vector<int> {static_cast<int>(it1-it_begin), static_cast<int>(it2-it_begin)};
            }
        }

        return vector<int>{0, 0};
    }

    // Two pass of vector elements.
    vector<int> twoSum2(vector<int>& nums, int target) {

        map<int, int> hmap;
        for (size_t i = 0; i < nums.size(); ++i) {
            hmap.insert(pair<int, int>(nums[i], i));
        }

        for (size_t i = 0; i < nums.size(); ++i) {
            int val = target - nums[i];
            if (hmap.find(val) != hmap.end()) {
                return vector<int> {static_cast<int>(i), hmap.at(val)};
            }
        }

        return vector<int>{0, 0};
    }

    // One pass of vector elements.
    vector<int> twoSum3(vector<int>& nums, int target) {

        map<int, int> hmap;
        for (size_t i = 0; i < nums.size(); ++i) {
            int val = target - nums[i];
            if (hmap.find(val) != hmap.end()) {
                return vector<int> {static_cast<int>(i), hmap.at(val)};
            }
            hmap.insert(pair<int, int>(nums[i], i));
        }

        return vector<int>{0, 0};
    }


};

int main() {

    vector<int> nums{1,2,4,7,10,11,16};
    Solution solution;

    auto vec = solution.twoSum(nums, 13);
    cout << "Result is " << vec[0] << ":"<< vec[1] << endl;

    vec = solution.twoSum1(nums, 13);
    cout << "Result is " << vec[0] << ":"<< vec[1] << endl;

    vec = solution.twoSum2(nums, 13);
    cout << "Result is " << vec[0] << ":"<< vec[1] << endl;

    vec = solution.twoSum3(nums, 13);
    cout << "Result is " << vec[0] << ":"<< vec[1] << endl;
}
