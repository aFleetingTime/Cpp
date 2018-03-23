#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int i = 20;
	double d = -3.141592654;
	string s("-Hello World!!!");
	constexpr unsigned max = 14;

	cout << setw(max) << "boolalpha: " << boolalpha << true << " " << false << noboolalpha << endl;
	cout << setw(max) << "showbase hex: " << showbase << hexfloat << hex << i << " " << d << endl
		 << oct << "showbase oct: " << i << " " << d << endl
		 << dec << "showbase dec: " << i << " " << d << noshowbase << defaultfloat << endl;
	cout << setw(max) << "uppercase: " << uppercase << hex << i << " " << oct << i << " " << dec << i << nouppercase << endl;
	cout << setw(max) << "showpoint: " << showpoint << d << " " << 3.0 << noshowpoint << " " << 3.0 << endl;
	cout << setw(max) << "fixed: " << fixed << setprecision(9) << d << endl
		 << setw(max) << "scientific: " << scientific << d << endl
		 << setw(max) << "hexfloat: " << hexfloat << d << defaultfloat << setprecision(6) << endl;
	cout << setw(max) << "right: " << setfill('*') << right << setw(i) << i << setw(i) << d << setw(i) << s << setfill(' ') << endl
		 << setw(max) << "left: " << setfill('#') << left << setw(i) << i << setw(i) << d << setw(i) << s << right << setfill(' ') << endl
		 << setw(max) << "internal: " << setfill('@') << internal << setw(i) << i << setw(i) << d << setw(i) << s << right << setfill(' ') << endl;
	cout << "--------------- input stream ----------------" << endl;
	istringstream iss(s + " Input Test ...\t #");
	iss >> noskipws;
	char temp;
	unsigned count = 0;
	cout << setw(max) << "text: ";
	while(iss >> temp)
	{
		cout << temp;
		++count;
	}
	cout << '\n' << setw(max) << "read count: " << count << endl;
}
