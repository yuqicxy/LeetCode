#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Graph{
    enum class Color:char{
        Black = 2,
        GRAY  = 1,
        WHITE = 0
    };
public:
    vector<int> BFS(vector<vector<int>> graph,int source, int vertexCount){
        vector<Color> colors(vertexCount,Color::WHITE); 
        colors[source-1] = Color::GRAY;
        vector<int> distances(vertexCount,INT_MAX);
        distances[source-1] = 0;
        queue<int> grayQueue;
        grayQueue.push(source-1);

        while(!grayQueue.empty()){
            int s = grayQueue.front();
            grayQueue.pop();
            colors[s] = Color::Black;
            auto edges = findEdgeStartWith(graph,s);
            for(auto edge : edges){
                int u = s; //(*edge)[0] - 1;
                int v = graph[edge][1] - 1;
                int w = graph[edge][2];
                distances[v] = min(distances[v], distances[u] + w);
                if(colors[v] == Color::WHITE){
                    colors[v] = Color::GRAY;
                    grayQueue.push(v);
                }
            }
        }
        return distances;
    }

    vector<int> findEdgeStartWith(const vector<vector<int>>& graph,const int& source){
        vector<int> results;
        for(int i = 0 ; i < graph.size(); ++i){
            if(graph[i][0] - 1 == source){
                results.push_back(i);
            }
        }
        return results;
    } 
};

std::ostream& operator<<(std::ostream& out,const std::vector<int> &vec){
    for_each(vec.begin(),vec.end(),[&](auto i){out<<i<<" ";});
    return out;
}

int main(){
    Graph g;
    vector<vector<int>> times ={{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout<<"test 1:"<<g.BFS(times,k,n)<<endl;
    times = {{1,2,1},{2,1,3}};
    n = 2, k = 2;
    cout<<"test 2:"<<g.BFS(times,k,n)<<endl;
    times = {{1,2,1}};
    n = 2, k = 2;
    cout<<"test 3:"<<g.BFS(times,k,n)<<endl;
    return 0;
}