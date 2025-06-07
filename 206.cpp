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



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            // Handle empty list or list with a single node
            if (head == nullptr || head->next == nullptr) {
                return head;
            }
            ListNode* r=head->next;
            ListNode* l=head;
            ListNode* lh=nullptr;
            while(r!=nullptr){
                l->next=lh;
                lh=l;
                l=r;
                r=l->next;
            }
            l->next=lh;
            return l;

        }
    };

//Reference Solution

//  class Solution {
//     public:
//         ListNode* reverseList(ListNode* head) {
//             ListNode* prev=NULL;
//             ListNode* curr=head;
//             ListNode* forward=NULL;
//             while(curr!=NULL){
//                 forward=curr->next;
//                 curr->next=prev;
//                 prev=curr;
//                 curr=forward;
//             }
    
//             return prev;
//         }
//     };