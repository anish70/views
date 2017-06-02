#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int
main()
{
	double fahr;

	cout<<-sizeof(char);

	cout << "Enter the Fahreheit value: \n";
	cin >> fahr;

	// T(°F) = T(°C) × 9/5 + 32
	// T(°C) = (T(°F) - 32.0) × 5/9 + 32
	double cgrade = ((fahr - 32.0) *  5.0/9.0);

	cout << "Centigrade value: " << setprecision(4) << cgrade << endl;

	return 0;
}
