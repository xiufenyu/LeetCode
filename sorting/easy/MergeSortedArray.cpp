/*
88. Merge Sorted Array
Easy

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


Constraints:
    nums1.length == m + n
    nums2.length == n
    0 <= m, n <= 200
    1 <= m + n <= 200
    -109 <= nums1[i], nums2[j] <= 109
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // Method 1: space: O(1), from back to front 
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int p = m+n-1;
        while (i>=0 and j>=0)
        {
            if (nums1[i] >= nums2[j]) {
                nums1[p--] = nums1[i--];
            }
            else
            {
                nums1[p--] = nums2[j--];
            }
        }
        while (j>=0 and p>=0)
        {
            nums1[p--] = nums2[j--];
        }
    }

     void merge_2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j=0; j < nums2.size(); j++)
        {
            nums1[j+m] = nums2[j];
        }

        std::sort(nums1.begin(), nums1.end());
    }

};

int main()
{
    Solution sol = Solution();
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m =3, n=3;
    sol.merge(nums1, m, nums2, n);  //1,2,2,3,5,6


    nums1 = {1};
    nums2 = {};
    m =1, n=0;
    sol.merge(nums1, m, nums2, n);  //1


    nums1 = {0};
    nums2 = {1};
    m =0, n=1;
    sol.merge(nums1, m, nums2, n);  //1

    nums1 = {4,5,6,0,0,0};
    nums2 = {1,2,3};
    m =3, n=3;
    sol.merge(nums1, m, nums2, n);  //[1,2,3,4,5,6]

    return 0;
}
