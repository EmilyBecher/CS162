#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct mult_div_values {
	int mult;
	float div;
};

void get_int(int &num, string prompt);
mult_div_values** create_table(int n);
void set_mult_values(mult_div_values** table, int n);
void set_div_values(mult_div_values** table, int n);
void delete_table(mult_div_values** table, int n);
bool is_valid_dimension(string/*char**/ c, int& num);
void get_bool(bool &play, string prompt);

int main(int argc, char* argv[]) {
	int n = 0;
	bool play = 1;

	while (play) {
		if (argc == 2 && atoi(argv[1]) > 0 && atoi(argv[1]) < 16) {
			n = atoi(argv[1]);
			argc = 0;
		}
		else {
			get_int(n, "Enter an integer: ");
		}
		mult_div_values** table = create_table(n);
		set_mult_values(table, n);
		set_div_values(table, n);
		delete_table(table, n);

		get_bool(play, "Would you like to see another matrix? ");
	}

	return 0;
}

mult_div_values** create_table(int n) {
	mult_div_values** table = new mult_div_values*[n];
	for(int i = 0; i < n; i++) {
		table[i] = new mult_div_values[n];
	}

	return table;
}

void set_mult_values(mult_div_values** table, int n) {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			table[i][j].mult = (i + 1) * (j + 1);
		}
	}

	cout << "Multiplication Table" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (table[i][j].mult > 9) {
				cout << " " << table[i][j].mult << " ";
			}
			else {
				cout << "  " << table[i][j].mult << " ";
			}
		}
		cout << endl;
	}
}

void set_div_values(mult_div_values** table, int n) {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			table[i][j].div = (i + 1.00)/(j + 1.00);
		}
	}

	cout << std::setprecision(2) << std::fixed;

	cout << "Division Table" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << " " << table[i][j].div << " ";
		}
		cout << endl;
	}
}

void delete_table(mult_div_values** table, int n) {
	for(int i = 0; i < n; i++) {
		delete [] table[i];
	}
	delete [] table;
	table = NULL;
}

void get_int(int &num, string prompt) {
	bool bad = 1;
	string c;
	//char c;
	cout << prompt;
	while(bad) {
		getline(cin, c);
		/*cin >> c;
		cin.ignore(1000, '\n');
		cin.clear();*/
		for(int i = 0; i < c.length(); i++) {
			/* Checks for invalid characters */
			if(c[i] < 48 || c[i] > 57) {
				cout << "Invalid input, try again: ";
				break;
			}
			else if(i == c.length() -1) {
				bad = is_valid_dimension(/*&*/c, num);
				//num = atoi(c);
			}
		}
	}
}

bool is_valid_dimension(string/*char**/ c, int& num) {
	num = atoi(c.c_str());
	if(num < 1) {
		cout << "Enter a number of at least 1: ";
	}
	else if(num > 15) {
		cout << "Enter a number less than 16: ";
	}
	/* Valid input*/
	else {
		return 0;
	}
	return 1;
}

void get_bool(bool &play, string prompt) {
	string str;
	bool bad = 1;
	cout << prompt;
	while(bad) {
		getline(cin, str);
		if(str.length() != 1) {
			cout << "Enter y or n: ";
		}
		/* True cases*/
		else if(str == "y" || str == "Y" || str == "1") {
			play = 1;
			bad = 0;
		}
		/* False cases*/
		else if(str == "n" || str == "N" || str == "0") {
			play = 0;
			bad = 0;
		}
		else {
			cout << "Enter y or n: ";
		}
	}
}