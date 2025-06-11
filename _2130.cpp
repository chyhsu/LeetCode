/*
LeetCode 2130 – Maximum Twin Sum of a Linked List
------------------------------------------------
Problem (re-phrased):
In a linked list of even length, the twin of the ith node (0-indexed) is
the (n−1−i)th node.  The twin sum is the sum of a node’s value and its
twin’s value.  Return the maximum twin sum of all node pairs.

Input
 • ListNode* head – head of a singly-linked list with an even number of
   nodes (2 ≤ n ≤ 10⁵).

Output
 • int – maximum twin sum.
------------------------------------------------
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
    int pairSum(ListNode* head) {
        if (!head || !head->next) return 0;
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Now prev is the head of the reversed second half
        int maxSum = 0;
        ListNode* first = head;
        ListNode* second = prev;        
        while (second) {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }
        
        return maxSum;
    }
};