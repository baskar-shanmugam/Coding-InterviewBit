/*
Given a number N >= 0, find its representation in binary.

Example:

if N = 6,

binary form = 110*/

string Solution::findDigitsInBinary(int A) {
    string str = "0";
    int n = A;
    while(n) {
        str << std::to_string(n%2);
        n = n/2;
    }
    std::reverse(str.begin(),str.end());
    return str;
}
