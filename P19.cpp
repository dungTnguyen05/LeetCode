/*
19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

Follow up: Could you do this in one pass?
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

// follow up: one pass - maintain 2 ptrs with delay of n nodes
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size = 1;

        while (curr -> next) {
            curr = curr -> next;
            size++;
        }

        curr = head;

        if (size == 1) {
            head = nullptr;
            return head;
        }

        for (int i = 2; i < size - n + 1; i++) {
            curr = curr -> next;
        }

        if (n == 1) {
            delete curr -> next;
            curr -> next = nullptr;
            return head;
        }

        if (n == size) {
            head = curr -> next;
            delete curr;
            return head;
        }

        ListNode* temp = curr -> next -> next;
        delete curr -> next;
        curr -> next = temp;

        return head;
    }
};