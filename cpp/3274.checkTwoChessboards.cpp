#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int sum  = abs(coordinate1[0] - coordinate2[0]) + 
        abs(coordinate1[1] - coordinate2[1]);
        return sum%2 == 0;
    }
};

int main(){
    Solution s;
    cout << boolalpha << s.checkTwoChessboards("a1","h3");
}