//dfs
    void generate() {
        stack<Point> st;
        st.push(Point(1, 1));
        grid[1][1] = PATH;
//dfs stack 
        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};
