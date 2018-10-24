/*
Determine whether an integer is a palindrome. Do this without extra space.

A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
Negative numbers are not palindromic.*/

int Solution::isPalindrome(int A) {
    if (A < 0)
        return 0;
        
    string num = std::to_string(A);
    for(int i =0, j = num.length()-1; i <= j; i++, j--) {
        if (num[i] != num[j]) {
            return 0;
        }
    }
    return 1;
}
