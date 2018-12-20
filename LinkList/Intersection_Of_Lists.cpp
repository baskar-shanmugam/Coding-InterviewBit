/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

 Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int getLinkLength(ListNode *lh) {
     int len = 1;
     if (lh == NULL) {
         return 0;
     }
     while (lh->next != NULL) {
         len++;
         lh = lh->next;
     }
     return len;
 }
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int lenA = getLinkLength(A);
    int lenB = getLinkLength(B);
    
    ListNode *movL = A;
    ListNode *movS = B;
    int movLen = lenA - lenB;
    if (lenB > lenA) {
        movLen = lenB - lenA;
        movL = B;
        movS = A;
    } 
   // std::cout << "len: " << movL << " s" << movS;
    while (movLen) {
        movL = movL->next;
        movLen--;
    }
    
    while (movL != NULL && movS != NULL) {
        if (movL == movS) {
            return movL;
        }
        movL = movL->next;
        movS = movS->next;
    }
    
    return NULL;
    
}

