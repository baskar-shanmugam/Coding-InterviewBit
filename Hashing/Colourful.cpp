/*
 For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1*/

int Solution::colorful(int A) {
    std::vector<int> digit;
    int num = A;
    while(num) {
        digit.push_back(num%10);
        num = num/10;
    }
    std::map<int,int> sub_seq;
    for(int i = 1; i <= digit.size(); i++) {
        for(int j = 0; j < digit.size(); j++) {
            if (i + j > digit.size())
                break;
            int num_of_digits = i;
            int d = j;
            int number = 1;
            while(num_of_digits) {
                
                number = number * digit[d];
                num_of_digits--;
                d++;
            }
        
            if(sub_seq.find(number) != sub_seq.end()) {
                return 0;
            } else {
                sub_seq.insert(std::pair<int,int>(number,1));
            }
        }
    }
    return 1;
}

