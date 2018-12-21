/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
        j < i AND
	    A[j] < A[i]
	    Elements for which no smaller element exist, consider next smaller element as -1.

	    Example:

	    Input : A : [4, 5, 2, 10, 8]
	    Return : [-1, 4, -1, 2, 2]

	    Example 2:

	    Input : A : [3, 2, 1]
	    Return : [-1, -1, -1]*/


vector<int> Solution::prevSmaller(vector<int> &A) {
    std::vector<int> s;
    std::stack<int> min;
    bool done = false;
    for (int i = 0; i < A.size(); i++) {
        if (i == 0) {
            min.push(A[i]);
            s.push_back(-1);
        } else {
            while(!min.empty() && !done) {
                if (min.top() >= A[i]) {
                    min.pop();
                } else {
                    s.push_back(min.top());
                    min.push(A[i]);
                    done = true;
                }
            }
            done = false;
        }
       // cout << "i" << i << " item " << A[i];
    }
    return s;
}
