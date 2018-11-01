/*
Given 2 non negative integers m and n, find gcd(m, n)

GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.
Both m and n fit in a 32 bit signed integer.

Example

m : 6
n : 9

GCD(m, n) : 3 
 NOTE : DO NOT USE LIBRARY FUNCTIONS */

int Solution::gcd(int A, int B) {
    int temp;
    if (A <= B)
        temp = A;
    else
        temp = B;
    if (A == 0 && B == 0)
        return 0;
    if (A == 0)
        return B;
    if (B==0)
        return A;
    vector<int> div;
    div.push_back(1);
    for (int i = 2; i <= sqrt(temp); i++) {
        if (temp%i == 0) {
            div.push_back(i);
            if (temp/i != i) {
                div.push_back(temp/i);
            }
        }
    }
    div.push_back(temp);
    sort(div.begin(), div.end(), std::greater<int>());
  // for (auto i: div)
    //    cout<< i;
    //cout << std::endl;
    int cmp;
    if (A <= B)
        cmp = B;
    else
        cmp = A;
     for (auto i: div) {
         
        if (cmp%i == 0)
            return i;
    }
}

