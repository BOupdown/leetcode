//      https://leetcode.com/problems/merge-two-sorted-lists/
#include <iostream>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL)
            return NULL;
        
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* res = new ListNode;
        ListNode* tempRes = res;
        
        while(temp1 != NULL || temp2 != NULL)
        {
            if(temp1 != NULL && temp2 != NULL)
            {
                if(temp1->val < temp2->val)
                {
                    tempRes->val = temp1->val;
                    temp1 = temp1->next;
                }else{
                    tempRes->val = temp2->val;
                    temp2 = temp2->next;
                }
            }
            else if(temp1 == NULL)
            {
                tempRes->val = temp2->val;
                temp2 = temp2->next;
            }else{
                tempRes->val = temp1->val;
                temp1 = temp1->next;
            }
            
            if(temp1 != NULL || temp2 != NULL)
            {
                tempRes->next = new ListNode;
                tempRes = tempRes->next;
            }
            
        }
        
        return res;
    }
};
