#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next; // Store the next node.
        current->next = prev; // Reverse the next pointer.
        prev = current; // Move prev to the current node.
        current = nextNode; // Move current to the stored next node.
    }

    return prev; // prev is now the new head of the reversed list.
}

// Helper function to print the linked list.
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original linked list: ";
    printList(head);

    // Reversing the linked list.
    head = reverseList(head);

    std::cout << "Reversed linked list: ";
    printList(head);

    return 0;
}
