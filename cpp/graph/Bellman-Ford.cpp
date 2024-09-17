#include <vector>
#include <limits>

using namespace std;

class BellmanFord{
public:
    bool singleSourceShortestPath(vector<vector<int>> graph,int source,int count){
        //intializeSingleSource
        vector<int> distance(count,numeric_limits<int>::max());
        vector<int> pre_pi(count,-1);
        distance[source - 1] = 0;
        //BellmanFord
        for(unsigned i = 0; i < count - 1; i++){
            for(auto edge : graph){
                //relax edge
                int u = edge[0] - 1;
                int v = edge[1] - 1;
                int w = edge[2];
                if(distance[u] != numeric_limits<int>::max() 
                    && distance[v] > distance[u] + w)
                {
                    distance[v] = distance[u] + w;
                    pre_pi[v]=u;
                }
            }
        }

        for(auto edge : graph){
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            int w = edge[2];
            if(distance[v] > distance[u] + w){
                return false;
            }
        }

        return true;
    }
};

int  main(){
    BellmanFord bf;
    // vector<vector<int>> graph = 
    //     {{2,1,1},{2,3,1},{3,4,1}};
    vector<vector<int>> graph = {
        {1,2,6},
        {1,5,7},
        {2,3,5},
        {2,4,-4},
        {2,5,8},
        {3,2,-2},
        {4,1,2},
        {5,3,-3},
        {5,4,9}
    };
    auto result = bf.singleSourceShortestPath(graph,1,5);
}