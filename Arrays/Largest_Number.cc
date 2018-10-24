/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.*/

bool get_high_bit(int x, int y) {
    std::string xy = std::to_string(x) + std::to_string(y);
    std::string yx = std::to_string(y) + std::to_string(x);
    return (std::stol(xy) > std::stol(yx));
}

string Solution::largestNumber(const vector<int> &A) {
    
    std::stringstream ss;
    vector<int> B(A);
    int high_num = 0;
    int high_bit = 0;
    int high_indx = 0;
    
    sort(B.begin(), B.end(), get_high_bit);
    vector<int> tmp;
    int first = 0;
    for(auto num: B) {
        if (num == 0 && first == 0)
            continue;
        first = 1;
        tmp.push_back(num);
    }
    if (tmp.size() ==0)
        tmp.push_back(0);
        
    
    for(auto num: tmp)
    ss << std::to_string(num);
    return ss.str();
}

