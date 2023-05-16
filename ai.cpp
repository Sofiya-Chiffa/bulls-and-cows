#include <iostream>
#include <random>
#include <random>
using namespace std;

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

bool del(int num, int rn, int c) {
	int a1 = num % 10;
	int a2 = num % 100 / 10;
	int a3 = num % 1000 / 100;
	int a4 = num / 1000;
}

int main() {
	srand(time(0));
	int arr[9000] = {};
	for (int i = 1000; i < 10000; ++i) {
		arr[i - 1000] = i;
	}
	int number;
	cin >> number;
	int num;
	while (true) {
		num = arr[rand() % 9000];
		int ch = check(num, number);
		if (ch % 10 != 0) {
			for (int i = 0; i < sizeof(arr); ++i) {
				if (del(arr[i], number, ch % 10)) {
					
				}
			}
		}
		
	}
}
