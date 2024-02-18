//============================================================================
// Name        : MoneyCounter.cpp
// Author      : Brendan Dishion
// Version     :
// Copyright   : Your copyright notice
// Description : HW #4 CS 140, Money Counter
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

class Counter {
public:
	Counter(int max_val = 9999);
	void incr1(int digit);
	void incr10(int digit);
	void incr100(int digit);
	void incr1000(int digit);
	bool overflow();
	void reset();
	void display() const;

private:
	int max_val;
	int count;
};

Counter::Counter(int max_val) {
	this->max_val = max_val;
	count = 0;
}

void Counter::incr1(int digit) {
	if (count + 1 > max_val) {
		cout << "You have gone over the amount." << endl;
	} else {
		count = count + 1 * digit;
	}
}
void Counter::incr10(int digit) {
	if (count + 10 > max_val) {
		cout << "You have gone over the amount." << endl;
	} else {
		count += 10 * digit;
	}
}

void Counter::incr100(int digit) {
	if (count + 100 > max_val) {
		cout << "You have gone over the amount." << endl;
	} else {
		count += 100 * digit;
	}
}

void Counter::incr1000(int digit) {
	if (count + 1000 > max_val) {
		cout << "You have gone over the amount." << endl;
	} else {
		count += 1000 * digit;
	}
}
bool Counter::overflow() {
	return count > max_val;
}

void Counter::reset() {
	count = 0;
}

void Counter::display() const {
	cout << setw(2) << count / 1000 << setw(1) << count / 100 % 10 << ".";
	cout << setw(2) << count / 10 % 10 << setw(1) << count % 10 << endl;
}

int main() {
	int max_val;
	cout
			<< "Please enter an integer amount less than 9999 to initialize the counter."
			<< endl;
	cin >> max_val;

	Counter counter(max_val);
	cout << "Maximum value of the counter is " << max_val << endl;
	cout << "Current value of the counter is ";
	counter.display();

	char key;
	int digit;
	while (true) {
		cout
				<< "Enter a key, either a, s, d, f, followed by 1-9. or o for overflow"
				<< endl;
		cin >> key;
		if (key == 'o') {
			if (counter.overflow()) {
				cout << "There is an overflow." << endl;
			} else {
				cout << "There is no overflow." << endl;
			}
		} else if (key == 'a' || key == 's' || key == 'd' || key == 'f') {
			cin >> digit;
			if (digit < 1 || digit > 9) {
				cout << "Invalid digit." << endl;
			} else {
				switch (key) {
				case 'a':
					counter.incr1(digit);
					break;
				case 's':
					counter.incr10(digit);
					break;
				case 'd':
					counter.incr100(digit);
					break;
				case 'f':
					counter.incr1000(digit);
					break;
				}
				counter.display();
			}
		} else {
			cout << "Invalid key." << endl;
		}
	}

	return 0;
}


