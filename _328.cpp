/*
LeetCode 328 – Odd Even Linked List
----------------------------------
Problem (re-phrased):
Rearrange a singly linked list so that all nodes at odd indices (1-based)
come first followed by nodes at even indices, preserving their original
relative order.  Return the head of the re-ordered list.

Input
 • ListNode* head – head of the singly-linked list (may be nullptr).

Output
 • ListNode* – head of the reorganized list.
----------------------------------
*/

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next || !head->next->next) {
                // For 0, 1, or 2 nodes, the list is already effectively sorted
                // or no change is needed.
                return head;
            }

            ListNode* odd_tail = head;          // Current tail of the odd-indexed list
            ListNode* even_tail = head->next;   // Current tail of the even-indexed list
            ListNode* even_head = head->next;   // Head of the even-indexed list (to connect later)

            // We need to ensure even_tail and even_tail->next are valid to continue linking.
            // odd_tail will always be valid if even_tail and its next are.
            while (even_tail != nullptr && even_tail->next != nullptr) {
                // Link next odd node: odd_tail's next skips current even_tail
                odd_tail->next = even_tail->next;
                odd_tail = odd_tail->next; // Move odd_tail to the new end of odd list

                // Link next even node: even_tail's next skips new odd_tail
                // It's important that odd_tail has been updated first.
                even_tail->next = odd_tail->next;
                even_tail = even_tail->next; // Move even_tail to the new end of even list
            }

            // Connect the end of the odd list to the head of the even list
            odd_tail->next = even_head;

            return head;
        }
};