#pragma once
#include <map>
#include <set>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <functional>
#include <sstream>
#include "QueryResult.h"
#include "StrBlob.h"

using namespace std::placeholders;

class TextQuery
{
public:
	using line_type = std::vector<std::string>::size_type;
	using text_ptr = std::shared_ptr<StrBlob>;
	using word_type = std::map<std::string, std::shared_ptr<std::set<line_type>>>;

	TextQuery();
	TextQuery(std::istream &);
	
	void retext(std::istream &);
	QueryResult query(const std::string &) const;
private:
	text_ptr lineText;
	word_type wordLine;
	static void insertLineNo(std::string, TextQuery &);
};
