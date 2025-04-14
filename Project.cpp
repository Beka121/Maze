#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int SIZE = 12;
const char WALL = '#';
const char PATH = ' ';
const char START = 'S';
const char EXIT = 'E';
const char SOLUTION = '.';

struct Point {
	//ram
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Maze {
private:
    vector<vector<char>> grid;
    	vector<vector<bool>> solutionPath;
    	Point start;
    	Point exit;
//map
public:
    Maze() : grid(SIZE, vector<char>(SIZE, WALL)), 
             solutionPath(SIZE, vector<bool>(SIZE, false)),
             start(1, 1), exit(SIZE-2, SIZE-2) {
        srand(time(0));
        generate();
        placeStartExit();
    }
//dfs
    void generate() {
        stack<Point> st;
        st.push(Point(1, 1));
        grid[1][1] = PATH;
//dfs stack 
        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};
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
//recursive 
    bool solve() {
        vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));
        return findPath(start.x, start.y, visited);
    }
//check
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

int main() {
    Maze maze;

    cout << "Generated Maze:" << endl;
    maze.print();
// output
    cout << "\nSolving Maze..." << endl;
    if (maze.solve()) {
        cout << "\nSolved Maze" << endl;
        maze.print();
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}