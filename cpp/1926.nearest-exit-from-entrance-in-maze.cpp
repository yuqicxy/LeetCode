/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */
#include <vector>
#include <queue>
#include <tuple>
#include <limits>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    struct Position{
        int x;
        int y;
        unsigned cost; 

        bool operator<(const Position& other){
            if(this->cost < other.cost)
                return true;
            return false;
        }
    };

    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT,
        LAST
    };

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const size_t dimX = maze.size();
        const size_t dimY = maze[0].size();
        Position initialPos{entrance[0],entrance[1],0};
        queue<Position> queue; 
        queue.push(initialPos);
        Position bestExit{0,0,static_cast<unsigned>(-1)};
        while(!queue.empty()){
            auto pos = queue.front();
            queue.pop();
            bool exit = false;
            Position newPos;
            for(int movement = Direction::UP; movement != Direction::LAST; ++movement){
                Direction dir = static_cast<Direction>(movement);
                std::tie(exit, newPos) = move(dimX,dimY,pos,dir);
                if(exit){
                    if(newPos.x != initialPos.x || newPos.y != initialPos.y)
                        if(newPos < bestExit)
                            bestExit = newPos;
                }
                else if(maze[newPos.x][newPos.y] == '.'){
                    newPos.cost += 1;
                    queue.push(newPos);
                    maze[newPos.x][newPos.y] = '+';
                }
            }
        }
        return bestExit.cost;
    }

    tuple<bool,Position> move(const size_t& dimX,const size_t& dimY,const Position &pos,const Direction& dir){
        Position currPos = pos;
        switch (dir)
        {
        case Direction::UP:
            currPos.x--;
            break;
        case Direction::DOWN:
            currPos.x++;
            break;
        case Direction::LEFT:
            currPos.y--;
            break;
        case Direction::RIGHT:
            currPos.y++;
        }

        bool exit = false;
        if(currPos.x < 0 || currPos.x >= dimX || currPos.y < 0 || currPos.y >= dimY )
            exit = true;

        return exit ? std::tie(exit,pos) : std::tie(exit,currPos);
    }
};
// @lc code=end
int main(){
    vector<vector<char>> maze{
        {'+','+','.','+'},
        {'.','.','.','+'},
        {'+','+','+','.'}
    };
    vector<int> entrance = {1,2};

    vector<vector<char>> maze2{
        {'+','+','+'},
        {'.','.','.'},
        {'+','+','+'}
    };
    vector<int> entrance2 = {1,0};

    vector<vector<char>> maze3{
        {'.','+'}
    };
    vector<int> entrance3 = {0,0};

    Solution s;
    std::cout<<s.nearestExit(maze,entrance)<<endl;
    std::cout<<s.nearestExit(maze2,entrance2)<<endl;
    std::cout<<s.nearestExit(maze3,entrance3)<<endl;
}

