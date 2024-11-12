#include<vector>
#include <algorithm>
#include <iostream>
using namespace std;

ostream& operator<< (ostream& ss, vector<int> nums){
    cout << "[";
    for(auto num:nums){
        cout << num << ", ";
    }
    cout << "\b\b" << "]";
    return ss;
}

// lower_bound 
// returns an iterator to the first element not less than the given key


// upper_bound
// returns an iterator to the first element greater than a certain value




int main(){
    vector num{1,2,3,5,5,5,5,5,6,7,8,9};
    cout << "***************************search 5 which has duplicates in ascending order array *****************************************************"<<endl;
    cout << num << endl;
    auto itr = lower_bound(num.begin(), num.end(), 5);
    cout << "Lower bound 5 at " << "val:" << *itr << "\t Index:" << distance(num.begin(), itr)  << endl;
    itr = upper_bound(num.begin(), num.end(), 5);
    cout << "Upper bound 5 at " << "val:" << *itr << "\t Index:" << distance(num.begin(), itr)  << endl;
    cout << "***************************search 4 which is not existed in ascending order array*****************************************************"<<endl;
    cout << num << endl;
    itr = lower_bound(num.begin(), num.end(), 4);
    cout << "Lower bound 4 at " << "val:" << *itr << "\t Index:" << distance(num.begin(), itr)  << endl;
    itr = upper_bound(num.begin(), num.end(), 4);
    cout << "Upper bound 4 at " << "val:" << *itr << "\t Index:" << distance(num.begin(), itr)  << endl;
    cout << "***************************search 5 which has duplicates in descending order array *****************************************************"<<endl;
    sort(num.begin(), num.end(), std::greater());
    cout << num << endl;
    itr = lower_bound(num.begin(), num.end(), 5, [](auto val, auto itr){
        return val > itr;
    });
    cout << "Lower bound 5 at " << "val:" << *itr << "\t Index:" << distance(num.begin(), itr) << endl;
    itr = upper_bound(num.begin(), num.end(), 5,  [](auto val, auto itr){
        return val > itr;
    });
    cout << "Upper bound 5 at "<< "val:" << *itr << "\t Index:"  << distance(num.begin(), itr) << endl;
    return 0;
}