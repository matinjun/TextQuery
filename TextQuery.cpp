#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream& infile)
{
	if (!infile.is_open()) {
		throw std::runtime_error("input file not exists");
	}
	
	/*首行从第一行开始，第0行标记为空*/
	content = std::make_shared<std::vector<std::vector<std::string>>>(1);
	std::vector<char> line(500);
	
	for (; !infile.eof();) {
		infile.getline(line.data(), line.size());
		std::vector<std::string> wrds;
		std::stringstream instr(line.data());
		for (; !instr.eof();) {
			std::string word;
			instr >> word;
			wrds.push_back(word);
		}
		this->content->push_back(wrds);
	}
}

TextResult TextQuery::query(const std::string& word) 
{
	auto it = this->dictionary.find(word);
	if ((it) != this->dictionary.end()) {
		return TextResult(*it, content);
	}
	
	std::set<int> lines;
	decltype(this->content->size()) i = 0;
	for (; i < this->content->size(); ++i) {

		for (const auto& wrd : (*this->content)[i]) {
			if (wrd == word) {
				lines.insert(i);
				break;
			}
		}
	}
	this->dictionary.insert(std::make_pair(word, std::make_shared<std::set<int>>(lines)));

	it = dictionary.find(word);
	return TextResult(*it, content);
}
