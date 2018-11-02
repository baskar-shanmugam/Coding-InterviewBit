/*
You are given an array A consisting of strings made up of the letters ‘a’ and ‘b’ only. 
Each string goes through a number of operations, where:
<ul>
<li>At time 1, you circularly rotate each string by 1 letter.</li>
<li>At time 2, you circularly rotate the new rotated strings by 2 letters.</li>
<li>At time 3, you circularly rotate the new rotated strings by 3 letters.</li>
<li>At time i, you circularly rotate the new rotated strings by i % length(string) letters.</li>
</ul>
Eg: String is abaa
<ul>
<li>At time 1, string is baaa, as 1 letter is circularly rotated to the back</li>
<li>At time 2, string is aaba, as 2 letters of the string baaa is circularly rotated to the back</li>
<li>At time 3, string is aaab, as 3 letters of the string aaba is circularly rotated to the back</li>
<li>At time 4, string is again aaab, as 4 letters of the string aaab is circularly rotated to the back</li>
<li>At time 5, string is aaba, as 1 letters of the string aaab is circularly rotated to the back</li>
</ul>
After some units of time, a string becomes equal to it’s original self. 
Once a string becomes equal to itself, it’s letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be it’s original self at 2t time. 
You have to find the minimum time, where maximum number of strings are equal to their original self. 
As this time can be very large, give the answer modulo 109+7.

Note: Your solution will run on multiple test cases so do clear global variables after using them.

Input:

A: Array of strings.
Output:

Minimum time, where maximum number of strings are equal to their original self.
Constraints:

1 <= size(A) <= 10^5
1 <= size of each string in A <= 10^5
Each string consists of only characters 'a' and 'b'
Summation of length of all strings <= 10^7
Example:

Input

A: [a,ababa,aba]
Output

4

String 'a' is it's original self at time 1, 2, 3 and 4.
String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)

Hence, 3 strings are their original self at time 4.*/




string string_rotate(const string& str, long rotate) {
    string r_str(str);
    long length = str.length()-1;
    while(rotate > 0) {
        char c = r_str[0];
        long iter = 1;
        while(iter <= length) {
            r_str[iter-1] = r_str[iter];
            iter++;
        }
        r_str[iter-1] = c;
     //   cout<< " rtd: " << r_str << " i: " << rotate;
        rotate--;
    }
    return r_str;
}


long findRotateTime(const string& str) {
    if(str.length() == 1) {
        return 1;
    }
    long timetaken = 0;
    long rotate = 1;
    long length = str.length();
    long time = 1;
    string r_str = str;
    while(1) {
        rotate = time % length;
        if (time == 0) {
            rotate = length;
        }
        timetaken++;
        r_str = string_rotate(r_str, rotate);
      //  cout<< " r_str: " << r_str << " tt: " << timetaken << " r: " << rotate << " ";
        if(r_str == str) {
            return timetaken;
        }
        time++;
    }
    return timetaken;
}

int Solution::solve(vector<string> &A) {
    vector<long> rotateTime;
    
    for(auto str: A) {
      //  cout<< "for string: " << str;
        rotateTime.push_back(findRotateTime(str));
    }
    for(auto time: rotateTime) {
       // cout<< time << " ";
    }
    return 1;
}
