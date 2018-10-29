/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.*/


int Solution::lengthOfLastWord(const string A) {
    int end = A.length()-1;
    int start = 0;
    int len = 0;
    bool last = false;
    while (end >= start) {
        if(A[end] != ' ') {
            if(!last) {
                last = true;
            }
            len++;
        } else {
            if(last) {
                return len;
            }
        }
        end--;
    }
    return len;
}

