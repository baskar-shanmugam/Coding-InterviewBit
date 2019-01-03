/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> idx;
    
    if (A.size() == 0 || B.size() == 0) {
        return idx;
    }
    
    int b_slen = B[0].size();
    int b_vlen = B.size();
    
    map<string,int> b_str;
    for(auto s: B) {
        int cnt = 1;
        auto itr = b_str.find(s);
        if ( itr != b_str.end()) {
            cnt = itr->second + 1;
        }
        b_str[s] = cnt;
    }
    
    for(int i = 0; i < A.size();) {
        map<string,int> m_str = b_str;
        int match_cnt = 0;
        int j = 0;
        bool done = false;
        for (j = i; j < A.size(); j= j+b_slen) {

            string tmp = A.substr(j, b_slen);
            if (b_str.find(tmp) != b_str.end()) {
                match_cnt++;
               if (m_str[tmp]) {
                    m_str[tmp]--;
                } else {
                    break;
                }
            } else {
                i++;
                done = true;
                break;
            }
            if (match_cnt == b_vlen)
                break;
        }
        if (match_cnt == b_vlen) {
            idx.push_back(i);
        }
        if (!done)
        i++;
        done = false;
    }
    return idx;
}

