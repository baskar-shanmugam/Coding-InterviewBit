/*Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    
    ListNode *h = A;
    ListNode *pp = NULL;
    ListNode *tmp;
    ListNode *p = h;
    bool skip = true;
    while(h) {
        if (!skip) {
            p->next = h->next;
            h->next = p;
            if (p == A) {
                A = h;
            }
            if(pp) {
                pp->next = h;
            }
            pp = p;
            skip = true;
            h = h->next;
        } else {
            skip = false;
        }
        p = h;
        h = h->next;
    }
    return A;
}

