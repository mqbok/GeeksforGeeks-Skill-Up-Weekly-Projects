

#include <iostream>
using namespace std;

int main()
{
	cout << "*******************************" << endl;
	cout << "*     Temperature Converter   *" << endl;
	cout << "*******************************" << endl;
	cout << "1.Celsius to Fahrenheit" << endl;
	cout << "2.Fahrenheit to Celsius" << endl;
	cout << "Select an option (1 or 2): ";
	int option;
	cin >> option;
	double temp;
	double result;
	switch (option){
		case 1:
			cout << "Enter temperature in Celsius: ";
			cin >> temp;
			result = (temp * 9.0 / 5.0) + 32.0;
			cout << fixed << setprecision(2) << "Temperature in Fahrenheit: " << result << " F" << endl;
			break;
		case 2:
			cout << "Enter temperature in Fahrenheit: ";
			cin >> temp;
			result = (temp - 32.0) * 5.0 / 9.0;
			cout << fixed << setprecision(2) << "Temperature in Celsius: " << result << " C" << endl;
			break;
		default:
			cout << "Invalid option selected." << endl;
			return 0;
	}
}
