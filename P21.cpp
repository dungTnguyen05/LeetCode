/*
21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list. 

https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *merged_list = new ListNode();
        ListNode *temp = merged_list;

        while (list1 != NULL && list2 != NULL) {
            if (list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            }

            else {
                temp -> next = list2;
                list2 = list2 -> next;
            }

            temp = temp -> next;
        }     

        while (list1 != NULL) {
            temp -> next = list1;
            list1 = list1 -> next;
            temp = temp -> next;
        }

        while (list2 != NULL) {
            temp -> next = list2;
            list2 = list2 -> next;
            temp = temp -> next;
        }

        return merged_list -> next;
    }
};