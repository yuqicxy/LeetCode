#include <vector>
#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        return uniquePaths(m,n-1) + uniquePaths(m-1,n);        
    }
};

int main(){
    Solution s;
    std::cout<<s.uniquePaths(51,9);
    return 1;
}