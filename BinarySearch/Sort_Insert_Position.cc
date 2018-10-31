/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0*/
int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int start = 0;
    int end = A.size() - 1;
    int mid = 0;
    bool moveright = false;
    while (start <= end) {
        mid = (start + end) / 2;
        if (A[mid] == B) {
            return mid;
        } else if (B > A[mid]) {
            start = mid + 1;
            moveright = true;
        } else {
            moveright = false;
            end = mid - 1;
        }
    }
    if (moveright)
        return mid + 1;
    return mid;
}

