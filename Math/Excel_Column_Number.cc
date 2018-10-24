/*
Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 
*/

int Solution::titleToNumber(string A) {
    int total = 0;
    for (int i = A.length()-1,j =0; i >= 0; i--,j++) {
        char c = A[i] - 'A' + 1;
        cout << "A: " << A[i] << " c: " << c << " p: " << pow(26,j) << std::endl;
        total += c * pow(26,j);
    }
    return total;
}
