/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If yo*/

std::stack<int> st;
std::stack<int> mst;

MinStack::MinStack() {
    while(!st.empty()) {
        st.pop();
    }
    while(!mst.empty()) {
        mst.pop();
    }
}

void MinStack::push(int x) {
  /*  if (s_end != s_fnt) {
        st[s_end] = x;
        s_end = (s_end + 1)%size;
    } else {
        
    }
    if (s_fnt == -1) {
        s_fnt = 0;
    }*/
    st.push(x);
    if (mst.empty()) {
        mst.push(x);
    } else if (mst.top() > x) {
        mst.push(x);
    }
}

void MinStack::pop() {
    if (!st.empty()) {
        auto top = st.top();
        if (mst.top() == top ) {
            mst.pop();
        }
        st.pop();
    }
}

int MinStack::top() {
    if (!st.empty())
        return st.top();
    return -1;
}

int MinStack::getMin() {
    if (!mst.empty()) {
        return mst.top();
    }
    return -1;
}


