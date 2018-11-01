/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index*/


vector<int> Solution::maxset(vector<int> &A) {
    int ma_start_idx = -1;
    int ma_len =0;
    long ma_max =0;
    
    int curr_start_idx = -1;
    int curr_len = 0;
    long curr_max = 0;
    
    vector<int> max_sub_arr;
    
    for(int i = 0; i < A.size(); i++) {
       //cout<< "index running for : " << i << std::endl;
        if (A[i] >= 0) {
            if (curr_start_idx == -1) {
        //        cout<< "set curr_start_idx: " << i << std::endl;
                curr_start_idx = i;
            }
            curr_len += 1;
            curr_max += A[i];
        } else {
            if (curr_max >= ma_max) {
                if (curr_max > ma_max) {
                    ma_max = curr_max;
                    ma_len = curr_len;
                    ma_start_idx = curr_start_idx;
                    curr_len = curr_max = 0;
                    curr_start_idx = -1;
                } else {
                    if (curr_len >= ma_len) {
                        if (curr_len > ma_len) {
                            ma_max = curr_max;
                            ma_len = curr_len;
                            ma_start_idx = curr_start_idx;
                            curr_len = curr_max = 0;
                            curr_start_idx = -1;
                        }
                    } else {
                        curr_len = curr_max = 0;
                        curr_start_idx = -1;
                    }
                }
                
            } else {
                //last max is better
                curr_len = curr_max = 0;
                curr_start_idx = -1;
            }
            
        }
    }
    if (curr_max >= ma_max) {
                if (curr_max > ma_max) {
                    ma_max = curr_max;
                    ma_len = curr_len;
                    ma_start_idx = curr_start_idx;
                    curr_len = curr_max = 0;
                    curr_start_idx = -1;
                } else {
                    if (curr_len >= ma_len) {
                        if (curr_len > ma_len) {
                            ma_max = curr_max;
                            ma_len = curr_len;
                            ma_start_idx = curr_start_idx;
                            curr_len = curr_max = 0;
                            curr_start_idx = -1;
                        }
                    } else {
                        curr_len = curr_max = 0;
                        curr_start_idx = -1;
                    }
                }
    }
    if (ma_len == 0 && curr_start_idx != -1) {
        return A;
    }
    for (int i = 0; i < ma_len; i++) {
      // cout<< "inx i:  " << i << "ma_start_idx is: " <<  ma_start_idx << "ma_len: " << ma_len << std::endl;
        max_sub_arr.push_back(A[i+ma_start_idx]);
    }
    return max_sub_arr;
}


