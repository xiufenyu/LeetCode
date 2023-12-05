/*141. Linked List Cycle
Easy

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
*/


#include <iostream>
#include <set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // method 1: set
    bool hasCycle_1(ListNode *head) {
        std::set<ListNode *> s;
        auto ptr = head;
        while(ptr) {
            if (s.find(ptr->next) != s.end())
            {
                return true;
            }
            s.insert(ptr);
            ptr = ptr->next;
        }
        return false;
    }

    // method 2: brute force
    bool hasCycle_2(ListNode *head) {
        if (nullptr == head or nullptr==head->next)
        {
            return false;
        }
        
        auto slow = head;
        auto fast = head->next;

        while (slow and fast and fast->next)
        {
            if (slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }

};

int main()
{
    Solution sol = Solution();
    // [-1,-7,7,-4,19,6,-9,-5,-2,-5]
    ListNode* list = new ListNode(-1); 
    list->next = new ListNode(-7);
    list->next->next = new ListNode(7);
    list->next->next->next = new ListNode(-4);
    list->next->next->next->next = new ListNode(19);
    list->next->next->next->next->next = new ListNode(6);
    list->next->next->next->next->next->next = new ListNode(-9);
    list->next->next->next->next->next->next->next = new ListNode(-5);
    list->next->next->next->next->next->next->next->next = list->next->next->next->next->next;

    // sol.hasCycle(list);
    return 0;
}
 
