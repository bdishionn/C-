//============================================================================
// Name        : Poker.cpp
// Author      : Brendan Dishion
// Version     :
// Copyright   : Your copyright notice
// Description : Homework Poker
//============================================================================

#include<stdio.h>

void take_input();
int is_onepair(int player);
int check_three(int x, int y, int z);
int is_twopair(int player);
int is_tok(int player);
int is_straight(int player);
int is_flush(int player);
int is_fullhouse(int player);
int is_fourofkind(int player);
int is_straight_flush(int player);
int check_player(int player);
int check_winner();

struct card {
	char color;
	int value;
};
struct card game_card[10];

//function to take input for the cards and convert value of ace to 14 if user enters 1
void take_input() {
	printf("Please enter details of cards\n");

	//as use of loops is restricted

	scanf("%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c",
			&game_card[0].value, &game_card[0].color, &game_card[1].value,
			&game_card[1].color, &game_card[2].value, &game_card[2].color,
			&game_card[3].value, &game_card[3].color, &game_card[4].value,
			&game_card[4].color, &game_card[5].value, &game_card[5].color,
			&game_card[6].value, &game_card[6].color, &game_card[7].value,
			&game_card[7].color, &game_card[8].value, &game_card[8].color,
			&game_card[9].value, &game_card[9].color);

	if (game_card[0].value == 1) {
		//game_card[0].value == 14;
	}

	if (game_card[1].value == 1) {
		game_card[1].value == 14;
	}

	if (game_card[2].value == 1) {
		//game_card[2].value == 14;
	}

	if (game_card[3].value == 1) {
		//game_card[3].value == 14;
	}

	if (game_card[4].value == 1) {
		//game_card[4].value == 14;
	}

	if (game_card[5].value == 1) {
		//game_card[5].value == 14;
	}

	if (game_card[6].value == 1) {
		//game_card[6].value == 14;
	}

	if (game_card[7].value == 1) {
		//game_card[7].value == 14;
	}

	if (game_card[8].value == 1) {
		//game_card[8].value == 14;
	}

	if (game_card[9].value == 1) {
		//game_card[9].value == 14;
	}

}
//function to check one pair
int is_onepair(int player) {
	if (player == 1) {
		int a, b, c, d, e;
		a = game_card[0].value;
		b = game_card[1].value;
		c = game_card[2].value;
		d = game_card[3].value;
		e = game_card[4].value;
		if (a == b || a == c || a == d || a == e || b == c || b == d || b == e
				|| c == d || c == e || d == e) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int a, b, c, d, e;
		a = game_card[5].value;
		b = game_card[6].value;
		c = game_card[7].value;
		d = game_card[8].value;
		e = game_card[9].value;
		if (a == b || a == c || a == d || a == e || b == c || b == d || b == e
				|| c == d || c == e || d == e) {
			return 1;
		} else {
			return 0;
		}
	}
}
//function to check one pair


//function to check if atleast two of three number are equal or not
//this function will be used by the next funtion
int check_three(int x, int y, int z) {
	if (x == y || x == z || y == z) {
		return 1;
	} else {
		return 0;
	}
}

int is_twopair(int player) {
	if (player == 1) {
		int a, b, c, d, e;
		a = game_card[0].value;
		b = game_card[1].value;
		c = game_card[2].value;
		d = game_card[3].value;
		e = game_card[4].value;
		if ((a == b) && (check_three(c, d, e) == 1)) {
			return 1;
		} else if ((a == c) && (check_three(b, d, e) == 1)) {
			return 1;
		} else if ((a == d) && (check_three(c, b, e) == 1)) {
			return 1;
		} else if ((a == e) && (check_three(b, c, d) == 1)) {
			return 1;
		} else if ((b == c) && (check_three(a, d, e) == 1)) {
			return 1;
		} else if ((b == d) && (check_three(a, c, e) == 1)) {
			return 1;
		} else if ((b == e) && (check_three(a, c, d) == 1)) {
			return 1;
		} else if ((c == d) && (check_three(a, b, e) == 1)) {
			return 1;
		} else if ((c == e) && (check_three(a, b, d) == 1)) {
			return 1;
		} else if ((d == e) && (check_three(a, b, c) == 1)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int a, b, c, d, e;
		a = game_card[5].value;
		b = game_card[6].value;
		c = game_card[7].value;
		d = game_card[8].value;
		e = game_card[9].value;
		if ((a == b) && (check_three(c, d, e) == 1)) {
			return 1;
		} else if ((a == c) && (check_three(b, d, e) == 1)) {
			return 1;
		} else if ((a == d) && (check_three(c, b, e) == 1)) {
			return 1;
		} else if ((a == e) && (check_three(b, c, d) == 1)) {
			return 1;
		} else if ((b == c) && (check_three(a, d, e) == 1)) {
			return 1;
		} else if ((b == d) && (check_three(a, c, e) == 1)) {
			return 1;
		} else if ((b == e) && (check_three(a, c, d) == 1)) {
			return 1;
		} else if ((c == d) && (check_three(a, b, e) == 1)) {
			return 1;
		} else if ((c == e) && (check_three(a, b, d) == 1)) {
			return 1;
		} else if ((d == e) && (check_three(a, b, c) == 1)) {
			return 1;
		} else {
			return 0;
		}
	}
}
int is_tok(int player) {
	if (player == 1) {
		int a, b, c, d, e;
		a = game_card[0].value;
		b = game_card[1].value;
		c = game_card[2].value;
		d = game_card[3].value;
		e = game_card[4].value;
		if ((a == b && b == c) || (a == b && b == d) || (a == b && b == e)
				|| (a == c && c == d) || (a == c && c == e)
				|| (a == d && d == e) || (b == c && c == d)
				|| (b == c && c == e) || (b == d && d == e)
				|| (c == d && d == e)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int a, b, c, d, e;
		a = game_card[5].value;
		b = game_card[6].value;
		c = game_card[7].value;
		d = game_card[8].value;
		e = game_card[9].value;
		if ((a == b && b == c) || (a == b && b == d) || (a == b && b == e)
				|| (a == c && c == d) || (a == c && c == e)
				|| (a == d && d == e) || (b == c && c == d)
				|| (b == c && c == e) || (b == d && d == e)
				|| (c == d && d == e)) {
			return 1;
		} else {
			return 0;
		}
	}
}

//function to check straight
int is_straight(int player) {
	if (player == 1) {
		int a, b, c, d;
		a = game_card[0].value + 4;
		b = game_card[1].value + 3;
		c = game_card[2].value + 2;
		d = game_card[3].value + 1;
		if (a == b && b == c && c == d && d == game_card[4].value) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int a, b, c, d;
		a = game_card[5].value + 4;
		b = game_card[6].value + 3;
		c = game_card[7].value + 2;
		d = game_card[8].value + 1;
		if (a == b && b == c && c == d && d == game_card[9].value) {
			return 1;
		} else {
			return 0;
		}
	}
}

int is_flush(int player) {
	if (player == 1) {
		int a, b, c, d;
		a = game_card[0].color;
		b = game_card[1].color;
		c = game_card[2].color;
		d = game_card[3].color;
		if (a == b && b == c && c == d && d == game_card[4].color) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int a, b, c, d;
		a = game_card[5].color;
		b = game_card[6].color;
		c = game_card[7].color;
		d = game_card[8].color;
		if (a == b && b == c && c == d && d == game_card[9].color) {
			return 1;
		} else {
			return 0;
		}
	}
}


int is_fullhouse(int player) {
	if (player == 1) {
		if ((is_tok(1) == 1) && (is_onepair(1) == 1)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if ((is_tok(2) == 1) && (is_onepair(2) == 1)) {
			return 1;
		} else {
			return 0;
		}
	}
}

int is_fourofkind(int player) {
	if (player == 1) {
		int a, b, c, d, e;
		a = game_card[0].value;
		b = game_card[1].value;
		c = game_card[2].value;
		d = game_card[3].value;
		e = game_card[4].value;
		if ((a == b && b == c && c == d) || (b == c && c == d && d == e)
				|| (c == d && d == e && e == a) || (d == e && e == a && a == b)
				|| (e == a && a == b && b == c)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int a, b, c, d, e;
		a = game_card[5].value;
		b = game_card[6].value;
		c = game_card[7].value;
		d = game_card[8].value;
		e = game_card[9].value;
		if ((a == b && b == c && c == d) || (b == c && c == d && d == e)
				|| (c == d && d == e && e == a) || (d == e && e == a && a == b)
				|| (e == a && a == b && b == c)) {
			return 1;
		} else {
			return 0;
		}
	}
}

int is_straight_flush(int player) {
	if (player == 1) {
		if ((is_flush(1) == 1) && (is_straight(1) == 1)) {
			return 1;
		} else {
			return 0;
		}
	} else {
		if ((is_flush(2) == 1) && (is_straight(2) == 1)) {
			return 1;
		} else {
			return 0;
		}
	}
}

//function to check combination of player
//functions returns 1 for high card, 2->One pair and so on.
int check_player(int player) {
	int combi = 1;
	if (is_straight_flush(player) == 1) {
		combi = 9;
	} else if (is_fourofkind(player) == 1) {
		combi = 8;
	} else if (is_fullhouse(player) == 1) {
		combi = 7;
	} else if (is_flush(player) == 1) {
		combi = 6;
	} else if (is_straight(player) == 1) {
		combi = 5;
	} else if (is_tok(player) == 1) {
		combi = 4;
	} else if (is_twopair(player) == 1) {
		combi = 3;
	} else if (is_onepair(player) == 1) {
		combi = 2;
	}
	return combi;
}

int check_winner() {
	if (check_player(1) > check_player(2)) {
		return 1;
	} else if (check_player(2) > check_player(1)) {
		return 2;
	} else {
		//do yourself
	}
	return 0;
}

//main function
int main()
{

	take_input();
	if (check_winner() == 1) {
		printf("Player 1 wins\n");
	}
	else {
		printf("Player 2 wins\n");
	}
}

