class Solution {
public:
    int t[46];
    int solve(int n) {
        if (n < 0) 
            return 0;
        if (t[n] != -1) 
            return t[n];
        if (n == 0) 
            return 1;
        int step_one = solve(n - 1);
        int step_two = solve(n - 2);

        return t[n] = step_one + step_two;
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }

};