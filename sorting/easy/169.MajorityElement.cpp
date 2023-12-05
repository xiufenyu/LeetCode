/*169. Majority Element
Easy

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 
Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

 
Constraints:
    n == nums.length
    1 <= n <= 5 * 104
    -109 <= nums[i] <= 109

 
Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;


class Solution {
public:

    int majorityElement_1(vector<int>& nums) {
        std::unordered_map<int, int> un_map;
        for (auto &v: nums) {
            if (un_map.find(v) == un_map.end())
            {
                un_map[v] = 1;
            }
            else
            {
                un_map[v] += 1;
            }
        }

        auto iter = un_map.begin();
        int count = 0;
        int majority = 0;
        for (iter = un_map.begin(); iter!=un_map.end(); iter++)
        {
            if (count < iter->second)
            {
                majority = iter->first;
                count = iter->second;
            }
        }

        return majority;
    }

    // method 2: Sorting
    int majorityElement_2(vector<int>& nums) {
       std::sort(nums.begin(), nums.end());
       int len = nums.size()/2;
       return nums[len];
    }

   int majorityElement(vector<int>& arr) {
        int ele=arr[0];
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(count==0)ele=arr[i];
            count+=(ele==arr[i])?1:-1;
        }
        return ele;
    }
};
