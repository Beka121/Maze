
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

