/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.*/



/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compareInterval(Interval i1, Interval i2) 
{ 
    return (i1.start < i2.start); 
} 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<Interval> merge;
    sort(A.begin(),A.end(),compareInterval);
    for (int i = 0; i < A.size();) {
        int curr_start = A[i].start;
        int curr_end = A[i].end;
        int next_iter = i + 1;
        while ((next_iter < A.size()) &&(curr_end >= A[next_iter].start)) {
            if (curr_end <  A[next_iter].end)
                curr_end = A[next_iter].end;
            next_iter++;
        }
        Interval element(curr_start, curr_end);
        merge.push_back(element);
        i = next_iter;
    }
    return merge;
}
