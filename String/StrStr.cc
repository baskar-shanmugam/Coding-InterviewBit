

/*
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. */

int Solution::strStr(const string A, const string B) {
    int h_len = A.length() - 1;
    int n_len = B.length() - 1;
    if (A.empty() && B.empty())
        return -1;
    if (B.empty())
        return -1;
    int h_s = 0;
    int b_s = 0;
    bool m_s = false;
    int m_si = 0;
    while(h_s <= h_len) {
        if(m_s) {
            if (A[h_s] != B[b_s]) {
                h_s = m_si+1;
                m_s = false;
                b_s = 0;
                m_si = 0;
            }
        }
        if(A[h_s] == B[b_s]) {
            if(!m_s) {
                m_s = true;
                m_si = h_s;
            }
            b_s++;
            if(b_s>n_len)
                return m_si;
        }
        h_s++;
    }
    return -1;
}
