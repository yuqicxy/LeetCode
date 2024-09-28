/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class MyCircularDequeOnList {
public:
    MyCircularDequeOnList(int k):mList(), mMaxSize(k) {
    }
    
    bool insertFront(int value) {
        if(mList.size() < mMaxSize){
            mList.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(mList.size() < mMaxSize){
            mList.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(mList.empty()) 
            return false;
        mList.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(mList.empty())
            return false;
        mList.pop_back();
        return true;        
    }
    
    int getFront() {
        if(mList.empty()) return -1;
        return mList.front();
    }
    
    int getRear() {
        if(mList.empty()) return -1;
        return mList.back();
    }
    
    bool isEmpty() {
        return mList.empty();
    }
    
    bool isFull() {
        return mList.size() == mMaxSize;
    }
private:
    int         mMaxSize;
    list<int>   mList;
};


// @lc code=start
class MyCircularDeque {
public:
    MyCircularDeque(int k):mList(k), mMaxSize(k),mFront(0),mRear(k-1),mCount(0) {
    }
    
    bool insertFront(int value) {
        if(mCount < mMaxSize){
            mList[mFront] = value;
            mFront = (mFront + 1) % mMaxSize;
            mCount++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(mCount < mMaxSize){
            mList[mRear] = value;
            mRear = (mRear - 1 + mMaxSize) % mMaxSize;
            mCount++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(mCount > 0){
            mCount--;
            mFront = (mFront - 1 + mMaxSize) % mMaxSize;
            return  true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(mCount > 0){
            mCount--;
            mRear = (mRear + 1) % mMaxSize;
            return true;
        }
        return false;        
    }
    
    int getFront() {
        if(mCount > 0){
            return mList[ (mFront - 1 + mMaxSize) % mMaxSize];
        }
        return -1;
    }
    
    int getRear() {
        if(mCount > 0){
            return mList[ (mRear + 1) % mMaxSize];
        }
        return -1;
    }
    
    bool isEmpty() {
        return mCount == 0;
    }
    
    bool isFull() {
        return mCount == mMaxSize;
    }
private:
    int         mFront;
    int         mRear;
    int         mMaxSize;
    int         mCount;
    vector<int> mList;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

int main(){
    MyCircularDeque* myCircularDeque = new MyCircularDeque(3);
    cout << boolalpha;
    cout<<myCircularDeque->insertLast(1)<<endl;  // return True
    cout<<myCircularDeque->insertLast(2)<<endl;  // return True
    cout<<myCircularDeque->getRear()<<endl;      // return 2
    cout<<myCircularDeque->deleteLast()<<endl;   // return True
    cout<<myCircularDeque->getRear()<<endl;      // return 1
    cout<<myCircularDeque->deleteLast()<<endl;   // return True
    cout<<myCircularDeque->insertFront(3)<<endl; // return True
    cout<<myCircularDeque->insertFront(4)<<endl; // return True
    cout<<myCircularDeque->getRear()<<endl;      // return 3
    cout<<myCircularDeque->isFull()<<endl;       // return False
    cout<<myCircularDeque->deleteLast()<<endl;   // return True

    cout<<myCircularDeque->insertFront(5)<<endl; // return True
    cout<<myCircularDeque->getFront()<<endl;     // return 5
    cout<<myCircularDeque->getRear()<<endl;     // return 3

    delete myCircularDeque;
}

