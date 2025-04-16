bool solve() {
        vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));
        return findPath(start.x, start.y, visited);
    }
