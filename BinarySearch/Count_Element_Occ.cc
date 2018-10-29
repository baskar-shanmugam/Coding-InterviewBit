/*
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.

PROBLEM APPROACH :

For complete solution, look at the hint.*/

int BinarySearchT(const vector<int> &A, int elem, bool searchFirst) {
    if (A.size() == 0)
        return -1;
    int start = 0;
    int end = A.size()-1;
    int mid;
    int result = -1;
    while (start<= end) {
        mid = (start+end)/2;
        if(A[mid] == elem) {
            result = mid;
            if (searchFirst) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else if (A[mid] > elem ) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
     //   mid = (start + end)/2;
    }
    return result;
}

int Solution::findCount(const vector<int> &A, int B) {
    int first = BinarySearchT(A,B,true);
    if (first == -1) {
        return 0;
    }
    
    
    int last = BinarySearchT(A,B,false);
  //  cout<<"first: " << first << " last: " << last << " ";
    return (last - first + 1);
}

