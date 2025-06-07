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
        ListNode* deleteMiddle(ListNode* head) {
            int count=1;
            ListNode* temp=head;
            while(temp->next!=NULL){
                count++;
                temp=temp->next;
            }
       
            if(count==1){
                return NULL;
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