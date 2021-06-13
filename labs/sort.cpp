/** Tasks
 ** fill dynamic array of length 1-25 with random ints
 ** ints are between 1-100
 ** length is determined by user
 ** print array
 ** sort array into ascending order
 ** print primes
 ** free memory
 */

#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Sort {
private:
	int* arr;
	int n;
public:
	Sort();
	Sort(int);
	Sort(Sort& arr);

	~Sort();

	int get_n();
	int get_ele(int);

	void randomize();
	void merge(int, int);
	void print_arr();
	void print_primes();
	bool prime(int);
};


int main(int argc, char* argv[]) {
	int size = 0;
	if (argc == 2) {
		for (int i = 0; i < strlen(argv[1]); i++) {
			if((int)argv[1][i] < 48 || (int)argv[1][i] > 57) {
				cout << "expected integer command line arg" << endl;
				return 0;
			}
			size = stod(argv[1]);
		}
	}
	else {
		cout << "expected integer command line arg" << endl;
		return 0;
	}
	srand(time(nullptr));

	Sort s(size);

	s.randomize();
	Sort copy(s);

	copy.merge(0, size - 1);

	s.print_arr();
	copy.print_arr();
	copy.print_primes();

	return 0;
}

Sort::Sort() {
	arr = nullptr;
	n = 0;
}

Sort::Sort(int n) {
	arr = new int[n];
	this -> n = n;
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
}

Sort::Sort(Sort& sort) {
	this -> n = sort.get_n();
	this -> arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = sort.get_ele(i);
	}
}

Sort::~Sort() {
	delete [] arr;
	arr = nullptr;
}

int Sort::get_n() {
	return n;
}

int Sort::get_ele(int i) {
	if (arr != nullptr) {
		return arr[i];
	}
	return -1;
}

void Sort::randomize() {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100 + 1;
	}
}

void Sort::merge(int l, int r) {
	if (l >= r) {
		return;
	}
	int mid = (l + r) / 2;
	merge(l, mid);
	merge(mid + 1, r);
	int* left = new int[mid - l + 1];
	int* right = new int[r - mid];
	//print_arr();
	for (int i = 0; i < mid - l + 1; i++) {
		left[i] = arr[l + i];
	}
	for (int i = 0; i < r - mid; i++) {
		right[i] = arr[mid + i + 1];
	}
	int j = 0, k = 0, i = 0;
	while (i < mid - l + 1 && j < r - mid) {
		if (left[i] <= right[j]) {
			arr[l + k] = left[i];
			i++;
		}
		else {
			arr[l + k] = right[j];
			j++;
		}
		k++;
	}
	while (i < mid - l + 1) {
		arr[l + k] = left[i];
		i++;
		k++;
	}
	while (j < r - mid) {
		arr[l + k] = right[j];
		j++;
		k++;
	}
	delete [] left;
	delete [] right;
}

void Sort::print_arr() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
 
void Sort::print_primes() {
	cout << "Primes: ";
	for (int i = 0; i < n; i++) {
		if (prime(arr[i]) == 1) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

bool Sort::prime(int num) {
	if (num == 1 || num == 2) {
		return 1;
	}
	for (int i = num - 1; i > 1; i--) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}