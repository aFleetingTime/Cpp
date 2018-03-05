#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	vector<int> ivec = { 1, 2, 3, 4, 5, 6, 7, 8 };
	stack<int, vector<int>> istk(ivec);
	while(!istk.empty())
		cout << istk.top() << ' ', istk.pop();
	cout << endl;
}
