#include <iostream>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int total = 0;
        
        while(temp != NULL)
        {
            total++;
            temp = temp->next;
        }
        
        if(total == 1 || total == 0)
            return NULL;
        
        temp = head;
        
        if(total == n)
        {
            head = head->next;
            return head;
        }
        
        for(int i = 0; i < (total - n) - 1; i++)
        {
            temp = temp->next;
        }
        
        if(temp->next->next != NULL)
        {
            temp->next = temp->next->next;
        }else{
            temp->next = NULL;
        }
        
        return head;
    }
};