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
        if(head==NULL)
        {
            return NULL;
        }
        Node *temp=head;
        while(temp!=NULL)
        {
            Node *newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            if(temp->random==NULL)
            {
                temp->next->random=NULL;
            }
            else
            {
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        Node *newhead=head->next;

        temp=newhead;
        while(head!=NULL)
        {
            head->next=head->next->next;
            if(temp->next!=NULL)
            {
                temp->next=temp->next->next;
            }
            head=head->next;
            temp=temp->next;
        }
    return newhead;
        
    }
};
