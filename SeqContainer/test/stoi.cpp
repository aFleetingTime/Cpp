#include <iostream>
#include <string>

using namespace std;

int main()
{
	size_t index = 0;
	const char *numbers = "0123456789";
	string::size_type size = 0;
	for(string input; cout << "input:", cin >> input;)
	{
		if((size = input.find_first_of(numbers)) != string::npos)
		{
			cout << "output:" << stoi(input.substr(size), &index) << endl;
			cout << "index:" << index << endl;
		}

	}
	cout << endl;
}
