#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <memory>

#include "TextResult.h"

class TextQuery
{
public:
	TextQuery(std::ifstream& infile);
public:
	TextResult query(const std::string &word);
	
private:
	std::shared_ptr < std::vector<std::vector<std::string>>> content;
	std::map<std::string, std::shared_ptr<std::set<int>>> dictionary;

};

