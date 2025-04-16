//Fisher YAtes
        while (!st.empty()) {
            Point current = st.top();
            vector<int> directions = {0, 1, 2, 3};
            random_shuffle(directions.begin(), directions.end());

            bool moved = false;
            for (int dir : directions) {
                int nx = current.x + dx[dir] * 2;
                int ny = current.y + dy[dir] * 2;

                if (nx > 0 && nx < SIZE-1 && ny > 0 && ny < SIZE-1 && grid[ny][nx] == WALL) {
                    grid[ny][nx] = PATH;
                    grid[current.y + dy[dir]][current.x + dx[dir]] = PATH;
                    st.push(Point(nx, ny));
                    moved = true;
                    break;
                }
            }

            if (!moved) {
                st.pop();
            }
        }
    }
