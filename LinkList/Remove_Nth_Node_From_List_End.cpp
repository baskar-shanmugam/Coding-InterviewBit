/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

 Note:
If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int getLinkLength(ListNode *A) {
    if (A == NULL)
        return 0;
    int len = 0;
    while(A) {
        len++;
        A = A->next;
    }
    return len;
 }
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if (B == 0) {
        return A;
    }
    int len = getLinkLength(A);
    
    if (len == 0) {
        return NULL;
    }

    int mov = 0;
    if (B > len || (B == len)) {
        ListNode* tmp = A->next;
        free(A);
        A = tmp;
        return A;
    } else {
        mov = len - B;
    }
    
    ListNode *movL = A;
    ListNode *prev = A;
    while(mov) {
        prev = movL;
        movL = movL->next;
        mov--;
    }
    prev->next = movL->next;
    free(movL);
    return A;
}

