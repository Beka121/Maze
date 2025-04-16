void print() const {
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (grid[y][x] == START) cout << START << ' ';
            else if (grid[y][x] == EXIT) cout << EXIT << ' ';
            else if (solutionPath[y][x]) cout << SOLUTION << ' ';
            else cout << grid[y][x] << ' ';
        }
        cout << endl;
    }
}
