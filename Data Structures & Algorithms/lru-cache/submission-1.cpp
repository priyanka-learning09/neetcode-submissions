class LRUCache {
public:
    struct node
    {
        int key;
        int val;
        struct node *next;
        struct node *prev;
        node(int k,int v)
        {
            key=k;
            val=v;
            next=NULL;
            prev=NULL;
        }
    };
     node *dummy,*tail;

    void insertatfront(node *temp)
    {
        temp->next=dummy->next;
        dummy->next->prev=temp;
        dummy->next=temp;
        temp->prev=dummy;
    }
    void delnode()
    {
        node *temp = tail->prev;
temp->prev->next = tail;
tail->prev = temp->prev;
    }
    int cap;
    unordered_map<int,node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        dummy=new node(-1,-1);
        tail=new node(-1,-1);
        dummy->next=tail;
        tail->prev=dummy;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        node *temp=mp[key];
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        insertatfront(temp);
        return temp->val;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            node *temp=mp[key];
            temp->val=value;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            insertatfront(temp);
            return;

        }
        if(mp.size()==cap)
        {
            mp.erase(tail->prev->key);
            delnode();
        }
        node *newnode=new node(key,value);
        insertatfront(newnode);
        mp[key]=newnode;
        
    }
};
