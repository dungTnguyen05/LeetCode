/*
1669. Merge In Between Linked Lists
You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
The blue edges and nodes in the following figure indicate the result:
https://assets.leetcode.com/uploads/2020/11/05/fig1.png
Build the result list and return its head.

Example 1:
https://assets.leetcode.com/uploads/2024/03/01/ll.png
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

Example 2:
https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex2.png
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.

Constraints:
3 <= list1.length <= 10^4
1 <= a <= b < list1.length - 1
1 <= list2.length <= 10^4
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = nullptr;
        ListNode* afterB = nullptr;
        ListNode* curr = list1;

        for (int i = 0; i < b + 2; i++) {
            if (i == a - 1) {
                prevA = curr; 
            }

            else if (i == b + 1) {
                afterB = curr;
            }

            curr = curr -> next;
        }

        curr = list2;

        while (curr && curr -> next) {
            curr = curr -> next;
        }

        ListNode* head2 = list2;
        ListNode* tail2 = curr;

        prevA -> next = head2;
        tail2 -> next = afterB;

        return list1;
    }
};