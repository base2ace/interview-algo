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
    // Create a dummy node to serve as the starting point of the answer linked list.
    ListNode *answer = new ListNode(0);
    ListNode *current = answer; // Pointer to the current node in the answer linked list.
    int carry = 0; // Initialize carry to 0.
    auto node1 = l1; // Pointer to traverse l1 linked list.
    auto node2 = l2; // Pointer to traverse l2 linked list.
    
    // Traverse through both linked lists and handle carry until both lists are processed and carry is 0.
    while (node1 != nullptr || node2 != nullptr || carry != 0) {
        // Extract the digits from the current nodes of l1 and l2.
        int digit1 = node1 != nullptr ? node1->val : 0;
        int digit2 = node2 != nullptr ? node2->val : 0;

        // Calculate the sum of digits from l1, l2, and carry.
        int sum = digit1 + digit2 + carry;
        
        // Calculate the new digit for the current position.
        auto digit = sum % 10;

        // Create a new node to store the new digit in the answer linked list.
        auto digitNode = new ListNode(digit);
        
        // Link the new digit node to the current node in the answer linked list.
        current->next = digitNode;
        current = digitNode; // Move the current pointer to the newly added digit node.
        
        // Calculate the carry for the next iteration.
        carry = sum / 10;

        // Move to the next nodes in l1 and l2 if they are not nullptr.
        node1 = node1 != nullptr ? node1->next : nullptr;
        node2 = node2 != nullptr ? node2->next : nullptr;
    }

    // The answer linked list starts from the node after the dummy node.
    return answer->next;
}

};
