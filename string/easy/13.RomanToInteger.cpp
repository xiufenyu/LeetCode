
/*
13. Roman to Integer
Easy

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

 
Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

*/
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// IV            4
// IX            9
// XL            40
// XC            90
// CD            400
// CM            900

// II            2
// XX            20
// XXX           30
// CC            200
// CCC           300
unordered_map<char, int> symbols = {
    {'I',   1},
    {'V',   5},
    {'X',   10},
    {'L',   50},
    {'C',   100},
    {'D',   500},
    {'M',   1000}
};

unordered_map<string, int> specials = {
    {"IV", 4},
    {"IX", 9},
    {"XL", 40},
    {"XC", 90},
    {"CD", 400},
    {"CM", 900},
};


class Solution {
public:
    // Method 1: 
    int romanToInt(string s) {
        int result = 0, index =0;
        while (index <= s.size()-1) {
            char cur = s[index];
            char next = s[index+1];
            string str = string{cur} + string{next};
            if (specials.find(str)!=specials.end())
            {
                result = result + specials[str];
                index += 2;
            }
            else
            {
                int cur_value = symbols[cur];
                result = result + cur_value;
                index = index + 1;
            }
        }

        std::cout << s << "\t" << result << endl;
        return result;
    }

    // Method 2: compare current value and next value
    int romanToInt_2(string s) {
        unordered_map<char, int> symbols;
        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;
        
        int ans = 0;
        
        for(int i = 0; i < s.length(); i++){

            if(symbols[s[i]] < symbols[s[i+1]]){
                ans -= symbols[s[i]];
            }
            else{
                ans += symbols[s[i]];
            }
        }
        return ans;
    }
};


int main()
{
    Solution sol = Solution();
    sol.romanToInt("I");
    sol.romanToInt("III");
    sol.romanToInt("IV");
    sol.romanToInt("V");

    sol.romanToInt("LVIII");  // 58
    sol.romanToInt("MCMXCIV");  // 1994

    sol.romanToInt("XX");

    sol.romanToInt("DCXXI");  // 621

    return 0;
}
