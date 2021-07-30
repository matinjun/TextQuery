#pragma once
#include <string>
#include <memory>
#include <set>
#include <iostream>
#include <vector>
class TextResult
{
	friend std::ostream& print(std::ostream& os, const TextResult& textResult); 

public:
	TextResult(
		std::pair<const std::string, std::shared_ptr<std::set<int>>> group, 
		std::shared_ptr<std::vector<std::vector<std::string>>>ct): 
		word(group.first), lines(group.second), content(ct) {}
private:
	std::string word;
	std::shared_ptr<std::set<int>> lines;
	std::shared_ptr<std::vector<std::vector<std::string>>> content;
};

std::ostream& print(std::ostream& os, const TextResult& textResult);
