//============================================================================
// Name        : MineSweeper.cpp
// Author      : Brendan Dishion
// Version     :
// Copyright   : Your copyright notice
// Description : Minesweeper Assignment 
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class MineSweeper {
private:
	int ddx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
	int ddy[8] = { 0, -1, 1, 1, -1, 0, -1, 1 };

public:
	// function to check if position (i, j) is inside the matrix of size (m, n)
	bool ifPosInsideTheMatrix(int i, int j, int m, int n) {
		// if i >= 0 and i < m then i is inside the matrix
		// if j >= 0 and j < n then j is inside the matrix
		return (i >= 0 && j >= 0 && i < m && j < n);
	}

	void play() {
		int game = 1; // game #

		// while n and m are not zeroes
		while (true) {
			// m is # of rows, n is # of columns
			int m, n;
			cin >> m >> n;

			// if m and n are zero then the game ends
			if (m == 0 && n == 0) {
				break;
			}

			// input for the matrix
			char matrix[m][n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					cin >> matrix[i][j];
				}
			}

			// matrix which will count the # of adjacent mines
			int hash[m][n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					hash[i][j] = 0;
				}
			}

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					// if there is a mine on current position
					if (matrix[i][j] == '*') {
						// then we move to all adjacent positions
						for (int dir = 0; dir < 8; dir++) {
							// check if adjacent coordinate is in the matrix
							int X = i + ddx[dir], Y = j + ddy[dir];
							if (ifPosInsideTheMatrix(X, Y, m, n)) {
								hash[X][Y]++;
							}
						}
					}
				}
			}

			// printing the game number
			cout << "Game " << game << '\n';

			// printing the hash matrix
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (matrix[i][j] == '*') {
						cout << "* ";
					} else {
						cout << hash[i][j] << ' ';
					}
				}
				cout << '\n';
			}

			game++;
		}
	}
};


int main() {
	MineSweeper game;
	game.play();
	return 0;
}
