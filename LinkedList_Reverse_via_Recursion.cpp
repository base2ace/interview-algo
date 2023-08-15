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
    ListNode* reverseList(ListNode* head) 
    {
        // Base case: an empty list or a list with a single node is already reversed.
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Reverse the rest of the list.
        ListNode* restReversed = reverseList(head->next);

        // Change the next pointer of the current node to point to the previous node.
        head->next->next = head;
        head->next = nullptr;

        return restReversed;

    }
};
