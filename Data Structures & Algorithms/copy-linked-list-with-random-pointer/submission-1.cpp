/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
        {
            return NULL;
        }
        Node *temp=head;
        while(temp!=NULL)
        {
            Node *newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=newnode->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->random==NULL)
            {
                temp->next->random=NULL;
            }
            else
                temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        Node *newhead=head->next,*curr=head,*newcurr=head->next;
        while(curr!=NULL)
        {
            curr->next=newcurr->next;
            if(curr->next==NULL)
            {
                newcurr->next=NULL;
            }
            else

                newcurr->next=curr->next->next;
            curr=curr->next;
            newcurr=newcurr->next;
        }

        return newhead;
    }
};
