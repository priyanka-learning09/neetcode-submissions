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
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *sec=slow->next;
        slow->next=NULL;
        ListNode *curr=sec,*prev=NULL,*next;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        sec=prev;
        
        while(sec!=NULL)
        {
            ListNode *t1=head->next;
            ListNode *t2=sec->next;
            head->next=sec;
            sec->next=t1;
            head=t1;
            sec=t2;
        }
        
    }
};
