/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.*/




int Solution::firstMissingPositive(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        while (A[i] > 0 && A[i] < A.size() + 1) {
            if (A[i] == (i + 1)) {
               // A[i] = 0;
                break;
            }
            
            int curr = A[i];
            int temp = A[curr - 1];
            if (A[curr-1] == curr)
                break;
            A[curr-1] = curr;
            A[i] = temp;
            
        }
    }
    int j;
    for (j = 0; j < A.size(); j++) {
        if (A[j] != j+1)
            return j+1;
    }
    return j+1;
}

