/*Find the intersection of two sorted arrays.
OR in other words,
Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example :

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 3 5]

Output : [3 3 5]

Input : 
    A : [1 2 3 3 4 5 6]
    B : [3 5]

Output : [3 5]
 NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output. */

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> match;
    int b_e = 0;
    for (int a_e = 0; a_e < A.size(); a_e++) {
        for (;b_e < B.size();) {
            if (A[a_e] == B[b_e]) {
                match.push_back(B[b_e]);
                b_e++;
                break;
            }
            if (A[a_e] < B[b_e]) {
                break;
            } else {
                b_e++;
            }
        }
    }
    return match;
}
