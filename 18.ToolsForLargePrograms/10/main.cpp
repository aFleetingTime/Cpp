#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <unordered_set>
#include "Sales_item.h"

int main()
{
	Sales_item left("A", 1, 1), right("B", 2, 2);
#ifdef TRY
	try {
#endif
		left += right;
#ifdef TRY
	} catch(isbn_mismatch &e) {
		std::cout << e.what() << std::endl;
	}
#endif
}
