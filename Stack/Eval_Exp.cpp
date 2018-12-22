/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6*/

int Solution::evalRPN(vector<string> &A) {
    std::stack<int> oprd;
    std::set<string> op {"+","-","*","/"};
    int val;
    if (A.size() == 0) {
        return 0;
    }
    for(int i = 0; i < A.size(); i++) {
        if (op.find(A[i]) != op.end()) {
            
            auto oprd1 = oprd.top();
            oprd.pop();
            auto oprd2 = oprd.top();
            oprd.pop();
            int res = 0;
            switch(A[i].at(0)) {
                case '+':
                    res = oprd1 + oprd2;
                    break;
                case '-':
                    res = oprd2 - oprd1;
                    break;
                case '*':
                    res = oprd2 * oprd1;
                    break;
                case '/':
                    res = oprd2/oprd1;
                    break;
            }
            oprd.push(res);
          //  std::cout<< "res p " << res << " ";
        } else {
          //  std::cout<< "push" << std::stoi(A[i]) << " ";
            oprd.push(std::stoi(A[i]));
        }
    }
    return oprd.top();
}

