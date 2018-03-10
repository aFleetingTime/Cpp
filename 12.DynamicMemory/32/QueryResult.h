#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <string>
#include "StrBlob.h"

class QueryResult;

std::ostream& operator<<(std::ostream &, const QueryResult &);

class QueryResult
{
	friend std::ostream& operator<<(std::ostream &, const QueryResult &);

public:
	using line_type = std::vector<std::string>::size_type;
	using WordLine_Type = std::pair<std::string, std::shared_ptr<std::set<line_type>>>;
	using text_ptr = std::shared_ptr<StrBlob>;

	QueryResult() = default;
	QueryResult(const text_ptr &, const WordLine_Type &);

	std::shared_ptr<StrBlob> getText();
	std::set<QueryResult::line_type>::iterator begin();
	std::set<QueryResult::line_type>::iterator end();

private:
	text_ptr lineText;
	WordLine_Type wordLine;
};
