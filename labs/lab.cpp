#include <iostream>
#include <string>

using namespace std;

class Vehicle {
private:
	string type;

public:
	Vehicle() {
		type = " ";
	}

	Vehicle(const Vehicle& v) {
		this -> type = v.type;
	}

	Vehicle& operator=(const Vehicle v) {
		this -> type = v.type;
	}

	Vehicle(string type) {
		this -> type = type;
	}

	string get_type() {
		return type;
	}

	void set_type(string type) {
		this -> type = type;
	}

	void print_vehicles() {
		cout << type;
	}

};

class Person {
private:
	string name;
	int num_vehicle;
	Vehicle* vehicles;

public:
	Person() {
		name = " ";
		num_vehicle = 0;
		vehicles = NULL;
	}

	Person(const Person& p) {
		this -> name = p.name;
		this -> num_vehicle = p.num_vehicle;
		this -> vehicles = new Vehicle[num_vehicle];
		for (int i = 0; i < num_vehicle; i++) {
			this -> vehicles[i] = p.vehicles[i];
		}
	}

	Person& operator=(const Person& p) {
		if(this != &p) {
			this -> name = p.name;
			this -> num_vehicle = p.num_vehicle;
			delete [] this -> vehicles;
			this -> vehicles = new Vehicle[num_vehicle];
			for (int i = 0; i < num_vehicle; i++) {
				this -> vehicles[i] = p.vehicles[i];
			}
		}
		return *this;
	}

	~Person() {
		if (num_vehicle > 0) {
			delete [] vehicles;
		}
		vehicles = NULL;
	}

	string get_name() {
		return name;
	}

	void set_name(string name) {
		this -> name = name;
	}

	int get_num_v() {
		return num_vehicle;
	}

	Vehicle get_vehicle(int i) {
		return vehicles[i];
	}

	void create_arr(int num) {
		num_vehicle = num;
		string temp;
		vehicles = new Vehicle[num_vehicle];
		for (int i = 0; i < num_vehicle; i++) {
			cout << "Enter vehicle type: ";
			cin >> temp;
			Vehicle v(temp);
			vehicles[i] = v;
		}
	}

	void add_vehicle(Vehicle v) {
		Vehicle* temp = new Vehicle[num_vehicle + 1];
		if (num_vehicle != 0) {
			for (int i = 0; i < num_vehicle; i++) {
				temp[i] = vehicles[i];
			}
		}
		delete [] vehicles;
		vehicles = temp;
		vehicles[num_vehicle] = v;
		num_vehicle++;
	}

	void print_vehicles() {
		for (int i = 0; i < num_vehicle; i++) {
			cout << "Vehicle " << i + 1 << ": ";
			vehicles[i].print_vehicles();
			cout << endl;
		}
	}
};

void printPersonInfo(Person p) {
	cout << "Name: " << p.get_name() << endl;
	p.print_vehicles();
}

int main() {
	Person p;
	string temp;
	int num;

	cout << "Enter name: ";
	cin >> temp;
	p.set_name(temp);

	cout << "Enter number of vehicles: ";
	cin >> num;
	p.create_arr(num);

	printPersonInfo(p);

	return 0;
}
