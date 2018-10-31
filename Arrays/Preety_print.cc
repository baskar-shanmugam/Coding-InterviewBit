/*
rint concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean.

Example 1:

Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
Example 2:

Input: A = 3.
Output:

3 3 3 3 3 
3 2 2 2 3 
3 2 1 2 3 
3 2 2 2 3 
3 3 3 3 3 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.

You will be given A as an argument to the function you need to implement, and you need to return a 2D array.*/
vector<vector<int> > Solution::prettyPrint(int A) {
    int N = A + (A-1);
    vector<vector<int>> vec(N);
    for (int i = 0; i < N; i++) {
        vec[i] = vector<int>(N);
    }
    for (int R = 0; R < A; R++) {
        for (int C = R; C < (N-R); C++) {
            int val = A - R;
            vec[R][C] = val;
            vec[(N-R-1)][C] = val;
            vec[C][R] = val;
            vec[C][(N-R-1)] = val;
        }
    }
    return vec;
}
