class Solution {
public:
    // Method 1
    vector<int> twoSum_1(vector<int>& nums, int target) {
        for (int index=0; index<nums.size()-1; index++) {
            int theother = target - nums[index];
            for (int j=index+1; j<nums.size(); j++) {
                if (theother == nums[j]) {
                    std::cout<< index << " " << j << std::endl;
                    return vector<int> {index, j};
                }
            }
        }
        return {};
    }

    // Method 2:
    vector<int> twoSum_2(vector<int>& nums, int target) {
        multimap<int, int> mmap;
        for (int index=0; index<nums.size(); index++) {
            mmap.insert({nums[index], index});
        }

        for (int index=0; index<nums.size(); index++) {
            int theother = target - nums[index];
            auto iter = mmap.find(theother);
            if (iter != mmap.end() and iter->second!=index) {
                return vector<int>{index, iter->second};
            }
        }
    
        return  {};
    }

    // Method 3:
    vector<int> twoSum_3(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};


/*

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

int main(){
    // Example 1
    Solution s = Solution();
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    s.twoSum(nums, target);

    // Example 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    s.twoSum(nums2, target2);

    // Example 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    s.twoSum(nums3, target3);
}
