/*
Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.*/


string Solution::simplifyPath(string A) {
    std::stack<string> path;
    string name;
    bool dot = false;
    bool str = false;
    for (unsigned i=0; i<A.length(); ++i)
    {
        char c = A.at(i);
        if (c == '.') {
            if (dot) {
                if (!path.empty())
                    path.pop();
                dot = false;
            } else {
                dot = true;
            }
            continue;
        } else if (c == '/') {
            if (dot) {
                dot = false;
            } if (str) {
                path.push(name);
                name.clear();
                str = false;
            }
        } else {
            str = true;
            name += c;
        }
    }
    if (str) {
        path.push(name);
    }
    string dirpath;
    while(!path.empty()) {
        dirpath = "/" + path.top() + dirpath;
        path.pop();
    }
    if (dirpath.empty()) {
        dirpath = '/';
    }
    return dirpath;
}

