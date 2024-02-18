//============================================================================
// Name        : RatMaze.cpp
// Author      : Brendan Dishion
// Version     :
// Copyright   : Your copyright notice
// Description : HW #14 Rat Maze
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // size of the maze

// check if a cell is a valid move
bool is_valid_move(int x, int y, const vector<vector<int>> &maze) {
	return x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1;
}

// recursive function to solve the maze
bool solve_maze_helper(const vector<vector<int>> &maze,
		vector<vector<int>> &solution, int x, int y) {
	// base case: check if we reached the destination
	if (x == N - 1 && y == N - 1) {
		solution[x][y] = 1; // mark the destination
		return true;
	}
	// check if the current cell is a valid move
	if (!is_valid_move(x, y, maze)) {
		return false;
	}
	// mark the current cell as part of the solution
	solution[x][y] = 1;
	// try to move right and down recursively
	if (solve_maze_helper(maze, solution, x, y + 1)
			|| solve_maze_helper(maze, solution, x + 1, y)) {
		return true; // if one of the moves leads to the destination, return true
	}
	// unmark the current cell and backtrack
	solution[x][y] = 0;
	return false;
}

// main function to solve the maze
void solve_maze(const vector<vector<int>> &maze) {
	vector<vector<int>> solution(N, vector<int>(N, 0)); // create a solution matrix filled with 0's
	if (solve_maze_helper(maze, solution, 0, 0)) { // start at the top-left corner
		// if a solution was found, print it
		cout << "Solution:" << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << solution[i][j] << " ";
			}
			cout << endl;

		}
		cout << endl;
	} else {
		cout << "No solution found" << endl;
	}
}

// test cases
int main() {
	vector<vector<int>> maze1 = { { 0, 0, 0, 0, 0 }, { 1, 1, 0, 1, 0 }, { 0, 1,
			1, 1, 0 }, { 0, 0, 0, 1, 0 }, { 1, 1, 1, 1, 1 } };
	vector<vector<int>> maze2 = { { 1, 0, 1, 0, 0 }, { 1, 1, 1, 1, 1 }, { 0, 1,
			0, 1, 0 }, { 1, 1, 0, 1, 1 }, { 0, 1, 1, 0, 1 } };
	solve_maze(maze1);
	solve_maze(maze2);
	return 0;
}

