#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int oneStepBefore = 2;
        int twoStepsBefore = 1;
        int allways = 0;
        for (int i = 3; i <= n; ++i) {
            allways = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = allways;
        }
        return allways;
    }
};

int main() {
    Solution s;
    std::cout<<s.climbStairs(4)<<std::endl;
    //std::cout<<
}