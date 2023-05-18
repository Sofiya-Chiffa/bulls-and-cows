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

int check(int num, int rn) {
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

bool checkcow(int n, int r, int c) {
	int count = 0;

	int a1 = n % 10;
	int a2 = n % 100 / 10;
	int a3 = n % 1000 / 100;
	int a4 = n / 1000;

	int b1 = r % 10;
	int b2 = r % 100 / 10;
	int b3 = r % 1000 / 100;
	int b4 = r / 1000;

	if (a1 == b1 || a1 == b2 || a1 == b3 || a1 == b4) {
		count += 1;
	}
	if (a2 == b1 || a2 == b2 || a2 == b3 || a2 == b4) {
		count += 1;
	}
	if (a3 == b1 || a3 == b2 || a3 == b3 || a3 == b4) {
		count += 1;
	}
	if (a4 == b1 || a4 == b2 || a4 == b3 || a4 == b4) {
		count += 1;
	}
	if (c == 0 && count != 0) {
		return false;
	}
	return count >= c;
}

bool checkbull(int n, int r, int c) {
	int count = 0;

	if (n / 1000 == r / 1000) {
		count += 1;
	}
	if (n % 1000 / 100 == r % 1000 / 100) {
		count += 1;
	}
	if (n % 100 / 10 == r % 100 / 10) {
		count += 1;
	}
	if (n % 10 == r % 10) {
		count += 1;
	}
	return count >= c;

}

int main() {
	srand(time(0));
	int numb = number();
	cout << "need number: " << numb << "\n\n";
	int arr[9000] = {};
	int len = 0;
	for (int i = 1000; i < 10000; ++i) {
		if (i % 10 != i % 100 / 10 && i % 10 != i % 1000 / 100 && i % 10 != i / 1000 &&
			i % 100 / 10 != i % 1000 / 100 && i % 100 / 10 != i / 1000 && i % 1000 / 100 != i / 1000) {
			arr[len] = i;
			len += 1;
		}
	}
	int w = 0;
	for (int i = 0; i < 20; ++i) {
		int ind = rand() % len;
		int num = arr[ind];
		cout << i << ". " << num << "\n";
		cout << "cows: ";
		int ch1;
		cin >> ch1;
		cout << "bulls: ";
		int ch2;
		cin >> ch2;
		int ch = ch1 + ch2 * 10;
		if (ch == 40) {
			w = 1;
			cout << "win\n";
			break;
		}
		int k = 0;
		while (k < len) {
			int nk = arr[k];
			if (nk == num || !checkbull(nk, num, ch / 10) || !checkcow(nk, num, ch / 10 + ch % 10)) {
				for (long m = k; m < len; ++m)
				{
					arr[m] = arr[m + 1];
				}
				--len;
			}
			else {
				k++;
			}

		}
	}
	if (w == 0) {
		cout << "loose\n";
	}

}
