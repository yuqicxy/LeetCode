#include <vector>
#include <iostream>

class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     if(m == 1 || n == 1)
    //         return 1;
    //     return uniquePaths(m,n-1) + uniquePaths(m-1,n);        
    // }

    int uniquePaths(int m, int n) {
        if(m > n) return uniquePaths(n,m);
        std::vector<int> dp(n * m, 0);
        for(size_t i = 0; i < m; ++i){
            for(size_t j = i; j < n; ++j){
                if(i == 0 || j == 0){
                    dp[i * n + j] = 1;
                    continue;
                }
                if(j == i){
                    dp[i * n + j - 1] = dp[(j-1) * n + i];
                }
                dp[i * n + j] = dp[i * n + j - 1] + dp[(i - 1) * n + j];
            }
        }
        return dp[(m - 1) * n + n - 1];
    }
};

int main(){
    Solution s;
    std::cout<<s.uniquePaths(51,9);
    return 1;
}