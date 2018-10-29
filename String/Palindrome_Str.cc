/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/

int Solution::isPalindrome(string A) {
    int start = 0;
    int end = A.length()-1;
    int ret = 1;
    while (start < end) {
        char st = A[start];
        char e = A[end];
        if(!isalnum(st)) {
            start++;
            continue;
        }
        if(!isalnum(e)) {
            end--;
            continue;
        }
        if (tolower(st) == tolower(e)) {
            start++;
            end--;
        } else {
            return 0;
        }
    }
    return ret;
}
