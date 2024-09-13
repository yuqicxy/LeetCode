/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */
#include <vector>
#include <tuple>
#include <iostream>
#include <stack>
using namespace std;

class StockSpannerStupid {
public:
    StockSpannerStupid() {
    }
    
    int next(int price) {
        // history.push_back(price);
        if(history.empty()){
            history.emplace_back(price, 1);
            return 1;
        }

        int count = 1;
        for(int i = (int)history.size() - 1; i > -1; ){
            int pastPrice, pastSpan;
            tie(pastPrice, pastSpan) = history[i];
            if(pastPrice > price){
                history.emplace_back(price, count);
                return count;
            }
            else{
               i -= pastSpan;
               count += pastSpan;
            }
        }
        history.emplace_back(price, count);
        return count;
    }
private:
    vector<tuple<int,int>> history;
};

// @lc code=start
class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int count = 1;
        while(!history.empty()){
            int pastPrice, pastSpan;
            tie(pastPrice, pastSpan) = history.top();
            if(pastPrice > price){
                history.emplace(price, count);
                return count;
            }else{
                count += pastSpan;
                history.pop();
            }
        }

        history.emplace(price, count);
        return count;
    }
private:
    stack<tuple<int,int>> history;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
int main(){
    StockSpanner stockSpanner;
    cout<<stockSpanner.next(100)<<endl; // return 1
    cout<<stockSpanner.next(80)<<endl;  // return 1
    cout<<stockSpanner.next(60)<<endl;  // return 1
    cout<<stockSpanner.next(70)<<endl;  // return 2
    cout<<stockSpanner.next(60)<<endl;  // return 1
    cout<<stockSpanner.next(75)<<endl;  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    cout<<stockSpanner.next(85)<<endl;  // return 6

    // cout<<stockSpanner.next(31)<<endl;  // return 1
    // cout<<stockSpanner.next(41)<<endl;  // return 2
    // cout<<stockSpanner.next(48)<<endl;  // return 3
    // cout<<stockSpanner.next(59)<<endl;  // return 4
    // cout<<stockSpanner.next(79)<<endl;  // return 5
}