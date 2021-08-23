//      https://leetcode.com/problems/add-two-numbers/
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //add, ret, res
        int add = 0;
        int ret = 0;
        ListNode* res = new ListNode;
        ListNode* retour = res;

        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL)
            {
                add = (l2->val + ret) % 10;
                ret = (l2->val + ret) / 10;
            }
            else if(l2 == NULL)
            {
                add = (l1->val + ret) % 10;
                ret = (l1->val + ret) / 10;
            }
            else
            {
                add = (l1->val + l2->val + ret) % 10;
                ret = (l1->val + l2->val + ret) / 10;
            }

            res->val = add;

            if(l1 != NULL)
            {
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                l2 = l2->next;
            }

            if(l1 != NULL || l2 != NULL)
            {
                res->next = new ListNode;
                res = res->next;
            }


        }

        if(ret != 0)
        {
            res->next = new ListNode;
            res = res->next;

            res->val = ret;
        }

        return retour;
    }
};
