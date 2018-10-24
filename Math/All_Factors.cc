/*
Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.
*/

vector<int> Solution::allFactors(int A) {
    vector<int> fact;
    double sq = sqrt(A);
    for(int i = 1; i <= sq; i++) {
        if (A%i == 0)
        {
            fact.push_back(i);
            if (i!=sq)
            fact.push_back(A/i);
        }
    }
    sort(fact.begin(),fact.end());
    return fact;
}
