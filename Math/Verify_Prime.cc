/*
Given a number N, verify if N is prime or not.

Return 1 if N is prime, else return 0.

Example :

Input : 7
Output : True*/

int Solution::isPrime(int A) {
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
    if (fact.size() == 2)
        return true;
    else
        return false;
}
