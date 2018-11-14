/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]*/

void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> other;
    int count_0 = 0;
    int count_1 = 0;
    int count_2 = 0;
    
    for(auto  e: A) {
        if(e == 0) {
            count_0++;
        } else if (e == 1) {
            count_1++;
        } else if (e == 2) {
            count_2++;
        } else {
            other.push_back(e);
        }
    }
    int i;
    for ( i =0; i < count_0; i++) {
        A[i] = 0;
    }
    for (; i < (count_0+count_1); i++) {
        A[i] = 1;
    }
    for (; i < (count_0+count_1+count_2); i++) {
        A[i] = 2;
    }
    for(auto o: other) {
        A[i] = o;
        i++;
    }
    
}

