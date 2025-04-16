//random exit and start 
    void placeStartExit() {
        vector<Point> borders;
        for (int i = 1; i < SIZE-1; i++) {
            borders.emplace_back(i, 1);
            borders.emplace_back(i, SIZE-2);
            borders.emplace_back(1, i);
            borders.emplace_back(SIZE-2, i);
        }
        random_shuffle(borders.begin(), borders.end());

        start = borders[0];
        exit = borders[1];
        grid[start.y][start.x] = START;
        grid[exit.y][exit.x] = EXIT;
    }

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
