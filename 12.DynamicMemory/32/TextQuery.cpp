#include "TextQuery.h"

TextQuery::TextQuery() : lineText(new StrBlob) {}
TextQuery::TextQuery(std::istream &in) : lineText(new StrBlob)
{
	for(std::string line; std::getline(in, line); lineText->push_back(line))
	{
		std::istringstream inWord(line);
		std::for_each(std::istream_iterator<std::string>(inWord), std::istream_iterator<std::string>(), std::bind(insertLineNo, _1, std::ref(*this)));
	}
}

QueryResult TextQuery::query(const std::string &word) const
{
	auto iter = wordLine.find(word);
	if(iter != wordLine.end())
		return { lineText, *iter };
	return { lineText, std::make_pair(word, std::shared_ptr<std::set<line_type>>()) };
}

void TextQuery::retext(std::istream &in)
{
	lineText->clear();
	wordLine.clear();
	for(std::string line; std::getline(in, line); lineText->push_back(line))
	{
		std::istringstream inWord(line);
		std::for_each(std::istream_iterator<std::string>(inWord), std::istream_iterator<std::string>(), std::bind(insertLineNo, _1, std::ref(*this)));
	}
	lineText->shrink_to_fit();
}

void TextQuery::insertLineNo(std::string word, TextQuery &result)
{
	word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
	auto &linep = result.wordLine[word];
	if(!linep) linep.reset(new std::set<line_type>);
	linep->insert(result.lineText->size());
}
