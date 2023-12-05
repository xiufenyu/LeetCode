/*
28. Find the Index of the First Occurrence in a String
Easy

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr_1(string haystack, string needle) {
        int index = haystack.find(needle);
        // std::cout << index << endl;
        return index == string::npos ? -1 : index;
    }

     int strStr(string haystack, string needle) {
        for (int i=0; i< haystack.size(); i++) {
            bool match = true;
            for (int j=0; j < needle.size(); j++) {
                if (haystack[i+j] != needle[j]) {
                    match = false;
                    break;
                }
            }

            if (match){
                // std::cout << i << endl;
                return i;
            }
        }
        // std::cout << -1 << endl;
        return -1;
    }
};

int main()
{
    Solution sol = Solution();
    string haystack = string("sadbutsad");
    string needle = string("sad");
    sol.strStr(haystack, needle);

    haystack = string("leetcode");
    needle = string("leeto");
    sol.strStr(haystack, needle);

     haystack = string("helloworld");
    needle = string("llowo");
    sol.strStr(haystack, needle);

    return 0;
}
