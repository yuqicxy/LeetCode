#include <vector>
#include <iostream>

using namespace std;

size_t parent(const size_t &i){
    if(i == 0) return 0;
    return (i + 1) >> 1 - 1;
}

size_t left(const size_t& i){
    return (i + 1) << 1 - 1;
}

size_t right(const size_t& i){
    return (i + 1) << 1;
}

void MaxHeapify(vector<int> &A, const size_t i){
    size_t l = left(i);
    size_t r = right(i);
    size_t largest;
    if(l < A.size() && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if(r < A.size() && A[r] > A[largest])
        largest = r;
    
    if(largest != i){
        swap(A[i], A[largest]);
        MaxHeapify(A, largest);
    }
}

void BuildMaxHeap(vector<int> &A){
    for(size_t i = A.size() >> 1; i >= 0; --i){
        MaxHeapify(A,i);
        if(i == 0)  
            break;
    }
}

void print(const vector<int>& A){
    for (auto &&i : A)
        cout << i <<'\t';
    cout << endl;
}

int main(){
    vector<int> A{4,1,3,2,16,9,10,14,8,7};
    BuildMaxHeap(A);
    print(A);
    A.erase(A.begin());
    MaxHeapify(A,0);
    print(A);
}

