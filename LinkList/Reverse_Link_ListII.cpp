/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

 Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. Note 2:
Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 int getListLength(ListNode* A) {
     int len = 0;
     while (A) {
         len++;
         A = A->next;
     }
     return len;
 }
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (B==C) {
        return A;
    }
    int len = getListLength(A);

    if (B > len || C > len || C < B || B < 1) {
        return NULL;
    }
    
    ListNode* prevB;
    ListNode* nextB;
    ListNode* currB;
    ListNode* nextC;
    ListNode* curr = A;
    ListNode* next = NULL;
    ListNode* prev = A;
    int cnt = 1;
    int cntb = 0;
    while (curr) {
      if (cnt >= B) {
        
        if (cnt == B) {
            prevB = prev;
            nextB = curr->next;
            currB = curr;
            cntb = cnt;
            cnt++;
            prev = curr;
            curr = curr->next;
        } else {

            if (cnt == C) {
                nextC = curr->next;
                curr->next = prev;
                prevB->next = curr;
                currB->next = nextC;
                nextB->next = currB;
               if (prevB == A && B == 1) {
                    A = curr;
                }
                return A;
            }
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;

        }
      }
      else {
        cnt++;
        prev = curr;
        curr = curr->next;
      }
    }
}

