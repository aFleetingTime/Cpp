#include <iostream>
#include <string>
#include <vector>

double addString(std::vector<std::string> &svec)
{
	double ret = 0;
	if(!svec.size()) return ret;
	const char *numbers = "+-0123456789";
	for(const std::string &val : svec)
	{
		std::string::size_type index = 0, temp = 0;
		while((index = val.find_first_of(numbers, index)) != std::string::npos)
		{
			ret += stod(val.substr(index), &temp);	
			index += temp;
		}
	}
	return ret;
}

int main()
{
	std::vector<std::string> svec;
	std::string input;
	for(std::string input; std::cout << "input: ", std::cin >> input; svec.push_back(input));
	std::cin.clear();
	std::cout << "\nsum: " << addString(svec) << std::endl;
}
