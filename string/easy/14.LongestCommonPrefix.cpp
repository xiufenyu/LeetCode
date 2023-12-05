/*14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 
Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // find the common prefix, not the common str
    // Method 1:
    string longestCommonPrefix_1(vector<string>& strs) {
        string common_str = string(), result=string();

        auto first_str = strs[0];
        int start = 0, end = start + 1;
        bool match = true;
        for (int i=0; i < first_str.size(); i++)
        {
            common_str = first_str.substr(start, end);
            for (int j=1; j < strs.size(); j++)
            {
                if (strs[j].find(common_str) !=0)
                {
                    match = false;
                    break;
                }
            }

            if (match) {
                result = common_str;
                end ++;
                match = true;
            }
            else
            {
                break;
            }
        }

        std::cout<< "common str: " << result << endl;
        return result;
    }

    // Method 2: 
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        {
            return "";
        }
        string prefix = strs[0];
        for (string s : strs)
        {
            while (s.find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
            }
        }
        return prefix;
    }
};

int main()
{
    Solution sol = Solution();
    vector<string> strs = {"flower", "flow", "flight"};
    sol.longestCommonPrefix(strs); // fl

    strs = {"dog","racecar","car"};
    sol.longestCommonPrefix(strs); // ""

    strs = {"dog","catdog","hedogcat"};
    sol.longestCommonPrefix(strs); // ""

    strs = {"c", "acc", "ccc"};
    sol.longestCommonPrefix(strs); // ""


    return 0;
}
