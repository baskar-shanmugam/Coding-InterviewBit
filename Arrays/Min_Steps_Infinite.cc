/*
You are in an infinite 2D grid where you can move in any of the 8 directions :

 (x,y) to 
    (x+1, y), 
    (x - 1, y), 
    (x, y+1), 
    (x, y-1), 
    (x-1, y-1), 
    (x+1,y+1), 
    (x-1,y+1), 
    (x+1,y-1) 
You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

Input :

Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.
Output :

Return an Integer, i.e minimum number of steps.
Example :

Input : [(0, 0), (1, 1), (1, 2)]
Output : 2
It takes 1 step to move from (0, 0) to (1, 1). It takes one more step to move from (1, 1) to (1, 2).

This question is intentionally left slightly vague. Clarify the question by trying out a few cases in the “See Expected Output” section.*/

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    if (A.size() == 0 || B.size() == 0 ||
        A.size() != B.size()) {
      //  cout << " Invalid input size" << std::endl;
        return 0;
    }
    
    int x = A[0];
    int y = B[0];
    int count = 0;
    int x_cnt = 0;
    int y_cnt = 0;
    for (int i = 1; i < A.size() ; i++) {
        x_cnt = y_cnt = 0;
        if (x == A[i] && y == B[i]) {
         //   cout << "Both the coordinates are same" << std::endl;
            continue;
        }
        /*while (x != A[i]) {
            if (x > A[i]) {
                x--;
            } else {
                x++;
            }
            x_cnt++;
        
        }*/
        if (x > A[i]) {
            x_cnt = x - A[i];
        } else {
            x_cnt = A[i] - x;
        }
        x = A[i];
        
       // cout<< "x_cnt: " << x_cnt << " for iteration i is: " << i << std::endl;
       /* while (y != B[i]) {
            if (y > B[i]) {
                y--;
            } else {
                y++;
            }
            y_cnt++;
        }*/
        if (y > B[i]) {
            y_cnt = y - B[i];
        } else {
            y_cnt = B[i] - y;
        }
        y = B[i];
      //  cout<< "y_cnt: " << y_cnt << " for iteration i is: " << i << std::endl;
        if (x_cnt >= y_cnt) {
            count += x_cnt;
        } else {
            count += y_cnt;
        }
       // cout<< "count: " << count << " for iteration i is: " << i << std::endl;
    }
    return count;
}

