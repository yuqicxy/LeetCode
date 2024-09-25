#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> mResult;
    unsigned mMin;
    int mTarget;
public:
    // 主函数，输入一组不重复的数字，返回它们的全排列
    vector<int> permute(vector<int>& nums, int target) {
        mTarget = target;
        mMin = INT_MAX;
        // 记录「路径」
        vector<int> track;
        // 「路径」中的元素会被标记为true，避免重复使用
        vector<bool> used(nums.size(), false);

        backtrack(nums, track, used);
        // return res;
        return mResult;
    }

    int calSum(vector<int> &track){
        int sum = 0;
        for(int i = 0; i < 3; i++){
            for(int j = i * 3; j < (i + 1) * 3; j++){
                sum += (track[j] * (int)pow(10,2 - (j % 3)));
            }
        }
        return sum;
    }

    void print(vector<int> &track){
        cout << "number:";
        for (auto &&i : track){
            cout << i << ',';
        }
        cout << endl;
    }

    // 路径：记录在 track 中
    // 选择列表：nums 中不存在于 track 的那些元素
    // 结束条件：nums 中的元素全都在 track 中出现
    void backtrack(vector<int>& nums, vector<int>& track, vector<bool>& used) {
        // 触发结束条件
        if (track.size() == nums.size()) {
            int sum = calSum(track);
            int result = abs(sum - mTarget);
            if(result < mMin){
                mResult = track;
                mMin = result;
                cout << "min:" << mMin << endl;
                print(track);
            }
            // res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 排除不合法的选择
            if (used[i]) {

                // nums[i] 已经在 track 中，跳过
                continue;
            }
            // 做选择
            track.push_back(nums[i]);
            used[i] = true;
            // 进入下一层决策树
            backtrack(nums, track, used);
            // 取消选择
            track.pop_back();
            used[i] = false;
        }
    }
};

int main(){
    Solution s;
    vector<int> track{1,2,3,4,5,6,7,8,9};
    s.permute(track, 1062);
}