#include <iostream>
#include <queue>
#include <vector>

// 1568

using namespace std;

class Solution {
    
public:
    
    vector<int> deltaX = {1, -1, 0, 0};
    vector<int> deltaY = {0, 0, 1, -1};
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visitedGrid) {
        
        // set the grid element at position (row, col) as visited
        visitedGrid[row][col] = 1;
        
        // for all possible directions (each node has exactly 4 neighbors)
        for (int i = 0; i < 4; i++) {
            
            int adjacentCol = col + deltaX[i];
            int adjacentRow = row + deltaY[i];
            
            if (adjacentCol >= 0 && adjacentRow >= 0 && adjacentCol < grid[0].size() && adjacentRow < grid.size()) {
                
                // if it is a land and it is not visited yet
                if (grid[adjacentRow][adjacentCol] == 1 && visitedGrid[adjacentRow][adjacentCol] != 1) {
                    
                    dfs(adjacentRow, adjacentCol, grid, visitedGrid);
                    
                }
                
            }
            
        }
        
    }
    
    int countIslands(vector<vector<int>>& grid) {
        
        int islands = 0;
        vector<vector<int>> visitedGrid(grid.size(), vector<int> (grid[0].size(), 0));
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                
                if ((visitedGrid[i][j] != 1) && (grid[i][j] == 1)) {
                    dfs(i, j, grid, visitedGrid);
                    islands++;
                }
                
            }
        }
        
        return islands;
        
    }
    
    int minDays(vector<vector<int>>& grid) {
        
        int islands = countIslands(grid);
        
        if (islands > 1 || islands == 0) return 0;
        
        for (int i = 0; i < grid.size(); i++) {
            
            for (int j = 0; j < grid[0].size(); j++) {
                
                if (grid[i][j]) {
                    
                    // counting islands if this cell is removed
                    grid[i][j] = 0;
                    
                    islands = countIslands(grid);
                    
                    // giving back the block
                    grid[i][j] = 1;
                    
                    if (islands > 1 || islands == 0) return 1;
                    
                }
                
            }
            
        }
        
        return 2;
        
    }
};

int main(int argc, const char * argv[]) {
    
    Solution *sol = new Solution();
    
    vector<vector<int>> test0 = {
        
        { 0, 1, 1, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 }
        
    };
    
    vector<vector<int>> test1 = {
        
        { 1, 1}
        
    };
    
    vector<vector<int>> test2 = {
        
        { 1, 0, 1, 0}
        
    };
    
    vector<vector<int>> test3 = {
        
        { 1, 1, 0, 1, 1},
        { 1, 1, 1, 1, 1},
        { 1, 1, 0, 1, 1},
        { 1, 1, 0, 1, 1}
        
    };
    
    vector<vector<int>> test4 = {
        
        { 1, 1, 0, 1, 1},
        { 1, 1, 1, 1, 1},
        { 1, 1, 0, 1, 1},
        { 1, 1, 1, 1, 1}
        
    };
    
    assert(sol->minDays(test0) == 2);
    assert(sol->minDays(test1) == 2);
    assert(sol->minDays(test2) == 0);
    assert(sol->minDays(test3) == 1);
    assert(sol->minDays(test4) == 2);
    
    cout << "Test passed!";
    
    return 0;
}

