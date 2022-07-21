class Solution {
public:
    ListNode* successor;

    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            //successor: the node after the first n nodes
            successor = head->next;
            return head;
        }

        ListNode* rhead = reverseN(head->next, n-1);

        //head is now the new tail of reversed list
        head->next->next = head;
        head->next = successor;

        return rhead;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(m == 1){
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m-1, n-1);

        return head;
    }
};