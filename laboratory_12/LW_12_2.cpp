// Task 1 (задача про подземелье)

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;


class Cord {
    public:
        vector<int> cord;
        int x;
        int y;

        void updateVars() {
            x = cord[0];
            y = cord[1];
        }

        Cord(vector<int> input_cord) {
            cord = input_cord;
            updateVars();
        }

        void changeCord(vector<int> new_cord) {
            cord = new_cord;
            updateVars();
        }
};



class Dungeon {
    private:
        vector<vector<int>> grid;
    public:
        Dungeon(vector<vector<int>> input_grid);
        int nextStep(Cord new_pos, int health, int req_hp);
        int optimalPath();
};

Dungeon::Dungeon(vector<vector<int>> input_grid) {
    grid = input_grid;
}

int Dungeon::nextStep(Cord new_pos, int health, int req_hp) {
    health += grid[new_pos.x][new_pos.y];
    req_hp = min(req_hp, health);
    cout << "curr pos: " << new_pos.x << "," << new_pos.y << "  health:" << health << "  req_hp:" << req_hp << endl;

    int optimal_req_hp;
    
    if ((new_pos.x)<(grid.size()-1) && (new_pos.y)<(grid[0].size()-1)) {
        optimal_req_hp = max(nextStep(Cord({new_pos.x, new_pos.y+1}), health, req_hp), nextStep(Cord({new_pos.x+1, new_pos.y}), health, req_hp));
    } else if ((new_pos.x)<(grid.size()-1)) {
        optimal_req_hp = nextStep(Cord({new_pos.x+1, new_pos.y}), health, req_hp);
    } else if ((new_pos.y)<(grid[0].size()-1)) {
        optimal_req_hp = nextStep(Cord({new_pos.x, new_pos.y+1}), health, req_hp);
    } else if ((new_pos.x)==(grid.size()-1) && (new_pos.y)==(grid[0].size()-1)) {
        optimal_req_hp = req_hp;
    }

    return optimal_req_hp;
}

int Dungeon::optimalPath() {
    Cord pos = Cord({0, 0});
    int health = grid[pos.x][pos.y];
    int optimal_path;

    if ((pos.x)<(grid.size()-1) || (pos.y)<(grid[0].size()-1)) {
        optimal_path = max(nextStep(Cord({0, 1}), health, health), nextStep(Cord({1, 0}), health, health));
    } else {
        optimal_path = health;
    }

    if (optimal_path <= 0)
        return abs(optimal_path) + 1;
    else
        return optimal_path;
}





int main() {
    vector<int> vec1 = {0};
    vector<vector<int>> vec2 = {vec1};
    Dungeon dungeon1 = Dungeon( {{-2,-3,3},{-5,-10,1},{10,30,-5}} );
    int path = dungeon1.optimalPath();
    cout << "Min health: " << path << endl;
}