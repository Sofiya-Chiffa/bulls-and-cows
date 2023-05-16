#include <iostream>
#include <random>
#include <random>
using namespace std;

int number() {
	srand(time(0));
	int num = 0;
	num = rand() % 9000 + 1000;
	while (num % 10 == num % 100 / 10 || num % 10 == num % 1000 / 100 || num % 10 == num / 1000 ||
		num % 100 / 10 == num % 1000 / 100 || num % 100 / 10 == num / 1000 || num % 1000 / 100 == num / 1000) {
		num = rand() % 9000 + 1000;
	}
	return num;
}

int check(int num, int rn){
	int k = 0;
	int b = 0;
	
	int a1 = rn / 1000;
	int a2 = rn % 1000 / 100;
	int a3 = rn % 100 / 10;
	int a4 = rn % 10;

	int b1 = num / 1000;
	int b2 = num % 1000 / 100;
	int b3 = num % 100 / 10;
	int b4 = num % 10;

	if (a1 == b1) {
		b += 1;
	}
	else if (a1 == b2 || a1 == b3 || a1 == b4) {
		k += 1;
	}
	if (a2 == b2) {
		b += 1;
	}
	else if (a2 == b1 || a2 == b3 || a2 == b4) {
		k += 1;
	}
	if (a3 == b3) {
		b += 1;
	}
	else if (a3 == b2 || a3 == b1 || a3 == b4) {
		k += 1;
	}
	if (a4 == b4) {
		b += 1;
	}
	else if (a4 == b2 || a4 == b3 || a4 == b1) {
		k += 1;
	}
	return (b * 10) + k;

}

int main() {
	int w = 0;
	int num = number();
	cout << "_ _ _ _\n";
	for (int i = 0; i < 10; ++i) {
		int answ = 0;
		cin >> answ;
		int ch = check(answ, num);
		cout << i + 1 << ". " << ch / 10 << " bulls " << ch % 10 << " cows\n";
		if (ch == 40) {
			cout << "win!\n";
			w = 1;
			break;
		}
	}
	if (w == 0) {
		cout << "lose\n";
	}
	cout << num;
}
