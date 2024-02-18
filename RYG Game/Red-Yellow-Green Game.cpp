//============================================================================
// Name        : Red-Yellow-Green.cpp
// Author      : Brendan Dishion
// Version     :
// Copyright   : Your copyright notice
// Description : Number Guessing Game
//============================================================================

#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class ColorGuessGame {
public:
	ColorGuessGame(){
		srand(time(nullptr));
		hidden_num = std::to_string(322); // random number
		guess_count = 0;
	}
	void play(){
		std::cout<< "Welcome to the guessing game! Only works with 3 digit #'s.\n";
		play_turn();
	}
private:
	std::string hidden_num;
	int guess_count;

	std::string get_guess(){ // gets guess
		std::string guess;
		std::cout<<"Enter a 3 digit guess and try to guess the number: ";
		std::cin>>guess;
		while(guess.size() != 3 ||
				// checks to see if first number is valid and so on
				!std::isdigit(guess[0]) ||
				!std::isdigit(guess[1]) ||
				!std::isdigit(guess[2])){
		std::cout << "Invalid input.\n"; // outputs invalid if not 3 digits
		std::cout <<"Enter a 3 digit guess: "; // restarts game
		std::cin>>guess;
	}
		return guess;
	}
	void check_guess(const std::string& guess){
		guess_count++;
		int green_count = 0;
		int yellow_count = 0;
		int red_count = 0;
		for(int i = 0; i < 3; i++){
			if(guess[i] == hidden_num[i]){ // if nums are equal return green
				green_count++;
			} else if(hidden_num.find(guess[i]) != std::string::npos){
				yellow_count++; // searches for similar numbers in both arrays, returns
								// yellow if not in order, but has correct digits
			} else{
				red_count++; // otherwise, nothing matches, return 3 reds
			}
		}
		std::cout << "You have: " << green_count << " green, " << endl <<
			yellow_count << " yellow, "	<< endl << red_count <<
			" red, " << endl; // outputs number of colors for guess
		if(green_count == 3){
			std::cout<<"Congratulations! You guessed the # in " << guess_count;
		}
		else{
			play_turn(); // if not matching, play turn and get new guess from user
		}
	}
	void play_turn(){
		std::string guess = get_guess();
		check_guess(guess);
	}
};

int main() {
	ColorGuessGame game; // instantiate class
	game.play(); // play game
	return 0;
};
