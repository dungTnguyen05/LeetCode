/*
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* res = new ListNode;
        ListNode* res_head = res;
        int carry = 0;

        while (curr1 || curr2 || carry) {
            int temp = carry;

            if (curr1) {
                temp += curr1 -> val;
                curr1 = curr1 -> next;
            }

            if (curr2) {
                temp += curr2 -> val;
                curr2 = curr2 -> next;
            }

            res -> val = temp % 10;
            carry = temp/10;
            
            if (curr1 || curr2 || carry) {
                res -> next = new ListNode;
                res = res -> next;
            }
        }

        return res_head;
    }
};