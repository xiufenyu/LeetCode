/*
21. Merge Two Sorted Lists
Easy

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

 
Constraints:
    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
*/

#include <iostream>
using namespace std;

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
    ListNode* mergeTwoLists_1(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1, *ptr2 = list2;
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        while (ptr1 != nullptr and ptr2!=nullptr)
        {
            if (ptr1->val < ptr2->val)
            {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (ptr1 == nullptr) ? ptr2 : ptr1;

        // std::cout<<"new List: " << endl;
        // ptr = head->next;
        // while(ptr != nullptr)
        // {
        //     std::cout<< ptr->val << " " <<endl;
        //     ptr = ptr->next;
        // }
        return head->next;
    }

    // Method 2:
    ListNode* mergeTwoLists_2(ListNode* list1, ListNode* list2) {
        if (nullptr == list1)
        {
            return list2;
        }

        if (nullptr == list2)
        {
            return list1;
        }

        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main()
{
    auto sol = Solution();
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    sol.mergeTwoLists(list1, list2);

    return 0;
}
