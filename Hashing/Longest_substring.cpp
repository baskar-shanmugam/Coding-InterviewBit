/*
 Given a string, 
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.*/

int Solution::lengthOfLongestSubstring(string A) {
    char start = A[0];
    char end = A[0];
    vector<int> len;
    map<char,int> m;
    if (A.length() == 0) {
        return 0;
    }
    
    for(int i = 0; i < A.length()-1;) {
        m.clear();
        start = A[i];
        m.insert(pair<char,int>(start,i));
        for (int j = i+1; j < A.length(); j++) {
            end = A[j];
            auto itr = m.find(end);
            if ( itr != m.end()) {
                len.push_back(j-i);
                i = itr->second+1;
                break;
            }
            else {
                m.insert(pair<char,int>(end,j));
                if(j+1 == A.length()) {
                    len.push_back(j-i+1);
                    i++;
                }
            }
        }
        
    }
    sort(len.begin(),len.end(),greater<int>());
    if (len.size()) {
        return len[0];
    }
    return 1;
    
}

