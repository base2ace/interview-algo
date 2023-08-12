https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:


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

        ListNode *answer = new ListNode(0);
        ListNode *current = answer;
        int carry = 0;
        auto node1 = l1;
        auto node2 = l2;
        
        while(node1 != nullptr || node2 != nullptr || carry !=0 )
        {
            int digit1 = node1 != nullptr ? node1->val : 0;
            int digit2 = node2 != nullptr ? node2->val : 0;

            int sum = digit1 + digit2 + carry;
            auto digit = sum % 10;

            // create a new node to store the new digit.
            auto digitNode = new ListNode(digit);
            current->next = digitNode;
            current = digitNode;

            carry = sum / 10;
     
            node1 = node1 != nullptr ? node1->next : nullptr;
            node2 = node2 != nullptr ? node2->next : nullptr;
        }

        return answer->next;
        
    }
};
