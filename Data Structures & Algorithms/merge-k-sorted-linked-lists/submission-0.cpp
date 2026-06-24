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
    ListNode *merge2(ListNode *l1,ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *res=&dummy;
        if(!l1)
        {
            return l2;
        }
        if(!l2)
        {
            return l1;
        }
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                res->next=l1;
                l1=l1->next;

            }
            else
            {
                res->next=l2;
                l2=l2->next;
            }
            res=res->next;

        }
        if(!l1)
        {
            res->next=l2;
        }
        else
        {
            res->next=l1;
        }
        return dummy.next;
    }
    ListNode *solve(vector<ListNode *> list,int l,int r)
    {
        if(l==r)
        {
            return list[l];
        }
        int mid=(l+r)/2;
        ListNode *left=solve(list,l,mid);
        ListNode *right=solve(list,mid+1,r);
        return merge2(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return NULL;
        }
        return solve(lists,0,lists.size()-1);
        
    }
};
