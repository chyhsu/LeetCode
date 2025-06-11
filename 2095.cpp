/*
LeetCode 2095 – Delete the Middle Node of a Linked List
------------------------------------------------------
Problem (re-phrased):
Given the head of a singly-linked list, delete the middle node and return
the head of the modified list.  For a list of length n, the middle is the
⌊n / 2⌋th node (0-indexed).

Input
 • ListNode* head – head of the singly-linked list, 1 ≤ n ≤ 10⁵.

Output
 • ListNode* – head of the list after deleting its middle node.
------------------------------------------------------
*/



 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
 class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            int count=1;
            ListNode* temp=head;
            while(temp->next!=nullptr){
                count++;
                temp=temp->next;
            }
       
            if(count==1){
                return nullptr;
            }
            int middle=count/2;
           
            temp=head;
            for(int i=0;i<middle-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            return head;
        }
    };