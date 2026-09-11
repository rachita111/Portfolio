class Solution {
public:
    ListNode* reverseLL(ListNode* head,int stop){
        ListNode* temp=head;
        ListNode* prev=NULL;
        int i=0;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
            i++;
            if(i==stop) break;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head1, int left, int right) {
        ListNode* head2 = new ListNode(-1);
        head2->next=head1;
        ListNode* temp1=head2,*temp2=head2,*temp3=head2;
        int i=0,j=0,k=0;
        while(i<left) {
            temp2=temp2->next;
            i++;
        }
        while(j<left-1){
        temp1=temp1->next;
        j++;
        }
        while(k<=right){
            temp3=temp3->next;
            k++;
        }
        int reverse=right-left+1; 
        ListNode* newHead=reverseLL(temp2,reverse);
        temp1->next=newHead;
        temp2->next=temp3;
        return head2->next;
    }
};