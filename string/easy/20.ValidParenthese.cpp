/*20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.


Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false


Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid_1(string s) {
        bool valid = true;
        stack<char> st;

        for(int i=0; i < s.size(); i++) {
            char c = s[i];
            if (st.empty()) 
            {
                st.push(c);
                continue;
            }

            char top_c = st.top();
            switch (c)
            {
                case ')':
                    if (top_c != '(')
                    {
                        valid = false;
                    }
                    break;
                case ']':
                    if (top_c != '[')
                    {
                        valid = false;
                    }
                    break;

                case '}':
                    if (top_c != '{')
                    {
                        valid = false;
                    }
                    break;
            }

            if (not valid) 
            {
                break;
            }
            
            if ((c == ')' or c== ']' or c=='}') and valid and st.size())
            {
                st.pop();
                continue;
            }

            st.push(c);
        }

        std::cout << s << ":\t" <<  st.empty() << endl;
        return st.empty();
    }

    bool isValid(string s) {
        stack<char> st; // create an empty stack to store opening brackets
        for (char c : s) { // loop through each character in the string
            if (c == '(' || c == '{' || c == '[') { // if the character is an opening bracket
                st.push(c); // push it onto the stack
            }
            else { // if the character is a closing bracket
                if (st.empty() || // if the stack is empty or 
                    (c == ')' && st.top() != '(') || // the closing bracket doesn't match the corresponding opening bracket at the top of the stack
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false; // the string is not valid, so return false
                }
                st.pop(); // otherwise, pop the opening bracket from the stack
            }
        }
        return st.empty(); // if the stack is empty, all opening brackets have been matched with their corresponding closing brackets,
                           // so the string is valid, otherwise, there are unmatched opening brackets, so return false
    }
};

int main()
{
    Solution sol = Solution();
    string s = "()";
    sol.isValid(s);  //true

    s = "()[]{}";   //true
    sol.isValid(s);

   
    s = "{[]}";
    sol.isValid(s);  //true

    s = "(]";       //false
    sol.isValid(s);

    s = "[";
    sol.isValid(s);  //false

    return 0;
}
