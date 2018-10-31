/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].*/

int findpos(const vector<int> &A, int b, bool left) {
    int start = 0;
    int end = A.size() -1;
    int mid = 0;
    int retpos = -1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (A[mid] == b) {
            retpos = mid;
            if (left) {
                end = mid - 1;
            } else {
                start = mid +1;
            }
        } else if (b > A[mid]) {
            start = mid +1;
        } else {
            end = mid - 1;
        }
    }
    return retpos;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> sol(2);
    sol[0] = findpos(A, B, true);
    sol[1] = findpos(A, B, false);
   // for (int i : sol) {
     //   cout<< "pos: " << i;
    //}
    return sol;
}

