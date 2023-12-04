/*
217. Contains Duplicate
Easy
Companies

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    // Method 1:
    bool containsDuplicate_1(vector<int>& nums) {
        std::set<int> s(nums.begin(), nums.end());
        return s.size()<nums.size();
    }

    // Method 2:
    bool containsDuplicate_2(vector<int>& nums) {
        std::map<int, int> m_map;
        for (auto &v: nums){
            if (m_map.find(v)!=m_map.end()){
                return true;
            }
            m_map.insert(std::pair{v, 1});
        }
        return false;
    }

    // Method 3:
    bool containsDuplicate_3(vector<int>& nums) {
        std::set<int> s;
        for (auto &v: nums)
        {
            if (s.find(v) != s.end())
            {
                return true;
            }
            s.insert(v);
        }
        return false;
    }

    // Method 4:
    bool containsDuplicate_4(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-1; i++)
        {
            if (nums[i] == nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
