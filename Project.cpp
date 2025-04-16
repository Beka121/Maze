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
