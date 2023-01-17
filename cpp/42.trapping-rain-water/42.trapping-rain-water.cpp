#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int sum = 0;
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while(left != right){
            if(height[left] <= height[right]){
                if(height[left] > maxLeft) maxLeft = height[left];
                else sum += maxLeft - height[left];
                ++left;
            }else if(height[right] < height[left]){
                if(height[right] > maxRight) maxRight = height[right];
                else sum += maxRight - height[right];
                --right;
            }
        }
        return sum;
    }
};

int main(){
    Solution s;
    std::vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(test);
}