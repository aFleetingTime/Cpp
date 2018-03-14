#include <iostream>
#include <cctype>
#include <functional>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>

class Math
{
public:
	Math() : op { {"+", std::plus<int>()}, 
				  {"-", std::minus<int>()}, 
				  {"*", std::multiplies<int>()},
				  {"/", std::divides<int>()},
				  {"%", std::modulus<int>()} } {}

	int operation(std::string rep)
	{
		deleteSpace(rep);
		std::stack<std::string> s = transform(rep);
		return math(s);
	}

private:
	std::map<std::string, std::function<int(int, int)>> op;

	int math(std::stack<std::string> &s)
	{
		if(s.empty())
			return 0;
		std::stack<int> num;
		while(!s.empty())
		{
			char c = s.top().front();
			if(isdigit(c))
			{
				num.push(std::stoi(s.top()));
			}
			else
			{
				int a = num.top();
				num.pop();
				if(num.empty()) throw std::out_of_range("Output Error");
				int b = num.top();
				num.pop();
				num.push(op[s.top()](b, a));
			}
			s.pop();
		}
		return num.top();
	}

	std::stack<std::string> transform(const std::string &s)
	{
		std::stack<std::string> suffix, sym;
		std::queue<std::string> temp = sub(s);
		while(!temp.empty())
		{
			char c = temp.front().front();
			if(isdigit(c))
			{
				suffix.push(temp.front());
			}
			else if(int p = getPriority(c) > 1)
			{
				while(!sym.empty() && p < getPriority(sym.top().front()))
				{
					suffix.push(sym.top());
					sym.pop();
				}
				sym.push(temp.front());
			}
			else if(c == ')')
			{
				while(!sym.empty() && sym.top().front() != '(')
				{
					suffix.push(sym.top());
					sym.pop();
				}
			}
			else if(c == '(')
				sym.push(temp.front());
			temp.pop();
		}
		while(!sym.empty())
		{
			char c = sym.top().front();
			if(c != '(' && c != ')')
				suffix.push(sym.top());
			sym.pop();
		}
		while(!suffix.empty())
		{
			sym.push(std::move(suffix.top()));
			suffix.pop();
		}
		return std::move(sym);
	}

	int getPriority(char c)
	{
		if(c == '*' || c == '/' || c == '%') return 3;
		else if(c == '+' || c == '-') return 2;
		else return 1;
	}

	std::queue<std::string> sub(const std::string &rep)
	{
		std::queue<std::string> s;
		std::size_t index = 0, old = 0; 
		while((index = rep.find_first_of("+-*/%()", index)) != std::string::npos)
		{
			if(index != old)
				s.emplace(rep.substr(old, index - old));
			s.emplace();
			s.back().push_back(rep[index]);
			old = ++index;
		}
		s.emplace(rep.substr(old, index - old));
		return std::move(s);
	}

	void deleteSpace(std::string &s)
	{
		for(std::size_t i; (i = s.find(" ")) != std::string::npos; s.erase(i, 1));
	}
};

int main()
{
	Math math;
	std::string line; 
	while(std::cout << "input: " && std::getline(std::cin, line))
		std::cout << "output:" << math.operation(line) << std::endl;
}
