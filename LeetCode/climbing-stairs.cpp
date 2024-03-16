// https://leetcode.com/problems/climbing-stairs/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int a = 0;
        int b = 1;
        int c = 1;
        for (int i = 2; i <= n; i++) {
            a = b;
            b = c;
            c = a + b;
        }

        return c;
    }
};
