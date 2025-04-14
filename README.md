
# Maze Generator and Solver

## For Reader

This program generates a random maze using a depth-first search (DFS) algorithm and solves it using a recursive backtracking approach. The program displays the maze with the start and exit points, and after solving the maze, it marks the solution path.

## Features

- **Generate Maze**: Randomly generates a maze using DFS and Fisher-Yates shuffle.
- **Solve Maze**: Finds a path from the start to the exit using recursive backtracking.
- **Random Start and Exit**: Randomly places the start and exit points on the maze's borders.
- **Visual Representation**: Displays the maze and the solution (if found).
- **Path Solution**: Marks the path from the start to the exit after solving the maze.
  
## Usage

Run the program and follow these steps:
1. **Generate Maze**: The maze is generated automatically.
2. **Solve Maze**: The program attempts to solve the maze and displays the result.

### Example Output:

```plaintext
Generated Maze:
| | | | | | | | | | | | 
| S|   | |   | | | | | 
| | | | | | | |   | | 
| |   | | | | | | | | 
| | | | | | |   | | | 
| |   |   | | | |   | 
| | |   |   |   |   | 
| | | | | | | | | | | 
| |   |   |   | | | | 
| | | | |   | |   | | 
| | | | | | | | | | E 
| | | | | | | | | | | 

Solving Maze...
Solved Maze:
| | | | | | | | | | | | 
| S| . | . | . | . | . | 
| . | # | . | . | . | . | 
| . | . | # | # | # | . | 
| # | . | . | . | # | . | 
| . | . | # | # | . | . | 
| # | . | . | . | . | # | 
| . | # | . | . | . | . | 
| . | . | . | . | . | . | 
| . | # | # | # | # | E 
| # | # | # | . | . | . | 
| | | | | | | | | | | |

```

### Explanation of Symbols:
- `S` = Start
- `E` = Exit
- `#` = Wall
- `.` = Solution path
- ` ` = Open path

## Data Structures

- `vector<vector<char>> grid`: Stores the maze layout with walls, paths, start, and exit.
- `vector<vector<bool>> solutionPath`: Stores the solution path after the maze is solved.
- `Point start`: Coordinates of the start point.
- `Point exit`: Coordinates of the exit point.
- `stack<Point> st`: Used for the depth-first search (DFS) maze generation.
- `vector<int> directions`: A random shuffle of movement directions for maze generation.
  
## Algorithm Overview

1. **Maze Generation**: 
   - Depth-first search (DFS) is used to carve paths through the maze. Walls are removed by selecting random directions and ensuring paths are created.
   - Fisher-Yates shuffle is used to randomize the directions for carving the maze.
  
2. **Solving the Maze**:
   - A recursive backtracking approach is used to find the path from the start to the exit.
   - The path is marked as the solution (`.`).

3. **Random Start and Exit Placement**: 
   - The start and exit points are randomly placed on the borders of the maze.

## Problems & Limitations

1. **Maze Size**: The maze is fixed to a 12x12 grid.
2. **No Time Handling**: The program doesn't consider time or efficiency in pathfinding.
3. **No Persistence**: The maze is not saved after the program exits.

## Requirements

- **C++** with a C++11 or later compiler.
- **Standard Library** for `vector`, `stack`, `cstdlib`, `ctime`, and `algorithm`.

## Thank You

If you have any questions or suggestions, feel free to reach out!

<p align="center">
    <a href="mailto:bekturemilev@gmail.com">
        <img src="https://img.shields.io/badge/Email-090909?style=for-the-badge&logo=gmail&logoColor=red">
    </a>
    <a href="https://t.me/Kaka_short">
        <img src="https://img.shields.io/badge/Telegram-090909?style=for-the-badge&logo=telegram&logoColor=26A5E4">
    </a>
</p>
