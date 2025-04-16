private:
    bool findPath(int x, int y, vector<vector<bool>>& visited) {
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || visited[y][x] || grid[y][x] == WALL) {
            return false;
        }

        visited[y][x] = true;

        if (Point(x, y) == exit) {
            solutionPath[y][x] = true;
            return true;
        }

        if (findPath(x+1, y, visited) || findPath(x-1, y, visited) || 
            findPath(x, y+1, visited) || findPath(x, y-1, visited)) {
            if (grid[y][x] == PATH) {
                solutionPath[y][x] = true;
            }
            return true;
        }

        return false;
    }
};
