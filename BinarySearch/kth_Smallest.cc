/*Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

 kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based ) 
NOTE
You are not allowed to modify the array ( The array is read only ). 
Try to do it using constant extra space.

Example:

A : [2 1 4 3 2]
k : 3

answer : 2*/


int Solution::kthsmallest(const vector<int> &A, int B) {
    vector<int> kth;
    int k_c = 0;
   
    if (B > A.size() || B < 1) {
        return -1;
    }

    for(int i = 0; i < A.size(); i++) {
        if (k_c < B) {
            kth.push_back(A[i]);
            k_c++;
           
        } else {
            sort(kth.begin(),kth.end());
            if (A[i] < kth[kth.size()-1]) {
                kth[kth.size()-1] = A[i];
            }
        }
    }

    sort(kth.begin(),kth.end());

    return kth[kth.size()-1];
        
}
