/*You are given two non-empty linked lists representing two non-negative integers.
 *
 * The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 */


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


int main()
{
    Solution somme;

    return 0;

}