/*
Reverse a linked list. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.*/

// Reverses the linkedList which starts from head
// Returns the end node which is the head of the reversed list.  
ListNode *reverseList(ListNode *head) {
 if (head == NULL) return head; 
 ListNode *cur = head, *nextNode, *prevNode;
 prevNode = NULL;
 while (cur != NULL) {
  nextNode = cur->next;
  cur->next = prevNode;
  prevNode = cur;
  cur = nextNode;
 }
 head = prevNode;
 return head;
}
