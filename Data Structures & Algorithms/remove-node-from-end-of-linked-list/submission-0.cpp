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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode dummy(0);
        dummy.next=head;
        ListNode *first=&dummy,*second=&dummy;
        for(int i=0;i<n;i++)
        {
            second=second->next;
        }
        while(second->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
        ListNode *delnode=first->next;
        first->next=delnode->next;
        delete delnode;
        return dummy.next;

        
        
    }
};
