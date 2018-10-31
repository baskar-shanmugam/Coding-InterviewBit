/*
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY*/

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long start = 0;
    long end = A;
    long mid = 0;
    long firstsq = 0;
    while(start <= end) {
        mid = (start+end)/2;
        long sqrt = (mid * mid);
        if (sqrt == A) {
            return mid;
        } else if (sqrt > A) {
            end = mid - 1;
        } else {
            start = mid + 1;
            firstsq = mid;
        }
    }
    return firstsq;
    
}

