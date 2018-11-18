/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3*/

int Solution::singleNumber(const vector<int> &A) {
    map<int,int> cnt;
    for(auto e: A) {
        auto it = cnt.find(e);
        if (it != cnt.end())
        {
            it->second++;
        } else
        {
            cnt[e] = 1;
        }
        
    }
    for (auto itr = cnt.begin(); itr != cnt.end(); ++itr) 
    { 
        if (itr->second ==1)
            return itr->first;
    } 
    return 0;
}
