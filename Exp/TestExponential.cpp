#include "exponential.h"
int main() {

	try {
		Exponential e1 = { 0,0 };
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}

	Exponential e1 = {};
	Exponential e2 = { 0,5 };
	Exponential e3 = { 0,-3 };
	Exponential e4 = { 1,5 };
	Exponential e5 = { 7,0 };
	cout << e1 << '\n' << e2 << '\n' << e3 << '\n' << e4 << '\n' << e5 << '\n';

	try {
		Exponential e1 = { 3,5 };
		Exponential e2 = { 3,8 };
		cout << e1*e2 << endl;
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}

	try {
		Exponential e1 = { 3,5 };
		Exponential e2 = { 3,5 };
		cout << e1*e2 << endl;
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}

	try {
		Exponential e1 = { 7,5 };
		Exponential e2 = { 3,5 };
		cout << e1*e2 << endl;
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
	}

	Exponential e6 = { 4,5 };
	cout << e6.basiswechsel(2) << endl;
	cout << e6.basiswechsel(4) << endl;
	cout << e6.basiswechsel(5) << endl;

	Exponential e7 = { 2,10 };
	cout << endl << e7.basiswechsel(4) << endl;
	cout << e7.basiswechsel(8) << endl;


	Exponential e8 = { 32,2 };
    for(Exponential e:e8.faktoren()){
        cout<<"("<<e<<") ";
    }

	//system("pause");
	return 0;

} 