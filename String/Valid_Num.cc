/*
Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem*/

int Solution::isNumber(const string A) {
    int start = 0;
    int end = A.length() - 1;
    bool sign = false;
    bool decimal = false;
    bool expo = false;
    bool num_start = false;
    bool space  = false;
    bool num = false;
    while (start <= end) {
        char sym = A[start];
        if (sym == ' ') {
            if(!space && !num_start) {
                start++;
                continue;
            }
            if (num_start) {
                space = true;
                start++;
                continue;
            }
        }
        if (num_start && space) {
            return 0;
        }
        if (sym == '-' || sym == '+') {
            if(!sign) {
                sign = true;
            } else {
                return 0;
            }
        } else if (sym == '.') {
            if (!decimal) {
                decimal = true;
            } else {
                return 0;
            }
        } else if (sym == 'e') {
            if (!expo) {
                if (A[start-1] == '.') {
                    return 0;
                }
                expo = true;
                sign = false;
                decimal = true;
            } else {
                return 0;
            }
        } else if(!(sym >= '0' && sym <= '9')) {
            return 0;
        }
        if (sym >= '0' && sym <= '9') {
            num  = true;
        }
        num_start = true;
        start++;
    }
    if(A[end] == '.') {
        return 0;
    }
    if (sign && !num) {
        return 0;
    }
    if(!num) {
        return 0;
    }
    return 1;
}

