/*
83. Remove Duplicates from Sorted List
Easy
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates_1(ListNode* head) {
        auto ptr = head;
        if (ptr == nullptr or ptr->next == nullptr)
        {
            return head;
        }
        while (ptr->next !=nullptr)
        {
            if (ptr->val == ptr->next->val)
            {
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr = ptr->next;
            }
        }

        return head;
    }

    // Shorter answer:
    ListNode* deleteDuplicates_2(ListNode* head) {
        auto ptr = head;
        while (ptr and ptr->next)
        {
            if (ptr->val == ptr->next->val)
            {
                ptr->next = ptr->next->next;
                continue;
            }
            ptr = ptr->next;
        }

        return head;
    }

};
