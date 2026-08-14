class LRUCache {
public:
    class ListNode{
        public:
            int key,val;
            ListNode* next,*prev;
            ListNode(int _key,int _val){
                key=_key;
                val=_val;
            }
    };
    void deleteNode(ListNode* node){
        ListNode* nextNode=node->next;
        ListNode* prevNode=node->prev;
        nextNode->prev=prevNode;
        prevNode->next=nextNode;
    }
    void insertAfterHead(ListNode* node){
        ListNode* currAfterHead=head->next;
        head->next=node;
        node->prev=head;
        node->next=currAfterHead;
        currAfterHead->prev=node;
    }
    map<int,ListNode*> mpp;
    int capacity_;
    ListNode* head=new ListNode(-1,-1),*tail=new ListNode(-1,-1);;
    LRUCache(int capacity) {
        capacity_=capacity;
        mpp.clear();
        head->next=tail;
        tail->prev=head;
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        ListNode* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;   
    }
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            ListNode* node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }else{
            if(mpp.size()==capacity_){
                ListNode* node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            ListNode* node=new ListNode(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */