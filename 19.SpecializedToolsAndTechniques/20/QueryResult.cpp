#include "QueryResult.h"

namespace Chapter10 {
std::ostream& operator<<(std::ostream &out, const TextQuery::QueryResult &result)
{
	if(!result.wordLine.second)
	{
		std::cout << "文本不包含单词: " << result.wordLine.first << '\n';
		return out;
	}
	out << "字符串: " << result.wordLine.first << "	包含该字符串的行数: " << result.wordLine.second->size() << std::endl;
	for(const auto &lineNo : *result.wordLine.second)
		out << "\t(line " << lineNo + 1 << ") " << result.lineText->at(lineNo) << '\n';
	return out;
}

TextQuery::QueryResult::QueryResult(const text_ptr &text, const WordLine_Type &pair) : lineText(text), wordLine(pair) {}

std::set<TextQuery::line_type>::iterator TextQuery::QueryResult::begin()
{
	return wordLine.second->begin();
}

std::set<TextQuery::line_type>::iterator TextQuery::QueryResult::end()
{
	return wordLine.second->end();
}

TextQuery::QueryResult::text_ptr TextQuery::QueryResult::getText()
{
	return lineText;
}
}
