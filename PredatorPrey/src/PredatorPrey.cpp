//============================================================================
// Name        : PredatorPrey.cpp
// Author      : Brendan Dishion
// Version     :
// Copyright   : Your copyright notice
// Description : Predator Prey
//============================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int a[20][20], p = 0, q = 0;
void step(int g, int h, int i, int &u, int &v);

class org {
public:
	int varx, vary, life;
};
class bug: public org {
public:
	void birth(int vare, int varf) {
		varx = vare;
		vary = varf;
		life = 0; // bug is born
		a[vare][varf] = 2; // indicates ant being born, presence of bug in array
		p++;
	}
	void move();
	void breed();
	void death() {
		a[varx][vary] = 0; // indicates death, ant is no longer in array
	}
} bugs[400]; // size of array 20 x 20
void bug::move() {
	int k = 0, t1, t2, i;
	life++;
	// Check each possible direction
	for (i = 0; i < 4; i++) {
		step(varx, vary, i, t1, t2);
		if (a[t1][t2] == 0)
			k++;
	}
	// If there is at least one empty cell, move the bug to a random empty cell
	if (k > 0) {
		// Choose a random direction with an empty cell
		if (k != 1)
			k = (rand() % k + 1);
		// Move the bug to the chosen empty cell
		for (i = 0; i < 4 && k > 0; i++) {
			step(varx, vary, i, t1, t2);
			if (a[t1][t2] == 0)
				k--;
		}
		// Update the positions of the bug and the grid
		a[varx][vary] = 0;
		a[t1][t2] = 2;
		varx = t1;
		vary = t2;
		// If the bug has lived for at least 3 cycles, it breeds
		if (life >= 3) {
			this->breed();
			life = 0;
		}
	}
}
void bug::breed() {
	int i, k = 0, t1, t2;
	for (i = 0; i < 4; i++) {
		step(varx, vary, i, t1, t2);
		if (a[t1][t2] == 0)
			k++;
	}
	if (k != 1)
		k = (rand() % k + 1);
	for (i = 0; i < 4 && k > 0; i++) {
		step(varx, vary, i, t1, t2);
		if (a[t1][t2] == 0)
			k--;
	}
	bugs[p].birth(t1, t2);
}
class doodles: public org {
public:
	int moves;
	void birth(int e, int f) {
		varx = e;
		vary = f;
		life = 3;
		moves = 0;
		a[e][f] = 1;
		q++;
	}
	void move();
	void breed();
	void death() {
		a[varx][vary] = 0;
	}
} doodle[400];
void shiftb();
void shiftd();
void doodles::move() {
	int k = 0, t1, t2;
	moves++;
	for (int i = 0; i < 4; i++) {
		step(varx, vary, i, t1, t2);
		if (a[t1][t2] == 2)
			k++;
	}
	if (k == 0)
		life--;
	else {
		if (k != 1)
			k = (rand() % k + 1);
		for (int i = 0; i < 4 && k > 0; i++) {
			step(varx, vary, i, t1, t2);
			if (a[t1][t2] == 2)
				k--;
		}
		life = 3;
		for (int j = 0; j < p; j++) {
			if ((bugs[j].varx == t1) && (bugs[j].vary == t2)) {
				bugs[j].death();
				shiftb();
			}
		}
		a[this->varx][this->vary] = 0;
		a[t1][t2] = 1;
		this->varx = t1;
		this->vary = t2;

	}
	if (moves >= 8)
		this->breed();
	if (life <= 0)
		this->death();
}
void doodles::breed() {
	int i, k = 0, t1, t2;
	for (i = 0; i < 4; i++) {
		step(varx, vary, i, t1, t2);
		if (a[t1][t2] == 0)
			k++;
	}
	if (k > 0) {
		if (k != 1)
			k = (rand() % k + 1);
		for (i = 0; i < 4 && k > 0; i++) {
			step(varx, vary, i, t1, t2);
			if (a[t1][t2] == 0)
				k--;
		}
		doodle[q].birth(t1, t2);
	}
}
void display() {
	int i, j;
	char c;
	system("cls");
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			if (a[i][j] == 0)
				c = '-';
			if (a[i][j] == 1)
				c = 'x';
			if (a[i][j] == 2)
				c = 'o';
			cout << c << " ";
		}
		cout << "\n";
	}
}
void step(int g, int h, int i, int &u, int &v) {
	u = g;
	v = h;
	if (i == 0)
		u--;
	if (i == 1)
		v++;
	if (i == 2)
		u++;
	if (i == 3)
		v--;
	if (u < 0 || v < 0 || u > 19 || v > 19) {
		u = g;
		v = h;
	}
}
void shiftb() {
	int j;
	if (p != 1)
		for (j = 0; j < p;) {
			if (a[bugs[j].varx][bugs[j].vary] == 0) {
				p--;
				for (int k = j; k < p; k++)
					bugs[k] = bugs[k + 1];
			} else
				j++;
		}
	if (p == 1)
		if (a[bugs[0].varx][bugs[0].vary] == 0)
			p--;
}
void shiftd() {
	int j;
	if (q != 1)
		for (j = 0; j < q;) {
			if (a[doodle[j].varx][doodle[j].vary] == 0) {
				q--;
				for (int k = j; k < q; k++)
					doodle[k] = doodle[k + 1];
			} else
				j++;
		}
	if (q == 1)
		if (a[doodle[0].varx][doodle[0].vary] == 0)
			q--;
}
int main() {
	system("cls");
	int m, n, i, j, s, t;
	char ch = 'y';
	cout << "Enter # of doodles(1st)/ants(2nd) that you want:" << endl;
	cin >> s >> t;
	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			a[i][j] = 0;
	srand(time(0));
	for (i = 0; i < s; i++) {
		do {
			m = rand() % 20;
			n = rand() % 20;
		} while (a[m][n] != 0);
		doodle[i].birth(m, n);
	}
	for (i = 0; i < t; i++) {
		do {
			m = rand() % 20;
			n = rand() % 20;
		} while (a[m][n] != 0);
		bugs[i].birth(m, n);
	}
	display();
	ch = cin.get();
	while (true) {
		for (i = 0; i < q; i++)
			doodle[i].move();
		shiftd();
		for (i = 0; i < p; i++)
			bugs[i].move();

		display();
		cout << "Press Enter for next";
		ch = cin.get();
	}
}
