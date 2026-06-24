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
    void reorderList(ListNode* head) 
    {
        ListNode *fast=head,*slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode *secound=slow->next;
        slow->next=NULL;
        ListNode *first=head;
        ListNode *curr=secound,*prev=NULL,*next;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        secound=prev;
        while(secound!=NULL)
        {
            ListNode *t1=first->next;
            ListNode *t2=secound->next;
            first->next=secound;
            secound->next=t1;
            first=t1;
            secound=t2;
        }

        
        
    }
};
