#include <vector>
#include <iostream>
#include <random>

using namespace std;

class QuickSort{
public:
    void quickSort(vector<int> &list, size_t start, size_t end){
        if(start < end){
            size_t mid = randomPartion(list, start, end);
            quickSort(list, start, mid);
            quickSort(list, mid + 1, end);
        }
    }

    size_t randomPartion(vector<int> &list, size_t start, size_t end){
        size_t randIndex = std::rand() / ((RAND_MAX + 1u) / (end - start)) + start;
        swap(list[randIndex], list[end - 1]);
        return partition(list, start, end);
    }

    size_t partition(vector<int> &list, size_t start, size_t end){
        int mid = list[end - 1];
        size_t i = start;
        for(size_t j = start; j < end; ++j){
            if(list[j] < mid){
                swap(list[i], list[j]);
                i++;
            }
        }
        swap(list[i], list[end - 1]);
        return i;
    }
};

int main(){
    QuickSort sort;
    vector<int> t2{2,8,7,1,3,5,6,4};
    sort.quickSort(t2, 0, t2.size());
    for (auto &&i : t2)
        cout << "," << i;
    cout << endl;
    return 0;
}