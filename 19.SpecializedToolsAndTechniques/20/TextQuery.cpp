#include "TextQuery.h"
#include "QueryResult.h"

namespace Chapter10 {
TextQuery::TextQuery() : lineText(new StrVec) {}
TextQuery::TextQuery(std::istream &in) : lineText(new StrVec)
{
	for(std::string line; std::getline(in, line); lineText->push_back(line))
	{
		std::istringstream inWord(line);
		std::for_each(std::istream_iterator<std::string>(inWord), std::istream_iterator<std::string>(), std::bind(insertLineNo, std::placeholders::_1, std::ref(*this)));
	}
}

TextQuery::QueryResult TextQuery::query(const std::string &word) const
{
	auto iter = wordLine.find(word);
	if(iter != wordLine.end())
		return { lineText, *iter };
	return { lineText, { word, std::shared_ptr<std::set<line_type>>(new std::set<line_type>) } };
}

void TextQuery::retext(std::istream &in)
{
	lineText->clear();
	wordLine.clear();
	for(std::string line; std::getline(in, line); lineText->push_back(line))
	{
		std::istringstream inWord(line);
		std::for_each(std::istream_iterator<std::string>(inWord), std::istream_iterator<std::string>(), std::bind(insertLineNo, std::placeholders::_1, std::ref(*this)));
	}
}

void TextQuery::insertLineNo(std::string word, TextQuery &result)
{
	word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
	auto &linep = result.wordLine[word];
	if(!linep) linep.reset(new std::set<line_type>);
	linep->insert(result.lineText->size());
}
}
