#include <iostream>
#include <vector>
using namespace std;

int findPaths(const vector<vector<int>>& grid, int r, int c, int cost) {
    
    if (r < 0 || c < 0 || cost < 0) return 0;
    if (r == 0 && c == 0)
        return (grid[0][0] == cost) ? 1 : 0;

   
    int fromTop = findPaths(grid, r - 1, c, cost - grid[r][c]);
    int fromLeft = findPaths(grid, r, c - 1, cost - grid[r][c]);

    return fromTop + fromLeft;
}

int main() {
    vector<vector<int>> grid = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    int target = 25;
    int rows = grid.size() - 1;
    int cols = grid[0].size() - 1;

    int totalPaths = findPaths(grid, rows, cols, target);
    cout << "Number of paths with total cost " << target << " = " << totalPaths << endl;

    return 0;
}
