/*
35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity. 

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert_1(std::vector<int>& nums, int target) {
        for (auto index=0; index < nums.size(); index++)
        {
            if (nums[index] >=target)
            {
                return index;
            }
        }
        return nums.size();
    }

    // Method 2: binary search
    int searchInsert_2(std::vector<int>& nums, int target) {
        auto low = 0, mid = 0;
        auto high=nums.size()-1;

        while (low <=high and mid<nums.size())
        {
            mid = (low + high) / 2;
            if (nums[mid] < target) 
            {
                low = mid + 1;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
            }
            else {
                std::cout<< "Mid1=" << mid << endl;
                return mid;
            }
        }

        std::cout<< "Mid2=" << low << endl;;
        return low;
    }
};

int main()
{
    auto sol = Solution();
    vector<int> vec1 = {1};
    auto target = 0;
    // sol.searchInsert(vec1, target); // 0

    // vec1 = {1, 3};
    // target = 2;
    // sol.searchInsert(vec1, target); // 1

    vec1 = {1, 3, 5, 6};
    target = 0;
    sol.searchInsert(vec1, target); // 0

    // target = 5;
    // sol.searchInsert(vec1, target); // 2

    // target = 2;
    // sol.searchInsert(vec1, target); // 1

    // target = 7;
    // sol.searchInsert(vec1, target); // 4

    return 0;
}
